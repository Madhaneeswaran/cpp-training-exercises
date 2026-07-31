# Day 03 Lab — Memory, Smart Pointers, I/O & Data Structures

Companion to [`cpp-training/docs/Day_03.md`](../../cpp-training/docs/Day_03.md).
This is the heaviest day so far — dynamic memory is the first C++ topic
with **no real JavaScript equivalent** (JS's garbage collector hides all of
this from you). Take these slower than Day 01/02, and lean hard on the
method:

1. **Predict** — wherever you see `PREDICT`, stop and write down what you
   think will happen.
2. **Run** — compile and run just that file.
3. **Check** — compare the real output to your prediction.
4. **Break it** — most files have a `TODO` asking you to uncomment
   something unsafe. Do it, and read the compiler warning or crash
   carefully — for this topic especially, the crash/warning IS the lesson.

## Build & run

```bash
cd cpp-learning-exercises/day-03
make              # builds every .exe
./01_memory_layout.exe
make clean        # remove all .exe files
```

No `make`? Compile any single file directly:
```bash
g++ -Wall -std=c++17 07_unique_ptr.cpp -o 07_unique_ptr.exe
./07_unique_ptr.exe
```

`10_io_streams.cpp` reads from the keyboard — either type input when
prompted, or feed it non-interactively:
```bash
echo "Ada Lovelace
Hello there, this is a whole sentence" | ./10_io_streams.exe
```

## File map (matches the syllabus table in Day_03.md)

| File | Syllabus topic | What you'll actually see happen |
|---|---|---|
| `01_memory_layout.cpp` | Memory Layout of C++ Program | Real addresses from the code, data, stack, and heap segments, printed side by side |
| `02_stack_vs_heap.cpp` | Stack vs Heap Memory | Automatic vs manual lifetime, heap memory outliving the function that created it, a stack overflow you can trigger on purpose |
| `03_buffers_raw_memory.cpp` | Buffers and Raw Memory | The same bytes read as text vs as numbers, and a `memcpy` buffer overflow |
| `04_new_delete.cpp` | Basic Allocation (new/delete) | `new`/`delete` for one object, `new[]`/`delete[]` for arrays, why mismatching them is dangerous |
| `05_memory_leaks.cpp` | Memory Leaks | An obvious leak, a realistic loop-based leak, and the fix side by side |
| `06_dangling_pointers.cpp` | Dangling Pointers | Returning a dead stack address, using memory after `delete`, and the `nullptr`-after-delete fix |
| `07_unique_ptr.cpp` | Auto Pointer (Deprecated) + Unique Pointer | RAII in action, why copying is a compile error, `std::move` transferring ownership |
| `08_shared_weak_ptr.cpp` | Shared Pointer, Weak Pointer, Comparison | Live `use_count()` tracking, a `weak_ptr` safely detecting a destroyed object via `lock()` |
| `09_date_time.cpp` | Date and Time | Current time, the classic `tm_year`/`tm_mon` offset gotchas, `strftime` formatting |
| `10_io_streams.cpp` | cin, cout, cerr | Reading tokens vs whole lines, and cout/cerr as genuinely separate, independently redirectable streams |
| `11_endl_vs_newline.cpp` | endl vs '\n' | A timed comparison showing the real cost of `std::endl`'s forced flush |
| `12_manipulators.cpp` | Manipulators | `setw`, `setfill`, `setprecision`, `fixed`, and the "setw only lasts one field" gotcha |
| `13_struct.cpp` | Struct | Declaring, initializing, nesting, and arrays of structs |
| `14_union.cpp` | Union | Same fields, shared memory — struct vs union size compared directly |
| `99_capstone_student_records.cpp` | Everything above | A heap-allocated roster owned by `unique_ptr` (no manual `delete[]`), timestamped with `<ctime>`, reported with manipulators, warnings routed to `cerr` |

## Self-check (from Day_03.md's Learning Outcomes)

- [ ] Can name the 4 memory segments and say which kind of variable lives in each
- [ ] Can explain why the stack is fast-but-small and the heap is slower-but-flexible
- [ ] Can explain what a buffer is and why raw memory has "no type safety"
- [ ] Can use `new`/`delete` and `new[]`/`delete[]` correctly, and explain why they can't be mixed
- [ ] Can define "memory leak" and point to the exact line that caused one in `05_memory_leaks.cpp`
- [ ] Can define "dangling pointer" and explain why setting a pointer to `nullptr` after `delete` helps
- [ ] Can explain why `unique_ptr` can't be copied but can be moved
- [ ] Can explain reference counting well enough to predict `use_count()` at any point in `08_shared_weak_ptr.cpp`
- [ ] Know when to reach for `unique_ptr` vs `shared_ptr` vs `weak_ptr`
- [ ] Can get the current date/time and format it with `strftime`
- [ ] Know the difference between `cin >>` and `std::getline`, and between `cout` and `cerr`
- [ ] Can explain why `std::endl` is sometimes slower than `'\n'`
- [ ] Can use at least 3 I/O manipulators (`setw`, `setprecision`, `setfill`)
- [ ] Can define a struct, initialize it, and access members with `.`
- [ ] Can explain why `sizeof(union)` is NOT the sum of its members' sizes

## Next step

Once every box above is checked, move on to `Assignment_02.md` in the
training repo, then continue to Day 04.
