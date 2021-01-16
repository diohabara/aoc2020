#ifndef MAIN_COMMON_H_
#define MAIN_COMMON_H_

#include <string>
#include <vector>

namespace common {
std::vector<std::string> read_line_by_line(const std::string filename);
std::vector<std::string> split(const std::string &s, char delim);
}  // namespace common

#endif