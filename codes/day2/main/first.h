#ifndef MAIN_FIRST_H_
#define MAIN_FIRST_H_

#include <string>
#include <vector>

namespace first {
int count_valid_passwords(const std::string filename);
bool is_valid(const std::string &counted_str, char count_char, int lower,
              int upper);
}  // namespace first

#endif