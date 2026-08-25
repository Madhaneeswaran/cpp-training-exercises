#include "EmployeeManagementSystem.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <algorithm>

EmployeeManagementSystem::EmployeeManagementSystem() : logger("ems_events") {
    logger.log(LogLevel::INFO, "Employee Management System Initialized.");
}

EmployeeManagementSystem& EmployeeManagementSystem::getInstance() {
    static EmployeeManagementSystem instance;
    return instance;
}

void EmployeeManagementSystem::addEmployee(const UserSession& session, std::shared_ptr<Employee> emp) {
    AuthSystem().checkAdminAccess(session);
    
    if (employees.find(emp->getId()) != employees.end()) {
        logger.log(LogLevel::ERROR, "Failed to add: Employee ID " + std::to_string(emp->getId()) + " exists.");
        throw std::invalid_argument("Employee ID already exists");
    }
    
    employees[emp->getId()] = emp;
    logger.log(LogLevel::INFO, "Added employee: " + emp->getName());
}

void EmployeeManagementSystem::removeEmployee(const UserSession& session, int id) {
    AuthSystem().checkAdminAccess(session);
    
    auto it = employees.find(id);
    if (it == employees.end()) {
        logger.log(LogLevel::ERROR, "Failed to remove: Employee ID " + std::to_string(id) + " not found.");
        throw EmployeeNotFoundException(); // Error 9002
    }
    
    std::string name = it->second->getName();
    employees.erase(it); // Smart pointer cleans up memory automatically
    logger.log(LogLevel::INFO, "Removed employee: " + name);
}

void EmployeeManagementSystem::updatePosition(const UserSession& session, int id, const std::string& newPosition) {
    AuthSystem().checkAdminAccess(session);
    
    auto emp = getEmployee(id);
    emp->setPosition(newPosition);
    logger.log(LogLevel::INFO, "Updated position for ID " + std::to_string(id) + " to " + newPosition);
}

void EmployeeManagementSystem::updateSalary(const UserSession& session, int id, double newSalary) {
    AuthSystem().checkAdminAccess(session);
    
    auto emp = getEmployee(id);
    emp->setSalary(newSalary);
    logger.log(LogLevel::INFO, "Updated salary for ID " + std::to_string(id));
}

void EmployeeManagementSystem::viewByCategory(const UserSession& session, EmployeeCategory category) const {
    if (!session.isAuthenticated) throw UnauthorizedAccessException();
    bool showSalary = (session.role == Role::ADMIN);

    std::vector<std::shared_ptr<Employee>> filtered;
    filtered.reserve(employees.size()); // Memory Check: Vector efficiency

    for (const auto& [id, emp] : employees) { // Memory Check: Using const auto&
        if (emp->getCategory() == category) {
            filtered.push_back(emp);
        }
    }

    std::cout << "\n--- Employees in Category ---\n";
    for (const auto& emp : filtered) {
        emp->printDetails(showSalary);
    }
}

void EmployeeManagementSystem::viewByPosition(const UserSession& session, const std::string& position) const {
    if (!session.isAuthenticated) throw UnauthorizedAccessException();
    bool showSalary = (session.role == Role::ADMIN);

    std::cout << "\n--- Employees with Position: " << position << " ---\n";
    for (const auto& [id, emp] : employees) {
        if (emp->getPosition() == position) {
            emp->printDetails(showSalary);
        }
    }
}

void EmployeeManagementSystem::viewTotalEmployees(const UserSession& session) const {
    if (!session.isAuthenticated) throw UnauthorizedAccessException();
    std::cout << "Total Employees: " << employees.size() << "\n";
}

void EmployeeManagementSystem::searchEmployeeById(const UserSession& session, int id) const {
    if (!session.isAuthenticated) throw UnauthorizedAccessException();
    
    auto emp = getEmployee(id);
    emp->printDetails(session.role == Role::ADMIN);
}

std::shared_ptr<Employee> EmployeeManagementSystem::getEmployee(int id) const {
    auto it = employees.find(id);
    if (it == employees.end()) {
        throw EmployeeNotFoundException(); // Error 9002
    }
    return it->second;
}