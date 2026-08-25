# Assignment 8: Employee Management System

## Overview
Build a comprehensive Employee Management System using C++'s advanced Object-Oriented Programming (OOP) concepts, incorporating logging and a login system.

## General Guidelines
1. Each class should have its own header (`.hpp`) and source (`.cpp`) file
2. Adhere to **SOLID principles** while creating class relationships
3. Use proper folder structure and Makefile

## Requirements

### 1. Employee Types
The company Soliton needs to categorize employees:

**Employee Categories:**
- **Engineers:**
  - Hardware Engineers
  - Software Engineers
- **Management Staff**

**Common Employee Attributes:**
- Employee ID (unique for each employee)
- Name
- Position (e.g., "Junior," "Senior," "Lead") – updatable
- Salary – updatable

### 2. Hardware Engineer Specific Feature
- Hardware Engineers assigned a fixed number of hardware units (e.g., 5)
- If another employee tries to check/update hardware count → **Error 9001**

### 3. Employee Management System (Singleton)
- Only **one instance** of the Employee Management System allowed
- Attempting to create duplicate instance → **Error 9000**

### 4. System Features
**View Operations:**
- View employee details by category
- View employee details by position
- View total number of employees

**Administrative Operations:**
- Add a new employee
- Remove an existing employee by ID
- Update an employee's position
- Update an employee's salary
- Search employee details by ID or Position

### 5. Login System
**Authentication:**
- Username-password validation
- Root user account

**Authorization:**
- **Management Staff**: Can perform administrative actions (add, remove, update)
- **Engineers**: Can view and search employee details
  - Salary visible only to Management Staff

### 6. Event Logging
Develop a logger library as a reusable module:

**EventLogger Class:**
- Implemented with separate header and source files
- **Configurable log file location**
- **Log rotation**: Create new log file when current reaches **1 MB**
- **Multiple log levels**:
  - INFO
  - WARNING
  - ERROR

## Error Codes
- **9000**: Duplicate instance of Employee Management System
- **9001**: Unauthorized hardware count access (non-hardware engineer)
- **9002**: Employee ID not found (search, update, or removal)
- **9003**: Unauthorized access attempt (failed login)

## Deliverables
- Well-structured codebase following SOLID principles
- Proper directory organization
- Working Makefile
- Complete implementation of all features
- Comprehensive error handling

## 🧠 Memory Check
- [ ] **The Singleton**: Who deletes the Singleton instance? (Or is it static?)
- [ ] **Employee Cleanup**: When you remove an employee, do you `delete` the object?
- [ ] **String Handling**: Are you using `std::string` to avoid buffer overflows?

