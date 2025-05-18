# Rumi

## Overview

Rumi is a minimal shell created using C and C++ designed for Unix-like platforms. It provides a simple command-line interface with essential shell functionalities, aiming to be lightweight and easy to extend.

## Features

Rumi is a lightweight custom shell designed with core Unix-like functionality in mind. It provides:

- Command support for file and folder management
- Utilities for navigation
- Built-in features for process management
- Commands for network related task
-  clean, extensible codebase ideal for learning or experimentation
> Rumi is an independent shell implementation that uses the same underlying Unix system calls as traditional shells like Bash but is built entirely from scratch.

## Getting Started

### Platforms

This shell supports the following platforms:

- Linux
- macOS
- Unix-like systems

### Requirements

- C and C++ compiler (e.g., gcc, clang)
- CMake 3.28.3
- Standard Unix development environment

### Installation

1. **Clone the repository:**
    ```sh
    git clone https://github.com/devrajeshthapa/shell.git
    cd shell
    ```

2. **Build and install using the provided script:**
    ```sh
    ./scripts/build.sh
    ```
    > Note: This script handles building and installing the project automatically.

## Configuration

Since CMake installs the project binaries in the `dist/bin` directory at the project root, you may want to add this directory to your PATH environment variable to easily run the shell from anywhere:

Add the below code snippet to your shell configuration file (e.g., ~/.bashrc or ~/.zshrc) to make it persistent.
```sh
export PATH="$<path_to_project_directory>/dist/bin:$PATH"
```

Reload your bashrc
```sh
source ~/.bashrc
```

## Usage

- Run the shell by executing:
    ```sh
    rumi
    ```
- Inside the shell, enter commands as you would in a typical Unix shell.

- Example:
    ```sh
    ┌──(<user_name>@<host_name>)-[<current_wokring_directory>]
    └─➤ list
    file1 file2 file3 file3 file4 file5
    ```

- Guide
  ```sh
  rumi -g, --guide
  ```

## Contributing

Contributions are welcome! Please fork the repo, make changes, and submit pull requests. Open issues for bugs or feature requests.

## License

This project is licensed under the "GNU General Public License v3.0" - see the [LICENSE](LICENSE) file for details.
