//
// Created by truefinch on 16.11.18.
//

#include <gtest/gtest.h>
#include <ClassToTestCodeCoverage.h>
#include <storage/StorageEngine.hpp>

namespace
{
class StorageEngineTestsFixture : public ::testing::Test
{
public:

  ClassToTestCodeCoverage obj;
  se::StorageEngine& storage = se::StorageEngine::Instance();
  std::string tableName = "some_table";
  int size;

  StorageEngineTestsFixture()
  {}

  virtual void SetUp()
  {
    // Supported types info
    std::unordered_map<std::string, se::size_t> mapping = {{"INTEGER", sizeof(int32_t)},
                                                           {"TEXT",    se::STRING_LEN},};
    if (!storage.HasMetaData(tableName)) {
      // CREATE TABLE
      auto& meta = storage.CreateData(tableName);
      meta.Add("id", "INTEGER");
      meta.Add("name", "TEXT");
      meta.Add("count", "INTEGER");

      se::size_t size = 0;
      for (auto& row : meta.data().at("public").items()) {
        size += mapping[row.value()];
      }
      meta.Add("size", size, "private");

      storage.Flush();
    }
  }

  static void SetUpTestCase()
  {}

  virtual void TearDown()
  {
    // DROP TABLE
    storage.RemoveData(tableName);
  };

  static void TearDownTestCase()
  {};
};
}

TEST_F(StorageEngineTestsFixture, TEST1)
{
  ASSERT_TRUE(storage.HasMetaData(tableName));
  // INSERT INTO
  auto& meta = storage.GetMetaData(tableName);
  se::size_t size = meta.data()["private"]["size"];
  se::RawData raw(size);

  int32_t first_expected[3] = {1, 2, 3};
  std::string second_expected[3] = {"First Line", "Second Line!", "Third Line!"};
  int32_t third_expected[3] = {64, 16, 16};

  raw.Fill<int32_t>(first_expected[0]).Fill<std::string>(second_expected[0]).Fill<int32_t>(third_expected[0]);
  storage.Write(meta, raw.data(), raw.capacity());

  raw.FullReset().Fill<int32_t>(first_expected[1]).Fill<std::string>(second_expected[1]).Fill<int32_t>(third_expected[1]);
  storage.Write(meta, raw.data(), raw.capacity());

  raw.FullReset().Fill<int32_t>(first_expected[2]).Fill<std::string>(second_expected[2]).Fill<int32_t>(third_expected[2]);
  storage.Write(meta, raw.data(), raw.capacity());

  // SELECT ALL
  auto dataAll1 = storage.Read(meta, size);
  int i = 0;
  for (auto& x : dataAll1) {
    ASSERT_EQ(x.Get<int32_t>(), first_expected[i]);
    ASSERT_EQ(x.Get<std::string>(), second_expected[i]);
    ASSERT_EQ(x.Get<int32_t>(), third_expected[i++]);
    x.Reset();
  }

  meta = storage.GetMetaData(tableName);
  // SELECT * WHERE id = 2
  int expected_id = 2;
  auto dataWhere = storage.Read(meta, size, [](const se::RawData& raw) {
    return (raw.Get<int>() == 2);
  });

  ASSERT_EQ(dataWhere.size(), 1);

  auto& result = *dataWhere.begin();
  ASSERT_EQ(result.Get<int32_t>(), expected_id);
  result.Reset();

  // UPDATE WHERE id = 1
  expected_id = 1;
  const std::string expected_line = "Updated first line!";
  storage.Update(meta, size, [](se::RawData&& raw) {
    if (raw.Get<int>() == 1) {
      raw.Fill<std::string>("Updated first line!", true);
      return true;
    }
    return false;
  });

  dataWhere = storage.Read(meta, size, [](const se::RawData& raw) {
    return (raw.Get<int>() == 1);
  });

  ASSERT_EQ(dataWhere.size(), 1);

  result = *dataWhere.begin();
  ASSERT_EQ(result.Get<int32_t>(), expected_id);
  ASSERT_EQ(result.Get<std::string>(), expected_line);
  result.Reset();

  // DELETE WHERE count < 64
  int border = 64;
  storage.Delete(meta, size, [](const se::RawData& raw) {
    return (raw.Skip<int>().Skip<std::string>(se::STRING_LEN).Get<int>() < 64);
  });

  dataAll1 = storage.Read(meta, size);
  for (auto& x : dataAll1) {
    x.Get<int32_t>();
    x.Get<std::string>();
    ASSERT_GE(x.Get<int32_t>(), border);
    x.Reset();
  }

}