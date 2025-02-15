// Copyright 2021 Nikita Boldaev <nikbold-02@yandex.ru>

#include <gtest/gtest.h>
#include "student.hpp"

TEST(ParserTest, rightFile) {
  auto students = parse_json_file(JSON_PATH"exmpl.json");
  std::stringstream parsed;
  Print(students, parsed);
  std::string compare =
      R"(| name          | group  | avg      | debt    |
|---------------|--------|----------|---------|
| Ivanov Petr   | 1      | 4.25     | null    |
|---------------|--------|----------|---------|
| Sidorov Ivan  | 31     | 4        | C++     |
|---------------|--------|----------|---------|
| Pertov Nikita | IU8-31 | 3.330000 | 3 items |
|---------------|--------|----------|---------|
)";
  EXPECT_EQ(compare,parsed.str());
}

TEST(ParserTest, wrongMeta) {
  EXPECT_THROW(parse_json_file(JSON_PATH"meta.json"), std::runtime_error);
}

TEST(ParserTest, notArray) {
  EXPECT_THROW(parse_json_file(JSON_PATH"array.json"), std::runtime_error);
}

TEST(ParserTest, wrongName) {
    EXPECT_THROW(parse_json_file(JSON_PATH"name.json"),std::invalid_argument);
}

TEST(ParserTest, wrongGroup) {
  EXPECT_THROW(parse_json_file(JSON_PATH"group.json"), std::invalid_argument);
}

TEST(ParserTest, wrongAvg) {
  EXPECT_THROW(parse_json_file(JSON_PATH"avg.json"), std::invalid_argument);
}

TEST(ParserTest, wrongDebt) {
  EXPECT_THROW(parse_json_file(JSON_PATH"debt.json"), std::invalid_argument);
}
