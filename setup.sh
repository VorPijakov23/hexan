#!/bin/env bash

set -e

if [ "$EUID" -ne 0 ]; then
  echo "setup.sh: Permission denied: use 'sudo'"
  exit 1
fi

if ! command -v g++ &> /dev/null; then
    echo "setup.sh: g++ not found. Please, install gcc."
    exit 1
fi

if [ ! -f "hexan.cpp" ]; then
    echo "setup.sh: Source files not found. Make sure main.cpp and hexan.cpp exist."
    exit 1
fi

echo "compiling..."
g++ -o hexan hexan.cpp

sudo install -m 755 hexan /usr/local/bin/

echo "Clean..."
sudo rm hexan

echo "installation completed successfully"

if command -v hexan &> /dev/null; then
    echo "hexan is installed and ready to use."
else
    echo "installation error: hexan is not in the PATH."
    exit 1
fi

exit 0