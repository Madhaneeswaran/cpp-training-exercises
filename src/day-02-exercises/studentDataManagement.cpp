#include <iostream>
#include <memory>
#include <string>

struct Student {
    std::string name;
    int rollNumber;
    int rank;
};

void searchStudent(const Student students[], int size, const std::string& searchInput) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (students[i].name == searchInput) {
            std::cout << "Found: " << students[i].name
                    << ", Roll number: " << students[i].rollNumber
                    << ", Rank: " << students[i].rank << "\n";
            found = true;
            break;
        }
    }

    if (!found) std::cout << "Not Found" << '\n';
}

int main() {
    int numberOfStudents;
    std::cout << "Enter number of students :- ";
    std::cin >> numberOfStudents;
    std::string searchInput;

    std::unique_ptr<Student[]> students = std::make_unique<Student[]>(numberOfStudents);
    for (int i = 0; i < numberOfStudents; i++) {
        std::cin.ignore();

        std::cout << "Enter student " << i + 1 << " name" << '\n';
        std::getline(std::cin, students[i].name);

        std::cout << "Enter student " << i + 1 << " rollnumber" << '\n';
        std::cin >> students[i].rollNumber;

        std::cout << "Enter student " << i + 1 << " rank" << '\n';
        std::cin >> students[i].rank;
    }

    std::cin.ignore();
    std::cout << "Enter student name to search: ";
    std::getline(std::cin, searchInput);

    searchStudent(students.get(), numberOfStudents, searchInput);

    return 0;
}
