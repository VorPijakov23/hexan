#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define BYTES_PER_LINE 24
#define ADDRESS_WIDTH 8

void hexan(std::ifstream &file) {
  std::vector<char> buffer(BYTES_PER_LINE);
  size_t address = 0;

  while (file.read(buffer.data(), buffer.size())) {
    // ADDRES
    std::cout << std::setw(ADDRESS_WIDTH) << std::setfill('0') << std::uppercase
              << std::hex << address << "    ";

    // HEX
    for (size_t j = 0; j < BYTES_PER_LINE; ++j) {
      std::cout << std::setw(2) << std::setfill('0') << std::hex
                << static_cast<int>(static_cast<unsigned char>(buffer[j]))
                << " ";
      if ((j + 1) % 4 == 0) {
        std::cout << " ";
      }
    }

    std::cout << " ";

    // ASCII
    for (size_t j = 0; j < BYTES_PER_LINE; ++j) {
      unsigned char ch = buffer[j];
      if (ch >= 32 && ch <= 126) {
        std::cout << ch;
      } else {
        std::cout << ".";
      }
    }

    std::cout << std::endl;
    address += BYTES_PER_LINE;
  }

  // Если остались байты, которые не составляют полные 24 байта, выводим их
  // Если при последнем прочтении файла, кол-во оставшиъ байтов было больше
  // нуля, то оставшиеся байты проходятся по немного другому алгоритму
  if (file.gcount() > 0) {
    // Print address
    std::cout << std::setw(ADDRESS_WIDTH) << std::setfill('0') << std::uppercase
              << std::hex << address << "    ";

    // Print hex values
    for (size_t j = 0; j < file.gcount(); ++j) {
      std::cout << std::setw(2) << std::setfill('0') << std::hex
                << static_cast<int>(static_cast<unsigned char>(buffer[j]))
                << " ";
      if ((j + 1) % 4 == 0) {
        std::cout << " ";
      }
    }

    for (size_t j = file.gcount(); j < BYTES_PER_LINE; ++j) {
      std::cout << "   ";
      if ((j + 1) % 4 == 0) {
        std::cout << " ";
      }
    }

    std::cout << " ";

    // Print ASCII values
    for (size_t j = 0; j < file.gcount(); ++j) {
      unsigned char ch = buffer[j];
      if (ch >= 32 && ch <= 126) {
        std::cout << ch;
      } else {
        std::cout << ".";
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
    std::cerr << "hexan: Error opening file: " << argv[1] << std::endl;
    return 1;
  }

  hexan(file);

  return 0;
}