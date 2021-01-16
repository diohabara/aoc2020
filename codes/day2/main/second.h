#ifndef MAIN_SECOND_H_
#define MAIN_SECOND_H_

#include <string>
#include <vector>

namespace second {
int count_valid_passwords(const std::string filename);
bool is_valid(const std::string &validated_str, char key_char, int lower,
              int upper);
}  // namespace second

#endif