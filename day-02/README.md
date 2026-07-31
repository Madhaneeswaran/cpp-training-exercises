# Day 02 Lab — Arrays, Strings, Pointers & References

Companion to [`cpp-training/docs/Day_02.md`](../../cpp-training/docs/Day_02.md).
Each file below is a **small, runnable experiment**, not just sample code to
read. The method for every file is the same:

1. **Predict** — wherever you see `PREDICT`, stop and write down (in the
   comment, or on paper) what you think will print.
2. **Run** — compile and run just that file.
3. **Check** — compare the real output to your prediction. If you were
   wrong, that's the whole point — that's the concept sinking in.
4. **Break it** — most files have a `TODO` asking you to uncomment
   something that shouldn't compile (or shouldn't run safely). Do it. Read
   the compiler error message, or watch the crash, all the way through.

## Build & run

```bash
cd cpp-learning-exercises/day-02
make              # builds every .exe
./01_arrays_lab.exe   # run one
make clean        # remove all .exe files
```

No `make`? Compile any single file directly:
```bash
g++ -Wall -std=c++17 04_pointers.cpp -o 04_pointers.exe
./04_pointers.exe
```

## File map (matches the syllabus table in Day_02.md)

| File | Syllabus topic | What you'll actually see happen |
|---|---|---|
| `01_arrays_lab.cpp` | Arrays | 0-based indexing, `sizeof`-based element count, an out-of-bounds read that doesn't crash (and why that's scary, not safe) |
| `02_cstyle_strings.cpp` | String (C-style char array) | Manual null terminators, `strlen` vs `sizeof`, a real `strcpy` buffer overflow you trigger yourself |
| `03_std_string.cpp` | C++ string (`std::string`) | The same operations as the C-style file, but with `+`, `==`, `.substr()`, and a bounds-checked `.at()` |
| `04_pointers.cpp` | Pointers | `&`/`*`, `nullptr`, pointer arithmetic walking an array, why `sizeof(pointer)` never changes |
| `05_references.cpp` | References | Aliasing, mandatory initialization, why a reference can never be "reseated", a reference-based swap |
| `06_pass_by_pointer_vs_reference.cpp` | Diff between pass by reference and pass by pointers | The exact same "double this value" function written 3 ways, plus the nullptr crash pointers allow and references don't |
| `07_memory_backend.cpp` | How it works in backend | Printing real addresses to prove a reference IS the original variable's memory, while a pointer variable has its own separate address too |
| `08_lvalue_rvalue.cpp` | LValue and RValue | `T&` vs `T&&` binding rules, a `const T&` that accepts both, and a hands-on lvalue/rvalue quiz |
| `99_capstone_roster_reverser.cpp` | Everything above | A pointer-walked array of `std::string`, reversed in place via a reference-based swap, feeding into a C-style "badge" string |

## Self-check (from Day_02.md's Learning Outcomes)

- [ ] Can declare/initialize an array and explain why the first index is 0, not 1
- [ ] Can explain why a C-string needs a `'\0'` and what `strlen` actually counts
- [ ] Can list at least 2 advantages of `std::string` over a C-style char array
- [ ] Can explain the difference between `&x` (address-of) and `*p` (dereference)
- [ ] Can state why a reference can't be `nullptr` but a pointer can
- [ ] Can write the same "modify the caller's variable" function as pass-by-value, pass-by-pointer, and pass-by-reference, and predict which ones actually work
- [ ] Can explain, using addresses, why writing through a reference and writing through a pointer both ultimately touch the same memory
- [ ] Can classify a given expression as an lvalue or rvalue and say why `const T&` accepts both

## Next step

Once every box above is checked, move on to `Assignment_01.md` in the
training repo if you haven't already, then continue to Day 03.
