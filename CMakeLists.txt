cmake_minimum_required(VERSION 3.10)
project(hexan)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Указываем директорию с заголовочными файлами
include_directories(include)

# Добавляем исходные файлы
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

set(CMAKE_BUILD_TYPE Release)

file(GLOB_RECURSE SCRIPT_FILES scripts/*.sh scripts/*.py)

# Включаем экспорт команд компиляции
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Добавляем исполняемый файл
add_executable(hexan ${SOURCE_FILES})
