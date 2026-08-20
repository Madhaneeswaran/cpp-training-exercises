# Assignment 5: STL & Templates

## Problem 1: Generic Addition Function
Write a C++ function using templates which will add double, int, and float values.

**Requirements:**
- If string is passed to the function, return concatenated string
- Use templates for generic implementation

## Problem 2: Word Frequency Counter
Write a C++ program to analyze word frequency from a file.

**Requirements:**
- Read words from a file as strings
- Use `std::map` to count frequency of each word
- Print the top 10 most frequent words in **alphabetical order**
- Case-insensitive comparison (not ASCII-based)

## Problem 3: Unique Number Storage
Write a C++ program that accepts numerics (double) from the user.

**Requirements:**
- Store values only if they have not already been entered
- Continue accepting input until user types "exit"
- Print all stored values in **sorted order** using STL

## 🧠 Memory Check
- [ ] **Vector Efficiency**: Did you use `.reserve()` before a loop?
- [ ] **Iterators**: Are you modifying the vector while iterating? (Invalidates iterators -> Crash).
- [ ] **Copies**: Iterating with `for(auto item : vec)` copies every item! Use `for(const auto& item : vec)`.

