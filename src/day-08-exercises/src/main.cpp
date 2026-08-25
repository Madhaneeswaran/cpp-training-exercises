#include <iostream>
#include <memory>
#include "EmployeeManagementSystem.hpp"
#include "DerivedEmployees.hpp"
#include "AuthSystem.hpp"

int main() {
    AuthSystem auth;
    auto& ems = EmployeeManagementSystem::getInstance();

    try {
        std::cout << "Logging in as ROOT (Admin)...\n";
        UserSession adminSession = auth.login("root", "admin123");
        
        std::cout << "Logging in as ENGINEER...\n";
        UserSession engSession = auth.login("engineer", "eng123");

        // Admin adds employees
        ems.addEmployee(adminSession, std::make_shared<SoftwareEngineer>(101, "Alice", "Senior", 120000.0));
        ems.addEmployee(adminSession, std::make_shared<HardwareEngineer>(102, "Bob", "Lead", 135000.0, 10));
        ems.addEmployee(adminSession, std::make_shared<ManagementStaff>(103, "Charlie", "Manager", 150000.0));
        ems.addEmployee(adminSession, std::make_shared<SoftwareEngineer>(104, "Diana", "Junior", 80000.0));

        // Test Views & Authorization Rules (Salary hidden for engineers)
        std::cout << "\n[Engineer View] - Searching for ID 101 (Salary should be hidden):";
        ems.searchEmployeeById(engSession, 101);

        std::cout << "\n[Admin View] - Viewing all SW Engineers (Salary visible):";
        ems.viewByCategory(adminSession, EmployeeCategory::SoftwareEngineer);

        // Test Hardware Feature (Error 9001)
        std::cout << "\n[Testing HW Unit Check on Software Engineer]\n";
        try {
            auto swEng = ems.getEmployee(101);
            std::cout << "HW Count: " << swEng->getHardwareCount() << "\n";
        } catch (const EMSException& e) {
            std::cerr << "Caught Exception: " << e.what() << "\n";
        }

        std::cout << "\n[Testing HW Unit Check on Hardware Engineer]\n";
        auto hwEng = ems.getEmployee(102);
        std::cout << hwEng->getName() << " has " << hwEng->getHardwareCount() << " hardware units.\n";

        // Admin updates employee
        std::cout << "\n[Admin Action] Updating Diana to Senior...\n";
        ems.updatePosition(adminSession, 104, "Senior");
        ems.searchEmployeeById(adminSession, 104);

        // Engineer attempts to update (Error 9003)
        std::cout << "\n[Testing Engineer Unauthorized Update]\n";
        try {
            ems.updateSalary(engSession, 104, 100000.0);
        } catch (const EMSException& e) {
            std::cerr << "Caught Exception: " << e.what() << "\n";
        }

        // Test Missing ID (Error 9002)
        std::cout << "\n[Testing Missing ID Search]\n";
        try {
            ems.searchEmployeeById(adminSession, 999);
        } catch (const EMSException& e) {
            std::cerr << "Caught Exception: " << e.what() << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << "\n";
    }

    return 0;
}