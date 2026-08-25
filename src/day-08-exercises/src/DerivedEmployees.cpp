#include "DerivedEmployees.hpp"
#include <iostream>
#include <iomanip>

// Software Engineer
SoftwareEngineer::SoftwareEngineer(int id, std::string name, std::string position, double salary)
    : Employee(id, std::move(name), std::move(position), salary, EmployeeCategory::SoftwareEngineer) {}

void SoftwareEngineer::printDetails(bool showSalary) const {
    std::cout << "[SW Engineer] ID: " << id << " | Name: " << name << " | Position: " << position;
    if (showSalary) std::cout << " | Salary: $" << std::fixed << std::setprecision(2) << salary;
    std::cout << "\n";
}

// Hardware Engineer
HardwareEngineer::HardwareEngineer(int id, std::string name, std::string position, double salary, int units)
    : Employee(id, std::move(name), std::move(position), salary, EmployeeCategory::HardwareEngineer), hardwareUnits(units) {}

void HardwareEngineer::printDetails(bool showSalary) const {
    std::cout << "[HW Engineer] ID: " << id << " | Name: " << name << " | Position: " << position 
              << " | Hardware Units: " << hardwareUnits;
    if (showSalary) std::cout << " | Salary: $" << std::fixed << std::setprecision(2) << salary;
    std::cout << "\n";
}

int HardwareEngineer::getHardwareCount() const { return hardwareUnits; }
void HardwareEngineer::setHardwareCount(int count) { hardwareUnits = count; }

// Management Staff
ManagementStaff::ManagementStaff(int id, std::string name, std::string position, double salary)
    : Employee(id, std::move(name), std::move(position), salary, EmployeeCategory::Management) {}

void ManagementStaff::printDetails(bool showSalary) const {
    std::cout << "[Management]  ID: " << id << " | Name: " << name << " | Position: " << position;
    if (showSalary) std::cout << " | Salary: $" << std::fixed << std::setprecision(2) << salary;
    std::cout << "\n";
}