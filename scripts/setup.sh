#!/bin/env bash

set -e

# Определение директории скрипта
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Проверка наличия ключа очистки
CLEAN=false
for arg in "$@"; do
  if [ "$arg" == "-c" ] || [ "$arg" == "--clean" ] || [ "$arg" == "--clear" ]; then
    CLEAN=true
    break
  fi
done

# Создание и переход в директорию сборки
BUILD_DIR="$SCRIPT_DIR/../build"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# Настройка и сборка проекта
echo "Configuring and building the project..."
cmake ..
make

# Копирование собранного бинарника в /usr/bin/
echo "Installing hexan..."
sudo install -m 755 $SCRIPT_DIR/../bin/hexan /usr/bin/

# Проверка успешной установки
if command -v hexan &> /dev/null; then
    echo "hexan is installed and ready to use."
else
    echo "installation error: hexan is not in the PATH."
    exit 1
fi

echo "Installation completed successfully"

# Удаление папок bin и build, если указан ключ очистки
if [ "$CLEAN" = true ]; then
  echo "Cleaning up..."
  rm -rf "$BUILD_DIR"
  rm -rf "$SCRIPT_DIR/../bin"
fi

exit 0
