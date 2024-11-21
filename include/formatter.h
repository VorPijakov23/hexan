#include <cstddef>
#include <vector>
#pragma once

void print_address(std::size_t address, size_t address_width);
void print_hex_values(const std::vector<char> &buffer, size_t bytes_per_line,
                      size_t gcount);
void print_ascii_values(const std::vector<char> &buffer, size_t gcount);