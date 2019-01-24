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
  bool bvalA, bvalB;
  int32_t ivalA, ivalB;
  double dvalA, dvalB;

  auto typeA = GetColumns().back().second;
  auto typeB = operand.GetColumns().back().second;

  switch (typeA) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ivalA);
      dvalA = ivalA;
      bvalA = ivalA;
      break;

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dvalA);
      ivalA = dvalA;
      bvalA = dvalA;
      break;

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bvalA);
      ivalA = bvalA;
      dvalA = bvalA;
      break;

    case cmd::LiteralType::TEXT:
      return (GetRecords().back().back()->ToString() == operand.GetRecords().back().back()->ToString());
  }

  switch (typeB) {
    case cmd::LiteralType::INTEGER:
      operand.GetRecords().back().back()->Value(&ivalB);
      return (ivalA == ivalB);

    case cmd::LiteralType::DOUBLE:
      operand.GetRecords().back().back()->Value(&dvalB);
      return (dvalA == dvalB);

    case cmd::LiteralType::BOOL:
      operand.GetRecords().back().back()->Value(&bvalB);
      return (bvalA == bvalB);

    case cmd::LiteralType::TEXT:
      return (GetRecords().back().back()->ToString() == operand.GetRecords().back().back()->ToString());
  }
  return false;
}

bool Table::operator>(const Table& operand) const
{
  bool bvalA, bvalB;
  int32_t ivalA, ivalB;
  double dvalA, dvalB;

  auto typeA = GetColumns().back().second;
  auto typeB = operand.GetColumns().back().second;

  switch (typeA) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ivalA);
      dvalA = ivalA;
      bvalA = ivalA;
      break;

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dvalA);
      ivalA = dvalA;
      bvalA = dvalA;
      break;

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bvalA);
      ivalA = bvalA;
      dvalA = bvalA;
      break;

    case cmd::LiteralType::TEXT:
      return (GetRecords().back().back()->ToString() > operand.GetRecords().back().back()->ToString());
  }

  switch (typeB) {
    case cmd::LiteralType::INTEGER:
      operand.GetRecords().back().back()->Value(&ivalB);
      return (ivalA > ivalB);

    case cmd::LiteralType::DOUBLE:
      operand.GetRecords().back().back()->Value(&dvalB);
      return (dvalA > dvalB);

    case cmd::LiteralType::BOOL:
      operand.GetRecords().back().back()->Value(&bvalB);
      return (bvalA > bvalB);

    case cmd::LiteralType::TEXT:
      return (GetRecords().back().back()->ToString() > operand.GetRecords().back().back()->ToString());
  }
  return false;
}

bool Table::operator!=(const Table& operand) const
{
  return !(*this == operand);
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
      break;

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dval);
      bval = dval;
      break;

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bval);
      break;

    case cmd::LiteralType::TEXT:
      bval = !GetRecords().back().back()->ToString().empty();
      break;
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
      break;

    case cmd::LiteralType::DOUBLE:
      operand.GetRecords().back().back()->Value(&dvalB);
      bvalB = dvalB;
      break;

    case cmd::LiteralType::BOOL:
      operand.GetRecords().back().back()->Value(&bvalB);
      break;

    case cmd::LiteralType::TEXT:
      bvalB = !operand.GetRecords().back().back()->ToString().empty();
      break;
  }

  switch (GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ivalA);
      bvalA = ivalA;
      break;

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dvalA);
      bvalA = dvalA;
      break;

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bvalA);
      break;

    case cmd::LiteralType::TEXT:
      bvalA = !GetRecords().back().back()->ToString().empty();
      break;
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
      break;

    case cmd::LiteralType::DOUBLE:
      operand.GetRecords().back().back()->Value(&dvalB);
      bvalB = dvalB;
      break;

    case cmd::LiteralType::BOOL:
      operand.GetRecords().back().back()->Value(&bvalB);
      break;

    case cmd::LiteralType::TEXT:
      bvalB = !operand.GetRecords().back().back()->ToString().empty();
      break;
  }

  switch (GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ivalA);
      bvalA = ivalA;
      break;

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dvalA);
      bvalA = dvalA;
      break;

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bvalA);
      break;

    case cmd::LiteralType::TEXT:
      bvalA = !GetRecords().back().back()->ToString().empty();
      break;
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
      break;

    case cmd::LiteralType::DOUBLE:
      operand.GetRecords().back().back()->Value(&dvalB);
      bvalB = dvalB;
      break;

    case cmd::LiteralType::BOOL:
      operand.GetRecords().back().back()->Value(&bvalB);
      break;

    case cmd::LiteralType::TEXT:
      bvalB = !operand.GetRecords().back().back()->ToString().empty();
      break;
  }

  switch (GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ivalA);
      bvalA = ivalA;
      break;

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dvalA);
      bvalA = dvalA;
      break;

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bvalA);
      break;

    case cmd::LiteralType::TEXT:
      bvalA = !GetRecords().back().back()->ToString().empty();
      break;
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
      return Table({GetColumns().back()}, {{std::make_shared<IntField>(ivalA + ivalB)}});

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dvalA);
      return Table({GetColumns().back()}, {{std::make_shared<DoubleField>(dvalA + dvalB)}});

    case cmd::LiteralType::TEXT:
      return Table({GetColumns().back()}, {{std::make_shared<TextField>(
          GetRecords().back().back()->ToString() + operand.GetRecords().back().back()->ToString()
        )}});

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bvalA);
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
      return Table({GetColumns().back()}, {{std::make_shared<IntField>(ivalA * ivalB)}});

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dvalA);
      return Table({GetColumns().back()}, {{std::make_shared<DoubleField>(dvalA * dvalB)}});

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bvalA);
      return Table({GetColumns().back()}, {{std::make_shared<BoolField>(bvalA && bvalB)}});
  }
  return *this;
}

Table Table::operator/(const Table& operand) const
{
  int32_t ivalA = 1;
  int32_t ivalB = 1;
  double dvalA, dvalB;
  bool bvalA, bvalB;

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

    case cmd::LiteralType::TEXT:
      ivalB = operand.GetRecords().back().back()->ToString().size();
      dvalB = ivalB;
      bvalB = ivalB;
      break;
  }

  if (ivalB == 0 || bvalB == false) {
    throw std::domain_error("DriverError: division by zero");
  }

  switch (GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ivalA);
      return Table({GetColumns().back()}, {{std::make_shared<IntField>(ivalA / ivalB)}});

    case cmd::LiteralType::DOUBLE:
      GetRecords().back().back()->Value(&dvalA);
      return Table({GetColumns().back()}, {{std::make_shared<DoubleField>(dvalA / dvalB)}});

    case cmd::LiteralType::BOOL:
      GetRecords().back().back()->Value(&bvalA);
      return Table({GetColumns().back()}, {{std::make_shared<DoubleField>(bvalA / bvalB)}});
  }
  return *this;
}

Table Table::operator%(const Table& operand) const
{
  int32_t ivalA = 1;
  int32_t ivalB = 1;
  double dvalA, dvalB;
  bool bvalA, bvalB;

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

    case cmd::LiteralType::TEXT:
      ivalB = operand.GetRecords().back().back()->ToString().size();
      dvalB = ivalB;
      bvalB = ivalB;
      break;
  }

  if (ivalB == 0 || bvalB == false) {
    throw std::domain_error("DriverError: division by zero");
  }

  switch (GetColumns().back().second) {
    case cmd::LiteralType::INTEGER:
      GetRecords().back().back()->Value(&ivalA);
      return Table({GetColumns().back()}, {{std::make_shared<IntField>(ivalA % ivalB)}});
  }
  return *this;
}


} //namespace sql