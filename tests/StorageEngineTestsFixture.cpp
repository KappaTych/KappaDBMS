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

TEST_F(StorageEngineTestsFixture, TEST_CREATE_METADATA)
{
  ASSERT_TRUE(storage.HasMetaData(tableName));
}

TEST_F(StorageEngineTestsFixture, TEST_INSERT_AND_SELECT)
{
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

  // SELECT *
  std::cout << "SELECT ALL" << std::endl;
  auto dataAll1 = storage.Read(meta, size);

  int i = 0;
  for (auto& x : dataAll1) {
    ASSERT_EQ(x.Get<int32_t>(), first_expected[i]);
    ASSERT_EQ(x.Get<std::string>(), second_expected[i]);
    ASSERT_EQ(x.Get<int32_t>(), third_expected[i++]);
    x.Reset();
  }
}