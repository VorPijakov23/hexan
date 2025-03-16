#include "formatter.h"
#include <iomanip>
#include <iostream>
#include <vector>

void print_address(size_t address, size_t address_width) {
  std::cout << std::setw(address_width) << std::setfill('0') << std::uppercase
            << std::hex << address << "    ";
}

void print_hex_values(const std::vector<char> &buffer, size_t bytes_per_line,
                      size_t gcount) {
  for (size_t j = 0; j < gcount; ++j) {
    std::cout << std::setw(2) << std::setfill('0') << std::hex
              << static_cast<int>(static_cast<unsigned char>(buffer[j])) << " ";
    if ((j + 1) % 4 == 0) {
      std::cout << " ";
    }
  }

  for (size_t j = gcount; j < bytes_per_line; ++j) {
    std::cout << "   ";
    if ((j + 1) % 4 == 0) {
      std::cout << " ";
    }
  }
}

void print_ascii_values(const std::vector<char> &buffer, size_t gcount) {
  for (size_t j = 0; j < gcount; ++j) {
    unsigned char ch = buffer[j];
    if (ch >= 32 && ch <= 126) {
      std::cout << ch;
    } else {
      std::cout << ".";
    }
  }
}
