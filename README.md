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

- Customize the prompt format by editing the source code or config files if implemented.
- Environment variables like `PATH` affect command lookup.

## Usage

- Run the shell by executing:
    ```sh
    ./rumi
    ```
- Inside the shell, enter commands as you would in a typical Unix shell.

- Example:
    ```sh
    ls -l
    pwd
    exit
    ```

## Contributing

Contributions are welcome! Please fork the repo, make changes, and submit pull requests. Open issues for bugs or feature requests.

## License

This project is licensed under the {{License Name}} License - see the [LICENSE](LICENSE) file for details.
