# Day 01 Lab — Practical C++ Basics

Companion to [`cpp-training/docs/Day_01.md`](../../cpp-training/docs/Day_01.md).
Each file below is a **small, runnable experiment**, not just sample code to
read. The method for every file is the same:

1. **Predict** — wherever you see `PREDICT`, stop and write down (in the
   comment, or on paper) what you think will print.
2. **Run** — compile and run just that file.
3. **Check** — compare the real output to your prediction. If you were
   wrong, that's the whole point — that's the concept sinking in.
4. **Break it** — most files have a `TODO` asking you to uncomment
   something that shouldn't compile, or change a value. Do it. Read the
   compiler error message all the way through.

## Build & run

```bash
cd cpp-learning-exercises/day-01
make              # builds every .exe
./01_comments.exe # run one
make clean        # remove all .exe files
```

No `make`? Compile any single file directly:
```bash
g++ -Wall -std=c++17 07_loops_lab.cpp -o 07_loops_lab.exe
./07_loops_lab.exe
```

`05b_extern_main.cpp` / `05b_extern_helper.cpp` are a pair — they must be
compiled **together** (the Makefile's `extern` target, or `make all`,
already handles this):
```bash
g++ -std=c++17 -Wall 05b_extern_main.cpp 05b_extern_helper.cpp -o 05b_extern.exe
```

## File map (matches the syllabus table in Day_01.md)

| File | Syllabus topic | What you'll actually see happen |
|---|---|---|
| `01_comments.cpp` | Commenting | How comments silence code, and one surprise about `main()`'s implicit return |
| `02_data_types_lab.cpp` | Data Types | Real `sizeof` values on your machine, `INT_MAX` overflow, float vs double precision |
| `03_variables_scope.cpp` | Variable Types, Variable Scope | Block-scope variable "death", global vs local shadowing |
| `04_constants_modifiers.cpp` | Constants/Literals, Modifier Types | `const` vs `#define`, signed/unsigned overflow wraparound, a live Windows-vs-Linux `long` size gotcha |
| `05_storage_classes.cpp` + `05b_extern_*.cpp` | Storage Classes | `static` surviving across calls, `extern` sharing one variable across two `.cpp` files |
| `06_operators_playground.cpp` | Operators | Precedence traps (predict-first), pre vs post increment, bitwise ops in binary |
| `07_loops_lab.cpp` | Loops | `for`/`while`/`do-while` side by side, `break` vs `continue`, pyramid + FizzBuzz |
| `08_decision_making.cpp` | Decision Making | `if/else if/else`, `switch`, and a real fallthrough bug (no `break`) |
| `09_numbers_lab.cpp` | Numbers | `<cmath>` functions, `rand()`/`srand()`, why seeding matters (rerun it and see) |
| `10_functions_lab.cpp` | Functions | Prototypes, pass-by-value, default parameters |
| `99_capstone_guessing_game.cpp` | Everything above | A real number-guessing game combining loops + conditionals + functions + random numbers + a `static` attempt counter |

## Self-check (from Day_01.md's Learning Outcomes)

- [ ] Can explain the difference between `//` and `/* */` comments
- [ ] Can state the byte size of `int`, `char`, `float`, `double`, `bool` **on your machine** (not just "textbook" numbers)
- [ ] Can explain declaration vs definition in your own words
- [ ] Can predict when a variable goes out of scope, just by looking at `{ }` blocks
- [ ] Can explain why `const` is safer than `#define`
- [ ] Know that `signed`/`unsigned`/`short`/`long` change both size and range
- [ ] Can explain why a `static` local variable "remembers" its value between calls
- [ ] Can evaluate a precedence-trap expression by hand and verify it by compiling
- [ ] Can write `for`, `while`, and `do-while` versions of the same loop
- [ ] Can explain `switch` fallthrough and why `break` matters
- [ ] Know at least 3 functions from `<cmath>` and how `rand()`/`srand()` work
- [ ] Can write a function with parameters, a return value, and explain pass-by-value

## Next step

Once every box above is checked, move on to `Assignment_01.md` in the
training repo (Leap Year, Function Call Counter, Name Processing) — write
those solutions **here**, in this practice repo, not in `cpp-training`.
