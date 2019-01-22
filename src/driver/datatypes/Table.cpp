#include "Table.hpp"
#include <vector>

using json = nlohmann::json;

namespace sql {

std::string to_string(cmd::LiteralType type)
{
  switch (type) {
    case cmd::LiteralType::INTEGER: {
      return "INTEGER";
    }
    case cmd::LiteralType::DOUBLE: {
      return "DOUBLE";
    }
    case cmd::LiteralType::TEXT: {
      return "TEXT";
    }
    case cmd::LiteralType::BOOL: {
      return "BOOL";
    }
    default: {
      return "UNKNOWN";
    }
  }
}

void to_json(json& j, const Table& t)
{
  j["name"] = t.name_.name_;
  j["database"] = t.name_.database_;
  j["schema"] = t.name_.schema_;

  std::vector<json> columns;
  for (auto& column : t.GetColumns()) {
    json c;
    c["name"] = column.first;
    c["type"] = to_string(column.second);
    columns.push_back(c);
  }
  j["columns"] = json(columns);

  std::vector<json> records;
  for (auto &record: t.GetRecords()) {
    std::vector<std::string> r;
    for (auto& field : record) {
      r.push_back(field->ToString());
    }
    records.push_back(r);
  }
  j["records"] = records;
}

void from_json(const json& j, Table& t)
{
  j.at("name").get_to(t.name_.name_);
  j.at("database").get_to(t.name_.database_);
  j.at("schema").get_to(t.name_.schema_);
}

void Table::AddColumn(Table::Column column)
{
  columns_.push_back(column);
}

void Table::InsertRecord(Table::Record record)
{
  records_.push_back(record);
}

void Table::DeleteRecord(int index)
{
  auto it = records_.begin();
  while (index > 0) {
    --index;
    ++it;
  }
  records_.erase(it);
}

std::string Table::ToString() const
{
  std::string result = "CREATE TABLE " + name_.ToString() + " (";
  // for (auto &col : columns_) {
  //   result += col.name_ + " " + sql::to_string(col.type_) + ", ";
  // }

  // result.pop_back();
  // result.pop_back();
  // result += ");";
  return result;
}

// Shit:
bool Table::operator==(const Table& operand) const
{
  auto type = GetColumns().back().second;
  if (type != operand.GetColumns().back().second) {
    return false;
  }

  bool bvalA, bvalB;
  int32_t ivalA, ivalB;
  double dvalA, dvalB;

  switch (type) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ivalA);
      operand.GetRecords().back().back()->Value(&ivalB);
      return (ivalA == ivalB);

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dvalA);
      operand.GetRecords().back().back()->Value(&dvalB);
      return (dvalA == dvalB);

    case cmd::LiteralType::TEXT:
      return (GetRecords().back().back()->ToString() == operand.GetRecords().back().back()->ToString());

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bvalA);
      operand.GetRecords().back().back()->Value(&bvalB);
      return (bvalA == bvalB);
  }
  return false;
}

bool Table::operator!=(const Table& operand) const
{
  return !(*this == operand);
}

bool Table::operator>(const Table& operand) const
{
  auto type = GetColumns().back().second;
  if (type != operand.GetColumns().back().second) {
    return false;
  }

  bool bvalA, bvalB;
  int32_t ivalA, ivalB;
  double dvalA, dvalB;

  switch (type) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ivalA);
      operand.GetRecords().back().back()->Value(&ivalB);
      return (ivalA > ivalB);

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dvalA);
      operand.GetRecords().back().back()->Value(&dvalB);
      return (dvalA > dvalB);

    case cmd::LiteralType::TEXT:
      return (GetRecords().back().back()->ToString() > operand.GetRecords().back().back()->ToString());

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bvalA);
      operand.GetRecords().back().back()->Value(&bvalB);
      return (bvalA > bvalB);
  }
  return false;
}

bool Table::operator<(const Table& operand) const
{
  return !(*this > operand) && (*this != operand);
}

bool Table::operator>=(const Table& operand) const
{
  return !(*this < operand);
}

bool Table::operator<=(const Table& operand) const
{
  return !(*this > operand);
}

bool Table::operator!() const
{
  bool bval = true;
  int32_t ival;
  double dval;

  switch (GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ival);
      bval = ival;

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dval);
      bval = dval;

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bval);

    case cmd::LiteralType::TEXT:
      bval = !GetRecords().back().back()->ToString().empty();
  }
  return !bval;
}

bool Table::operator^(const Table& operand) const
{
  bool bvalA, bvalB;
  int32_t ivalA, ivalB;
  double dvalA, dvalB;

  switch (operand.GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      operand.GetRecords().back().back()->Value(&ivalB);
      bvalB = ivalB;

    case cmd::LiteralType::DOUBLE:
      operand.GetRecords().back().back()->Value(&dvalB);
      bvalB = dvalB;

    case cmd::LiteralType::BOOL:
      operand.GetRecords().back().back()->Value(&bvalB);

    case cmd::LiteralType::TEXT:
      bvalB = !operand.GetRecords().back().back()->ToString().empty();
  }

  switch (GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ivalA);
      bvalA = ivalA;

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dvalA);
      bvalA = dvalA;

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bvalA);

    case cmd::LiteralType::TEXT:
      bvalA = !GetRecords().back().back()->ToString().empty();
  }

  return bvalA ^ bvalB;
}

bool Table::operator&&(const Table& operand) const
{
  bool bvalA, bvalB;
  int32_t ivalA, ivalB;
  double dvalA, dvalB;

  switch (operand.GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      operand.GetRecords().back().back()->Value(&ivalB);
      bvalB = ivalB;

    case cmd::LiteralType::DOUBLE:
      operand.GetRecords().back().back()->Value(&dvalB);
      bvalB = dvalB;

    case cmd::LiteralType::BOOL:
      operand.GetRecords().back().back()->Value(&bvalB);

    case cmd::LiteralType::TEXT:
      bvalB = !operand.GetRecords().back().back()->ToString().empty();
  }

  switch (GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ivalA);
      bvalA = ivalA;

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dvalA);
      bvalA = dvalA;

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bvalA);

    case cmd::LiteralType::TEXT:
      bvalA = !GetRecords().back().back()->ToString().empty();
  }

  return bvalA && bvalB;
}

bool Table::operator||(const Table& operand) const
{
  bool bvalA, bvalB;
  int32_t ivalA, ivalB;
  double dvalA, dvalB;

  switch (operand.GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      operand.GetRecords().back().back()->Value(&ivalB);
      bvalB = ivalB;

    case cmd::LiteralType::DOUBLE:
      operand.GetRecords().back().back()->Value(&dvalB);
      bvalB = dvalB;

    case cmd::LiteralType::BOOL:
      operand.GetRecords().back().back()->Value(&bvalB);

    case cmd::LiteralType::TEXT:
      bvalB = !operand.GetRecords().back().back()->ToString().empty();
  }

  switch (GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ivalA);
      bvalA = ivalA;

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dvalA);
      bvalA = dvalA;

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bvalA);

    case cmd::LiteralType::TEXT:
      bvalA = !GetRecords().back().back()->ToString().empty();
  }

  return bvalA || bvalB;
}

Table Table::operator+() const
{
  return *this;
}

Table Table::operator-() const
{
  int32_t ival;
  double dval;

  switch (GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ival);
      return Table({GetColumns().back()}, {{std::make_shared<IntField>(-ival)}});

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dval);
      return Table({GetColumns().back()}, {{std::make_shared<DoubleField>(-dval)}});
  }
  return *this;
}

Table Table::operator+(const Table& operand) const
{
  bool bvalA, bvalB;
  int32_t ivalA, ivalB;
  double dvalA, dvalB;

  switch (operand.GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      operand.GetRecords().back().back()->Value(&ivalB);
      dvalB = ivalB;
      bvalB = ivalB;
      break;

    case cmd::LiteralType::DOUBLE:
      operand.GetRecords().back().back()->Value(&dvalB);
      ivalB = dvalB;
      bvalB = dvalB;
      break;

    case cmd::LiteralType::BOOL:
      operand.GetRecords().back().back()->Value(&bvalB);
      ivalB = bvalB;
      dvalB = bvalB;
      break;
  }

  switch (GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ivalA);
      operand.GetRecords().back().back()->Value(&ivalB);
      return Table({GetColumns().back()}, {{std::make_shared<IntField>(ivalA + ivalB)}});

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dvalA);
      operand.GetRecords().back().back()->Value(&dvalB);
      return Table({GetColumns().back()}, {{std::make_shared<DoubleField>(dvalA + dvalB)}});

    case cmd::LiteralType::TEXT:
      return Table({GetColumns().back()}, {{std::make_shared<TextField>(
          GetRecords().back().back()->ToString() + operand.GetRecords().back().back()->ToString()
        )}});

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bvalA);
      operand.GetRecords().back().back()->Value(&bvalB);
      return Table({GetColumns().back()}, {{std::make_shared<BoolField>(bvalA || bvalB)}});
  }
  return *this;
}

Table Table::operator-(const Table& operand) const
{
  return (*this + (-operand));
}

Table Table::operator*(const Table& operand) const
{
  bool bvalA, bvalB;
  int32_t ivalA, ivalB;
  double dvalA, dvalB;

  switch (operand.GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      operand.GetRecords().back().back()->Value(&ivalB);
      dvalB = ivalB;
      bvalB = ivalB;
      break;

    case cmd::LiteralType::DOUBLE:
      operand.GetRecords().back().back()->Value(&dvalB);
      ivalB = dvalB;
      bvalB = dvalB;
      break;

    case cmd::LiteralType::BOOL:
      operand.GetRecords().back().back()->Value(&bvalB);
      ivalB = bvalB;
      dvalB = bvalB;
      break;
  }

  switch (GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ivalA);
      operand.GetRecords().back().back()->Value(&ivalB);
      return Table({GetColumns().back()}, {{std::make_shared<IntField>(ivalA * ivalB)}});

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dvalA);
      operand.GetRecords().back().back()->Value(&dvalB);
      return Table({GetColumns().back()}, {{std::make_shared<DoubleField>(dvalA * dvalB)}});

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bvalA);
      operand.GetRecords().back().back()->Value(&bvalB);
      return Table({GetColumns().back()}, {{std::make_shared<BoolField>(bvalA && bvalB)}});
  }
  return *this;
}

Table Table::operator/(const Table& operand) const
{
  int32_t ivalA, ivalB;
  double dvalA, dvalB;

  switch (operand.GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      operand.GetRecords().back().back()->Value(&ivalB);
      dvalB = ivalB;
      break;

    case cmd::LiteralType::DOUBLE:
      operand.GetRecords().back().back()->Value(&dvalB);
      ivalB = dvalB;
      break;
  }

  switch (GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ivalA);
      operand.GetRecords().back().back()->Value(&ivalB);
      return Table({GetColumns().back()}, {{std::make_shared<IntField>(ivalA / ivalB)}});

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dvalA);
      operand.GetRecords().back().back()->Value(&dvalB);
      return Table({GetColumns().back()}, {{std::make_shared<DoubleField>(dvalA / dvalB)}});
  }
  return *this;
}

Table Table::operator%(const Table& operand) const
{
  int32_t ivalA, ivalB;

  switch (GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ivalA);
      operand.GetRecords().back().back()->Value(&ivalB);
      return Table({GetColumns().back()}, {{std::make_shared<IntField>(ivalA % ivalB)}});
  }
  return *this;
}


} //namespace sql