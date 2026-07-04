# Shell

A tiny shell written in C.

> [!Note]
> It is compatible only with Unix-like operating systems.

## Getting Started

### Requirements

* GNU GCC
* CMake 3.28.3 or later

### Installation

#### Option 1: Install using the installer script

Install shell with a single command:

```sh
curl -fsSL https://raw.githubusercontent.com/bokshi-gh/shell/main/scripts/install.sh | bash
```

#### Option 2: Build locally

1. **Clone the repository:**

   ```sh
   git clone https://github.com/bokshi-gh/shell.git
   cd shell
   ```

2. **Build the project:**

   ```sh
   ./scripts/build.sh
   ```

3. **Run the generated binary:**

   The executable is generated in:

   ```text
   dist/bin/
   ```

## Usage

Run the shell:

```sh
shell
```

Display the built-in guide:

```sh
shell -g
```

or

```sh
shell --guide
```
