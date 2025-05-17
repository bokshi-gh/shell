# Rumi

## Overview

Rumi is a minimal shell created using C and C++ designed for Unix-like platforms. It provides a simple command-line interface with essential shell functionalities, aiming to be lightweight and easy to extend.

## Features

- Basic command parsing and execution
- Support for common Unix commands
- Customizable prompt showing user, host, and current directory
- Minimal external dependencies
- Simple and clean codebase for learning and extension

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
    git clone https://github.com/{{your-username}}/rumi.git
    cd rumi
    ```

2. **Build and install using the provided script:**
    ```sh
    ./scripts/build.sh
    ```
    > Note: This script handles building and installing the project automatically.

## Configuration

Since CMake installs the project binaries in the `dist/bin` directory at the project root, you may want to add this directory to your PATH environment variable to easily run the shell from anywhere:

```sh
export PATH="$(pwd)/dist/bin:$PATH"
```
Add the above line to your shell configuration file (e.g., ~/.bashrc or ~/.zshrc) to make it persistent..

## Usage

- Run the shell by executing:
    ```sh
    rumi
    ```
- Inside the shell, enter commands as you would in a typical Unix shell.

- Example:
    ```sh
    <user_name>@<host_name>:<cwd>$ list
    a b c d e f
    <user_name>@<host_name>:<cwd>$
    ```

## Contributing

Contributions are welcome! Please fork the repo, make changes, and submit pull requests. Open issues for bugs or feature requests.

## License

This project is licensed under the {{License Name}} License - see the [LICENSE](LICENSE) file for details.
