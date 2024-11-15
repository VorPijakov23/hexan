#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

void hexan(const std::vector<unsigned char> &data) {
  const int bytesPerLine = 24;
  const int addressWidth = 8;

  for (size_t i = 0; i < data.size(); i += bytesPerLine) {
    // Print address
    std::cout << std::setw(addressWidth) << std::setfill('0') << std::uppercase
              << std::hex << i << "    ";

    // Print hex values
    for (size_t j = 0; j < bytesPerLine; ++j) {
      if (i + j < data.size()) {
        std::cout << std::setw(2) << std::setfill('0') << std::hex
                  << static_cast<int>(data[i + j]) << " ";
      } else {
        std::cout << "   ";
      }
      if (j % 4 == 3) {
        std::cout << " ";
      }
    }

    std::cout << " ";

    // Print ASCII values
    for (size_t j = 0; j < bytesPerLine; ++j) {
      if (i + j < data.size()) {
        unsigned char ch = data[i + j];
        if (ch >= 32 && ch <= 126) {
          std::cout << ch;
        } else {
          std::cout << ".";
        }
      } else {
        std::cout << " ";
      }
    }

    std::cout << std::endl;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "hexan: Usage: hexan <file_path>" << std::endl;
    return 1;
  }

  std::ifstream file(argv[1], std::ios::binary);
  if (!file) {
    std::cerr << "hexan : Error opening file: " << argv[1] << std::endl;
    return 1;
  }

  std::vector<unsigned char> data((std::istreambuf_iterator<char>(file)),
                                  std::istreambuf_iterator<char>());
  file.close();

  hexan(data);

  return 0;
}