# Assignment 6: Multi-Threading

## Problem 1: Producer-Consumer Pattern
Write a C++ program using multithreading and Vectors to create a producer-consumer pattern.

**Requirements:**

**Main Function:**
- Launch producer and consumer threads

**Producer Thread:**
- Get a number and an arithmetic operation from user (Addition, Subtraction, Multiplication, Division)
- Enqueue into the queue
- Notify consumer once enqueued
- If operation is "stop":
  - Enqueue "stop" to queue
  - Exit function

**Consumer Thread:**
- Wait for notification
- Maintain a variable (initialized to 0)
- On notification:
  - Dequeue value from queue
  - Perform operation on the variable
  - Print result in console
- If operation is "stop":
  - Flush the queue
  - Exit

**Implementation Notes:**
- Producer and consumer run in different threads
- Use proper synchronization mechanisms
- Handle thread-safe queue operations

## 🧠 Memory Check
- [ ] **Data Races**: Are multiple threads writing to the same variable without a `mutex`?
- [ ] **Deadlocks**: Do you have a `lock_guard` that goes out of scope?
- [ ] **Detached Threads**: If you `detach()`, does the thread access variables that might have been destroyed (dangling reference)?
