#!/usr/bin/env bash

set -euo pipefail

# Configuration
REPO_URL="https://github.com/bokshi-gh/shell.git"
TEMP_DIR="$(mktemp -d)"
DEST_BIN="/usr/local/bin/shell"

cleanup() {
    rm -rf "$TEMP_DIR"
}

trap cleanup EXIT

echo "Checking dependencies..."

for cmd in git gcc cmake sudo; do
    if ! command -v "$cmd" >/dev/null 2>&1; then
        echo "Error: '$cmd' is required but is not installed."
        exit 1
    fi
done

echo "Cloning Shell..."
git clone --depth 1 "$REPO_URL" "$TEMP_DIR"

cd "$TEMP_DIR"

if [ ! -f "./scripts/build.sh" ]; then
    echo "Error: scripts/build.sh not found."
    exit 1
fi

chmod +x ./scripts/build.sh

echo "Building..."
./scripts/build.sh

SRC_BIN="./dist/bin/shell"

if [ ! -f "$SRC_BIN" ]; then
    echo "Error: Build succeeded but binary was not found at $SRC_BIN."
    exit 1
fi

echo "Installing to $DEST_BIN..."
sudo install -m 755 "$SRC_BIN" "$DEST_BIN"

echo
echo "Shell has been installed successfully!"
echo
echo "Run it with:"
echo "  shell"
echo
echo "For the built-in guide:"
echo "  shell --guide"
```
