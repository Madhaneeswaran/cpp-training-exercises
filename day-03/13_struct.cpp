#include <iostream>
#include <string>

// JS BRIDGE: a struct looks a LOT like a JS object literal's shape, but
// there's a key difference -- a struct's fields (names AND types) are
// FIXED at compile time. You can't add a random new field at runtime like
// `obj.extraThing = 5` the way you can in JS. What you get in exchange is
// the compiler catching typos and type mistakes in every field, for free.

struct Employee {
    std::string name;
    int age;
    double salary;
};

void printEmployee(const Employee& e) {   // pass by const ref -- see Day 02!
    std::cout << e.name << ", age " << e.age << ", salary $" << e.salary << "\n";
}

bool isHigherPaid(const Employee& a, const Employee& b) {
    if (a.salary > b.salary) return true;

    return false;
}

int main() {
    std::cout << "--- creating and initializing ---\n";
    Employee alice;              // fields start UNINITIALIZED (garbage!) -- fill them in
    alice.name = "Alice";
    alice.age = 30;
    alice.salary = 75000.0;
    printEmployee(alice);

    std::cout << "\n--- aggregate initialization (all fields at once, in order) ---\n";
    Employee bob = {"Bob", 25, 60000.0};
    printEmployee(bob);

    std::cout << "\n--- member access with the dot (.) operator ---\n";
    bob.salary += 5000.0;   // bob got a raise
    std::cout << "bob.salary after raise = " << bob.salary << "\n";

    std::cout << "\n--- structs can hold OTHER structs ---\n";
    struct Team {
        std::string teamName;
        Employee lead;
    };
    Team engineering = {"Engineering", alice};
    std::cout << engineering.teamName << " is led by " << engineering.lead.name << "\n";

    std::cout << "\n--- an array of structs ---\n";
    Employee staff[3] = {
        {"Carol", 41, 90000.0},
        {"Dave", 22, 50000.0},
        {"Eve", 35, 82000.0},
    };
    double totalPayroll = 0;
    for (int i = 0; i < 3; i++) {
        printEmployee(staff[i]);
        totalPayroll += staff[i].salary;
    }
    std::cout << "total payroll = $" << totalPayroll << "\n";

    std::cout << "\n--- what a struct actually costs in memory ---\n";
    std::cout << "sizeof(Employee) = " << sizeof(Employee)
              << " bytes  (roughly: a string object + an int + a double, plus\n"
              << "                    possible padding the compiler adds for alignment)\n";

    std::cout << "Assignment: " << isHigherPaid(staff[1], bob) << std::endl;

    return 0;
}

/*
   CHALLENGE: write a function `bool isHigherPaid(const Employee& a, const
   Employee& b)` that returns true if `a` earns more than `b`, and use it
   to find the highest-paid person in `staff` without hand-comparing
   .salary directly in main().
*/
