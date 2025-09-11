#!/bin/bash

set -e  # Exit immediately if a command fails

# Variables
REPO_URL="https://github.com/bokshi-gh/shell.git"
TEMP_DIR="/tmp/shell_build_$$"  # Unique temporary directory
SRC_BIN="./dist/bin/rumi"
DEST_BIN="/usr/bin/rumi"

echo "Creating temporary directory: $TEMP_DIR"
mkdir -p "$TEMP_DIR"

echo "Cloning repository into temporary directory..."
git clone "$REPO_URL" "$TEMP_DIR"

# Change into the temporary repository
cd "$TEMP_DIR"

# Run the build script
if [ -f "./scripts/build.sh" ]; then
    echo "Running build script..."
    chmod +x ./scripts/build.sh
    ./scripts/build.sh
else
    echo "Build script not found!"
    exit 1
fi

# Copy the built binary to /usr/bin
if [ -f "$SRC_BIN" ]; then
    echo "Copying $SRC_BIN to $DEST_BIN (requires sudo)"
    sudo cp "$SRC_BIN" "$DEST_BIN"
    sudo chmod +x "$DEST_BIN"
    echo "Installation complete!"
else
    echo "Built binary not found at $SRC_BIN"
    exit 1
fi

# Cleanup
cd /
rm -rf "$TEMP_DIR"
echo "Temporary directory removed: $TEMP_DIR"
