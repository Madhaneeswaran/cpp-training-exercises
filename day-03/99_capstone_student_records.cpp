// CAPSTONE: Student Record System
// Combines everything from today: struct, heap allocation managed by a
// smart pointer (RAII, no manual delete needed), date/time stamping,
// cerr for warnings, and manipulators for a clean formatted report.

#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <ctime>

struct Student {
    std::string name;
    double grade;
    std::string enrolledOn;
};

// Builds a "YYYY-MM-DD" timestamp for "right now" -- see 09_date_time.cpp.
std::string todayAsString() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    char buffer[16];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", localTime);
    return std::string(buffer);
}

// OUT-PARAMETERS via reference (Day 02!): one function, two results handed
// back without needing a second struct just to bundle them.
void computeStats(const std::unique_ptr<Student[]>& roster, int count,
                   double& outAverage, int& outTopIndex) {
    double total = 0.0;
    outTopIndex = 0;
    for (int i = 0; i < count; i++) {
        if (roster[i].grade < 0.0 || roster[i].grade > 100.0) {
            std::cerr << "WARNING: " << roster[i].name
                      << " has an out-of-range grade (" << roster[i].grade << ")\n";
        }
        total += roster[i].grade;
        if (roster[i].grade > roster[outTopIndex].grade) {
            outTopIndex = i;
        }
    }
    outAverage = total / count;
}

int main() {
    const int STUDENT_COUNT = 4;

    std::cout << "--- allocating the roster on the HEAP, owned by a smart pointer ---\n";
    // unique_ptr<Student[]> manages a heap array -- no delete[] needed
    // anywhere in this file. When `roster` goes out of scope at the end of
    // main(), the array is freed automatically (see 07_unique_ptr.cpp).
    std::unique_ptr<Student[]> roster = std::make_unique<Student[]>(STUDENT_COUNT);

    std::string enrollDate = todayAsString();
    roster[0] = {"Priya", 92.5, enrollDate};
    roster[1] = {"Arjun", 78.0, enrollDate};
    roster[2] = {"Zoya", 105.0, enrollDate};   // deliberately invalid -- watch for the cerr warning
    roster[3] = {"Kiran", 88.25, enrollDate};

    std::cout << "\n--- formatted report (manipulators doing the heavy lifting) ---\n";
    std::cout << std::left  << std::setw(10) << "Name"
              << std::right << std::setw(8)  << "Grade"
              << std::right << std::setw(14) << "Enrolled On" << "\n";
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < STUDENT_COUNT; i++) {
        std::cout << std::left  << std::setw(10) << roster[i].name
                  << std::right << std::setw(8)  << roster[i].grade
                  << std::right << std::setw(14) << roster[i].enrolledOn << "\n";
    }

    double average;
    int topIndex;
    computeStats(roster, STUDENT_COUNT, average, topIndex);

    std::cout << "\n--- summary ---\n";
    std::cout << "average grade: " << average << "\n";
    std::cout << "top student:   " << roster[topIndex].name << " (" << roster[topIndex].grade << ")\n";

    std::cout << "\n(no delete[] anywhere in this file -- 'roster' cleans itself up now)\n";
    return 0;
}

/*
   TRY IT:
     g++ -std=c++17 -Wall 99_capstone_student_records.cpp -o 99_capstone.exe
     ./99_capstone.exe

   Notice the WARNING for Zoya's invalid grade printed to cerr, separate
   from the normal report on cout -- redirect them independently to see it:
     ./99_capstone.exe 2> warnings.txt

   STRETCH GOALS (optional):
   1. Change `std::unique_ptr<Student[]>` to a raw `new Student[STUDENT_COUNT]`
      with a matching `delete[]` at the end, and confirm the program behaves
      identically -- this proves unique_ptr is automating exactly the
      new/delete pattern from 04_new_delete.cpp, not doing anything magic.
   2. Add a `std::shared_ptr<Student>` "class representative" that multiple
      parts of the program can point to, and print its use_count() at a few
      points (08_shared_weak_ptr.cpp).
   3. Reject (skip adding to the average) any student with an out-of-range
      grade instead of just warning about it.
*/
