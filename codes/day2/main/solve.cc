#include <iostream>
#include <string>

#include "main/first.h"

int main() {
  const std::string filename = "data/input";
  std::cout << "First: " << first::count_valid_passwords(filename) << std::endl;
  return 0;
}