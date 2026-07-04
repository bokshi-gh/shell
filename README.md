# Shell

A tiny shell written in C.

> [!NOTE]
> Shell is compatible only with Unix-like operating systems.

## Getting Started

### Requirements

* GNU GCC
* CMake 3.28.3 or later

### Installation

1. **Clone the repository:**

   ```sh
   git clone https://github.com/bokshi-gh/shell.git
   cd shell
   ```

2. **Configure the project:**

   ```sh
   cmake -B build
   ```

3. **Build the project:**

   ```sh
   cmake --build build
   ```

4. **Install the executable:**

   ```sh
   sudo cmake --install build
   ```

By default, the executable is installed to:

```text
/usr/local/bin/shell
```

### Usage

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
