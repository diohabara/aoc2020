#include <iostream>
#include <string>

#include "main/first.h"
#include "main/second.h"

int main() {
  const std::string filename = "data/input";
  std::cout << "First: " << first::count_valid_passwords(filename) << std::endl;
  std::cout << "Second: " << second::count_valid_passwords(filename)
            << std::endl;
  return 0;
}