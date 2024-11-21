#include "hexan.h"
#include "formatter.h"
#include <vector>
#include <iostream>

void hexan(std::ifstream &file, size_t bytes_per_line, size_t address_width) {
  std::vector<char> buffer(bytes_per_line);
  size_t address = 0;

  while (file.read(buffer.data(), buffer.size())) {
    print_address(address, address_width);
    print_hex_values(buffer, bytes_per_line, bytes_per_line);
    std::cout << " ";
    print_ascii_values(buffer, bytes_per_line);
    std::cout << std::endl;
    address += bytes_per_line;
  }

  // Если остались байты, которые не составляют полные bytes_per_line байта, выводим их
  if (file.gcount() > 0) {
    print_address(address, address_width);
    print_hex_values(buffer, bytes_per_line, file.gcount());
    std::cout << " ";
    print_ascii_values(buffer, file.gcount());
    std::cout << std::endl;
  }
}