#include "main/first.h"

#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace first {
int count_valid_passwords(const std::string filename) {
  auto lines = read_line_by_line(filename);
  int cnt = 0;
  for (auto line : lines) {
    int lower, upper;
    std::string str_line = line.c_str();
    char count_char;
    std::string password;
    auto vec_line = split(str_line, ' ');
    // separate lines
    for (auto i = 0; i < vec_line.size(); ++i) {
      if (i == 0) {
        auto bounds = split(vec_line[i], '-');
        lower = stoi(bounds[0]);
        upper = stoi(bounds[1]);
      }
      if (i == 1) {
        count_char = vec_line[i][0];
      }
      if (i == 2) {
        password = vec_line[i];
      }
    }
    if (is_valid(password, count_char, lower, upper)) {
      ++cnt;
    }
  }
  return cnt;
}

std::vector<std::string> read_line_by_line(const std::string filename) {
  std::ifstream file(filename);
  std::vector<std::string> ret{};

  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      ret.push_back(line);
    }
    file.close();
  }
  return ret;
}

template <typename Out>
void split(const std::string &s, char delim, Out result) {
  std::istringstream iss(s);
  std::string item;
  while (std::getline(iss, item, delim)) {
    *result++ = item;
  }
}

std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  split(s, delim, std::back_inserter(elems));
  return elems;
}

bool is_valid(const std::string &counted_str, char count_char, int lower,
              int upper) {
  int cnt = 0;
  for (auto counted_char : counted_str) {
    if (counted_char == count_char) {
      ++cnt;
    }
  }
  return lower <= cnt && cnt <= upper;
}
}  // namespace first