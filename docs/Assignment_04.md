# Assignment 4: Error Handling & File I/O

## Problem 1: Custom Exception for Division
Write a simple C++ function which will perform Addition, Subtraction, Multiplication, and Division.

**Requirements:**
- When dividing by 0, throw a custom exception with error code and description
- Print error code and description in console
- Use a class for custom exception
- All exception classes should inherit from `std::exception`

## Problem 2: File Retention Policy Logger
Implement a file retention policy for logging data.

**Disk Memory Retention Policy:**
In data logging, disk memory retention policy refers to the rules that determine how long data is stored on disk before it is archived, deleted, or overwritten.

**Requirements:**
- Log current date and time to a file within a "logs" folder
- Each log file has a size limit of **2MB**
- Once file size exceeds 2MB, create a new file
- Total size of all files in "logs" folder limited to **20MB**
- If folder exceeds 20MB, automatically delete the oldest five log files
- When application is relaunched, create a new file and continue logging
- Apply retention policy continuously

## 🧠 Memory Check
- [ ] **Files**: If an exception is thrown, does your file close? (RAII!)
- [ ] **Leaks**: If you `new` an Exception object, who `delete`s it? (Prefer throwing by value, catching by reference).

