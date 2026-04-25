# Project: Tower of Hanoi with Stacks

## Description

This project consists of a C++ application designed to solve the classic Tower of Hanoi problem using stack data structures.

The goal is to simulate the movement of disks between three rods (A, B, and C), following the problem rules and displaying each step of the solution in the console.

The project structure is organized in a modular way, separating source files, headers, and tests to improve maintainability, readability, and scalability.


## Project Structure

```
/
├── include/    # Header files (.h)
├── src/        # (empty) Implementation in headers
├── tests/      # Project tests
├── main.cpp    # Main file
└── README.md   # Documentation
```

## Requirements

To compile and run this project, you need:

* GCC compiler version 10 or higher
* Compatible operating system (Windows, Linux, or macOS)
* Code editor or IDE (recommended: Visual Studio Code with C/C++ extension)

---

## Compilation and Execution

### Compile the main program

In the terminal, at the project root, run:

```bash
g++ main.cpp -o hanoi
```

If the project uses files inside `src/` and `include/`, use:

```bash
g++ main.cpp src/*.cpp -Iinclude -o hanoi
```

### Execution

On Linux/macOS:

```bash
./program
```

On Windows:

```bash
program.exe
```

## Features

The application implements the following requirements:

* Receives the number of disks as input (minimum 1, maximum 10);
* Initializes rod A with properly ordered disks (largest at the bottom, smallest at the top);
* Solves the problem using recursion;
* Displays the total number of moves at the end;
* Displays each move in the format:
  ```
  Move disk X from A to C
  A: [...]   B: [...]   C: [...]
  ```

---

## Tests

### Compile tests

```bash
g++ tests/test.cpp src/*.cpp -Iinclude -o test
```

### Run tests

On Linux/macOS:

```bash
./test
```

On Windows:

```bash
test.exe
```

## Notes

* Each rod is represented using a Stack (either `std::stack` or a custom implementation)
* The algorithm used is recursive, following the classic Tower of Hanoi logic
* Make sure GCC is properly installed and added to your system PATH

---

## Analysis and Justification

### 1. Why is the Stack the most appropriate data structure to model the rods?

The Stack is ideal because it follows the LIFO (Last In, First Out) principle, where only the top element can be accessed or removed. This directly matches the rules of the Tower of Hanoi, where only the top disk can be moved.

Additionally:
* It naturally enforces valid moves
* Prevents access to lower disks
* Accurately represents the physical behavior of the rods

### 2. Is it possible to solve this problem without recursion? If so, how? If not, why?

Yes, it is possible to solve the problem without recursion.

An iterative approach can be used based on movement patterns:
* The smallest disk moves in a fixed cycle
* Other moves follow deterministic rules between rods

Another approach is to simulate recursion using an explicit stack, storing function calls and states manually.

However, the recursive solution is simpler, more elegant, and closer to the mathematical definition of the problem.