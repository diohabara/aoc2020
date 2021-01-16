#include "main/second.h"

#include <string>
#include <vector>

#include "main/common.h"

namespace second {
int count_valid_passwords(const std::string filename) {
  auto lines = common::read_line_by_line(filename);
  int cnt = 0;
  for (auto line : lines) {
    int lower, upper;
    std::string str_line = line.c_str();
    char key_char;
    std::string password;
    auto vec_line = common::split(str_line, ' ');
    // separate lines
    for (auto i = 0; i < vec_line.size(); ++i) {
      if (i == 0) {
        auto bounds = common::split(vec_line[i], '-');
        lower = stoi(bounds[0]) - 1;
        upper = stoi(bounds[1]) - 1;
      }
      if (i == 1) {
        key_char = vec_line[i][0];
      }
      if (i == 2) {
        password = vec_line[i];
      }
    }
    if (is_valid(password, key_char, lower, upper)) {
      ++cnt;
    }
  }
  return cnt;
}

bool is_valid(const std::string &validated_str, char key_char, int lower,
              int upper) {
  return validated_str[lower] == key_char ^ validated_str[upper] == key_char;
}
}  // namespace second