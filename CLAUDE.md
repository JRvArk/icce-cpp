# CLAUDE.md

## Project

Self-study solutions to the C++ exercises from the ICCE course by the Department of Computing Science at the University of Groningen (RUG), authored by Frank B. Brokken and Jurjen Bokma. Primary reference is the C++ Annotations textbook.

## Repository Layout

```
part-I/
  set1/
    1/          ← exercise folder (digits only)
    2/
    ...
  set4/
    28/
      exercise_text.txt
      main.cpp
      line/
        line.h
        ...
part-II/
part-III/
Makefile
```

## How to Help

**Before doing anything else, read `exercise_text.txt` in the exercise folder.** It is the authoritative source for what the exercise requires, including constraints and hints. Do not assume the intent from the code alone.

Exercise folders are named with digits only (e.g. `28/`), nested under `part-X/setY/`.

Some exercises are textual (no code); those have a `textual_answer.txt` instead of source files.

## Building

Use the root `Makefile`. The target format is `X.Y.Z` where X = part, Y = set, Z = exercise:

```
make 1.4.28   # builds part-I/set4/28/
make 2.1.5    # builds part-II/set1/5/
```

The Makefile compiles all `.cpp` files found recursively under the exercise directory and outputs a `solution` binary in that directory. To remove all built binaries:

```
make clean
```

## Coding Conventions

- All class data members must be prefixed with `d_` (e.g., `d_position`, `d_current_line`). This is the style used throughout the course.

## Toolchain

- Compiler: `g++` (GNU C++) on macOS
- Standard: C++23 (`-std=c++23`)
- Flags: `-Wall -Wextra`
