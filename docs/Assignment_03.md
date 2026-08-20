# Assignment 3

## Problem 1: Person and Student Details
Create a base class named "Person" and a derived class "Student".

**Person Class:**
- Attributes: `name`, `age`
- Method: `Show_Name()` - prints "The Name is <name>"
- Method: `Show_Details()` - prints "The Name is <name>. He/She is <age> years old"

**Student Class:**
- Inherits from Person
- Additional attribute: `qualification`
- Method: `Show_Details()` - prints "The Name is <name>. He/She is <age> years old. His/Her Qualification is <qualification>"

**Requirements:**
- Implement necessary constructors and destructors
- Create class instances (objects) in main

## Problem 2: Calculate Total Marks
Create a class named "Subject" with operator overloading.

**Subject Class:**
- Attributes: `Subject_Name`, `Marks`
- Implement operator overloading so that adding 2 Subject objects adds their marks

**Example:**
```cpp
Subject english{"english", 90};
Subject maths{"maths", 80};
Subject total{"", 0};
total = english + maths;
// Now total.marks should equal 170
```

## Problem 3: Calculate Area of Circle and Square
Create an abstract class named "Shapes" with polymorphism.

**Shapes Class (Abstract):**
- Virtual method: `Calculate_Area()`

**Circle Class:**
- Attribute: `Radius`
- Override `Calculate_Area()` to return circle area

**Square Class:**
- Attribute: `Length`
- Override `Calculate_Area()` to return square area

## 🧠 Memory Check
- [ ] **Lifecycle**: Add a `cout << "Destructor"` to your class. When does it print?
- [ ] **Hidden Copies**: Are you passing objects by Value? (Try `const &`).
- [ ] **Cleanup**: If your class allocates memory with `new`, does the Destructor `delete` it?

