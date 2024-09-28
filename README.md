# Network_Programming 📜

Building a Rubik Game with challenges and fighting mode.

## Table of Contents

1. [Project Overview](#project-overview)
2. [Technologies Used](#technologies-used)
3. [Installation](#installation)
4. [How to Run](#how-to-run)
5. [Features](#features)
6. [Techniques and Concepts](#techniques-and-concepts)
7. [Contributing](#contributing)
8. [License](#license)

## Project Overview

Provide a concise summary of the project and its main purpose or objective.

## Technologies Used

- **Programming Language**: C++
- **Graphics Library**: SFML (Simple and Fast Multimedia Library)
- **Build Tool**: CMake / Make
- **Compiler**: MinGW

### Prerequisites

- **MSYS2**: A powerful terminal for Windows with support for multiple package managers and tools.
- **SFML**: A multimedia library required for handling graphics and user input.

## Installation
1. **Download and install MSYS2**:

   You can download it from the official website: [https://www.msys2.org/](https://www.msys2.org/)

2. **Update MSYS2**:
   Open the MSYS2 terminal and run the following commands to update all packages:
   ```bash
   pacman -Syu

3. **Install the MinGW-w64 toolchain**
    ```bash
    pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
    pacman -S mingw-w64-ucrt-x86_64-toolchain

4. **Install SFML library**
    ```bash
    pacman -S mingw-w64-ucrt-x86_64-sfml


