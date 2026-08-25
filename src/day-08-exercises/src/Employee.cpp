#include "Employee.hpp"
#include <iostream>

Employee::Employee(int id, std::string name, std::string position, double salary, EmployeeCategory category)
    : id(id), name(std::move(name)), position(std::move(position)), salary(salary), category(category) {}

int Employee::getId() const { return id; }
std::string Employee::getName() const { return name; }
std::string Employee::getPosition() const { return position; }
double Employee::getSalary() const { return salary; }
EmployeeCategory Employee::getCategory() const { return category; }

void Employee::setPosition(const std::string& newPosition) { position = newPosition; }
void Employee::setSalary(double newSalary) { salary = newSalary; }

int Employee::getHardwareCount() const {
    throw UnauthorizedHardwareException(); // Error 9001
}

void Employee::setHardwareCount(int) {
    throw UnauthorizedHardwareException(); // Error 9001
}