// Copyright 2021 Nikita Boldaev <nikbold-02@yandex.ru>

#ifndef INCLUDE_STUDENT_HPP_
#define INCLUDE_STUDENT_HPP_

#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <any>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iomanip>


struct student_t {
  std::string name;
  std::any group;
  std::any avg;
  std::any debt;
};

struct col_widths{
  int name_width;
  int group_width;
  int avg_width;
  int debt_width;
};

std::vector<student_t> parse_json_file(const std::string& path);

col_widths table_params(const std::vector<student_t>& students);
void Print(const std::vector<student_t>& students,
           std::ostream& ostr = std::cout);

#endif // INCLUDE_STUDENT_HPP_
