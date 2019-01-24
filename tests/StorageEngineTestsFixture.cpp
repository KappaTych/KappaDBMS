//
// Created by truefinch on 16.11.18.
//

#include <gtest/gtest.h>
#include <storage/StorageEngine.hpp>

namespace
{

class StorageEngineTestsFixture : public ::testing::Test
{
public:
  using types_map = std::unordered_map<std::string, se::size_t>;  

  static std::string tableName;
  se::StorageEngine& storage = se::StorageEngine::Instance();
  types_map mapping = {
      { "INTEGER", sizeof(int32_t) },
      { "DOUBLE",  sizeof(double) },
      { "TEXT",    se::STRING_LEN },
    };

  virtual void SetUp() { }

  virtual void TearDown() { }

  static void SetUpTestCase()
  {
    se::StorageEngine& storage = se::StorageEngine::Instance();
    if (storage.HasMetaData(tableName)) {
      storage.RemoveData(tableName);
    }
  }

  static void TearDownTestCase()
  {
    se::StorageEngine& storage = se::StorageEngine::Instance();
    if (storage.HasMetaData(tableName)) {
      storage.RemoveData(tableName);
    }
  }
};
std::string StorageEngineTestsFixture::tableName = "some_table";

} // namespace

TEST_F(StorageEngineTestsFixture, METADATA_TEST)
{
  ASSERT_FALSE(storage.HasMetaData(tableName));

  auto& meta = storage.CreateData(tableName);
  meta.Add("id", "INTEGER");
  meta.Add("name", "TEXT");
  meta.Add("count", "INTEGER");
  meta.Add("price", "DOUBLE");

  se::size_t size = 0;
  se::size_t expected_size = 4 + se::STRING_LEN + 4 + 8;
  for (auto& row : meta.data().at("public").items()) {
    size += mapping[row.value()];
  }
  ASSERT_EQ(expected_size, size);

  meta.Add("size", size, "private");

  storage.Flush();

  ASSERT_TRUE(storage.HasMetaData(tableName));
}

TEST_F(StorageEngineTestsFixture, WRITE_READ_TEST)
{
  ASSERT_TRUE(storage.HasMetaData(tableName));
  auto& meta = storage.GetMetaData(tableName);
  se::size_t size = meta.data()["private"]["size"];

  // INSERT INTO
  int32_t expected_id[3] = {1, 2, 3};
  std::string expected_name[3] = { "First Line", "Second Line!", "Third Line!" };
  int32_t expected_count[3] = {64, 16, 322};
  double expected_price[3] = {12.3, 33.33335, 1e-4};

  se::RawData raw(size);
  for (auto i = 0; i < 3; ++i) {
    raw.FullReset()
       .Fill<int32_t>(expected_id[i])
       .Fill<std::string>(expected_name[i])
       .Fill<int32_t>(expected_count[i])
       .Fill<double>(expected_price[i]);
    storage.Write(meta, raw.data(), raw.capacity());
  }

  // SELECT ALL
  auto dataAll = storage.Read(meta, size);
  int i = 0;
  for (auto& x : dataAll) {
    ASSERT_EQ(x.Get<int32_t>(), expected_id[i]);
    ASSERT_EQ(x.Get<std::string>(), expected_name[i]);
    ASSERT_EQ(x.Get<int32_t>(), expected_count[i]);
    ASSERT_EQ(x.Get<double>(), expected_price[i++]);
  }

}

TEST_F(StorageEngineTestsFixture, READ_LAMBDA)
{
  ASSERT_TRUE(storage.HasMetaData(tableName));
  auto& meta = storage.GetMetaData(tableName);
  se::size_t size = meta.data()["private"]["size"];

  // SELECT * WHERE id = 2
  const int32_t expected_id = 2;

  auto dataWhere = storage.Read(meta, size, [&](const se::RawData& raw) {
    return (raw.Get<int32_t>() == expected_id);
  });

  ASSERT_EQ(dataWhere.size(), 1);
  ASSERT_EQ(dataWhere.begin()->Get<int32_t>(), expected_id);
}

TEST_F(StorageEngineTestsFixture, UPDATE_LAMBDA)
{
  ASSERT_TRUE(storage.HasMetaData(tableName));
  auto& meta = storage.GetMetaData(tableName);
  se::size_t size = meta.data()["private"]["size"];

  // UPDATE WHERE id = 1
  const int32_t expected_id = 1;
  const std::string expected_line = "Updated first line!";

  storage.Update(meta, size, [&](se::RawData&& raw) {
    if (raw.Get<int32_t>() == expected_id) {
      raw.Fill<std::string>(expected_line, true);
      return true;
    }
    return false;
  });

  auto dataWhere = storage.Read(meta, size, [&](const se::RawData& raw) {
    return (raw.Get<int32_t>() == expected_id);
  });

  ASSERT_EQ(dataWhere.size(), 1);

  auto result = dataWhere.begin();
  ASSERT_EQ(result->Get<int32_t>(), expected_id);
  ASSERT_EQ(result->Get<std::string>(), expected_line);
}

TEST_F(StorageEngineTestsFixture, DELETE_LAMBDA)
{
  ASSERT_TRUE(storage.HasMetaData(tableName));
  auto& meta = storage.GetMetaData(tableName);
  se::size_t size = meta.data()["private"]["size"];

  // DELETE WHERE count < 64
  int32_t border = 64;
  storage.Delete(meta, size, [&](const se::RawData& raw) {
    return (raw.Skip<int>().Skip<std::string>(se::STRING_LEN).Get<int>() < border);
  });

  auto dataAll = storage.Read(meta, size);
  for (auto& x : dataAll) {
    x.Skip<int32_t>().Skip<std::string>();
    ASSERT_GE(x.Get<int32_t>(), border);
  }

}
