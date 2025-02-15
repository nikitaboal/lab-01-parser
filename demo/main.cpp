// Copyright 2021 Nikita Boldaev <nikbold-02@yandex.ru>
#include <student.hpp>

using json = nlohmann::json;

  int main(int argc, char* argv[]) {
    if (argc != 1) {
      for (int i = 1; i < argc; i++) {
        auto students = parse_json_file(argv[i]);
        Print(students, std::cout);
      }
    } else {
      throw std::invalid_argument("Expected a path for a *.json file");
    }
    return 0;
}
