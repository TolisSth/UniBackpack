# UniBackpack

UniBackpack is a lightweight C++ Qt application designed to automate the installation of essential software and development tools for university students. By selecting the target University and Department, the application automatically detects the underlying Linux distribution's package manager (`apt` or `pacman`) and installs the required toolchain.

## Prerequisites

Before building UniBackpack, ensure that the following dependencies are installed on your system:

* A C++17 compatible compiler (`gcc` or `clang`)
* CMake (version 3.10 or higher)
* Qt6 Development Libraries
* Polkit (`pkexec`) for granting installation privileges

### Installing Dependencies

**For Arch Linux / Manjaro / EndeavourOS:**

```bash
sudo pacman -S base-devel cmake qt6-base qt6-tools polkit
```

## Project Structure

* `src/` - C++ source files (`.cpp`)
* `include/` - C++ header files (`.hpp`)
* `ui/` - Qt Designer forms (`.ui`)
* `resources/lists/` - Configuration files containing the software lists tailored for each academic department.

## Contributors

**Apostolos Chalis - Author**
Email: achalis@csd.auth.gr / cs05414@uowm.gr

**Ioannis Michadasis - Co-Author**
Email: cs05415@uowm.gr