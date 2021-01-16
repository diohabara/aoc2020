
#include "main/common.h"

#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace common {
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
}  // namespace common