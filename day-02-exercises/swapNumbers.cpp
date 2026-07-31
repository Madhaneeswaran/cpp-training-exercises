#include <iostream>

void swapNumbers(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;

    std::cout << "Before swapping :- " << x << '\t' << y << std::endl;

    swapNumbers(x, y);

    std::cout << "After swapping :- " << x << '\t' << y << std::endl;
}

// #include <iostream>
// #include <string>

// struct Student {
//     std::string name;
//     double rollNumber;
//     int rank;
// };

// void searchStudent(const Student students[], int size, const std::string& searchInput) {
//     bool found = false;
//     for (int i = 0; i < size; i++) {
//         if (students[i].name == searchInput) {
//             std::cout << "Found: " << students[i].name
//                     << ", Roll " << students[i].rollNumber
//                     << ", Rank " << students[i].rank << "\n";
//             found = true;
//             break;
//         }
//     }

//     if (!found) std::cout << "Not Found" << '\n';
// }

// int main() {
//     int numberOfStudents;
//     std::cout << "Enter number of students: ";
//     std::cin >> numberOfStudents;

//     // dynamic memory allocation: size decided at runtime, not compile time
//     Student* students = new Student[numberOfStudents];

//     for (int i = 0; i < numberOfStudents; i++) {
//         std::cin.ignore(); // discard leftover '\n' from the previous input
//         std::cout << "Enter name for student " << i + 1 << ": ";
//         std::getline(std::cin, students[i].name);

//         std::cout << "Enter roll number for student " << i + 1 << ": ";
//         std::cin >> students[i].rollNumber;

//         std::cout << "Enter rank for student " << i + 1 << ": ";
//         std::cin >> students[i].rank;
//     }

//     std::cin.ignore();
//     std::string searchInput;
//     std::cout << "Enter student name to search: ";
//     std::getline(std::cin, searchInput);

//     searchStudent(students, numberOfStudents, searchInput);

//     delete[] students; // must match new[] with delete[]
// }
