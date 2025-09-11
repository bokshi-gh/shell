#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Variables
REPO_URL="https://github.com/bokshi-gh/shell.git"
CLONE_DIR="shell"
SRC_BIN="./dist/bin/rumi"
DEST_BIN="/usr/bin/rumi"

# Clone the repository
if [ ! -d "$CLONE_DIR" ]; then
    git clone "$REPO_URL" "$CLONE_DIR"
else
    echo "Directory '$CLONE_DIR' already exists. Skipping clone."
fi

# Change into the repository directory
cd "$CLONE_DIR"

# Run the build script
if [ -f "./scripts/build.sh" ]; then
    chmod +x ./scripts/build.sh
    ./scripts/build.sh
else
    echo "Build script not found!"
    exit 1
fi

# Copy the built binary to /usr/bin (requires sudo)
if [ -f "$SRC_BIN" ]; then
    echo "Copying $SRC_BIN to $DEST_BIN"
    sudo cp "$SRC_BIN" "$DEST_BIN"
    sudo chmod +x "$DEST_BIN"
    echo "Installation complete!"
else
    echo "Built binary not found at $SRC_BIN"
    exit 1
fi
