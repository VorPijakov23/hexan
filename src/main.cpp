#include "hexan.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

const size_t default_bytes_per_line = 16;
const size_t address_width = 8;
const size_t max_bytes_per_line = 1024;

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cerr << "hexan: Usage option: --help" << std::endl;
    return 1;
  }

  const char *file_path = nullptr;
  size_t bytes_per_line = default_bytes_per_line;

  for (int i = 1; i < argc; ++i) {
    if (std::strcmp(argv[i], "--help") == 0 ||
        std::strcmp(argv[i], "-h") == 0) {
      std::cout << "Usage: hexan [OPTIONS] [FILE]" << std::endl;
      std::cout << "Options:" << std::endl;
      std::cout << "  --help, -h    Display this help message" << std::endl;
      std::cout
          << "  --bytes, -b    The number of bytes in the line (Default 16)"
          << std::endl;
      return 0;
    } else if (std::strcmp(argv[i], "--bytes") == 0 ||
               std::strcmp(argv[i], "-b") == 0) {
      if (i + 1 < argc) {
        char *end;
        unsigned long value = std::strtoul(argv[++i], &end, 10);
        if (*end != '\0' || value == 0 || value > max_bytes_per_line) {
          std::cerr << "hexan: Invalid value for --bytes option: " << argv[i]
                    << std::endl;
          return 1;
        }
        bytes_per_line = static_cast<size_t>(value);
      }

      else {
        std::cerr << "hexan: --bytes option requires a value" << std::endl;
        return 1;
      }
    } else if (file_path == nullptr) {
      file_path = argv[i];
    } else {
      std::cerr << "hexan: Unexpected argument: " << argv[i] << std::endl;
      return 1;
    }
  }

  if (file_path == nullptr) {
    std::cerr << "hexan: No file specified" << std::endl;
    return 1;
  }

  std::ifstream file(file_path, std::ios::binary);
  if (!file) {
    std::cerr << "hexan: Error opening file: " << file_path << std::endl;
    return 1;
  }

  hexan(file, bytes_per_line, address_width);

  return 0;
}
