#ifndef EMPLOYEE_MANAGEMENT_SYSTEM_HPP
#define EMPLOYEE_MANAGEMENT_SYSTEM_HPP

#include <map>
#include <memory>
#include <vector>
#include "Employee.hpp"
#include "AuthSystem.hpp"
#include "Logger.hpp"

// Compile-safe Singleton
class EmployeeManagementSystem {
private:
    std::map<int, std::shared_ptr<Employee>> employees;
    EventLogger logger;

    // Private constructor for Singleton
    EmployeeManagementSystem();
    ~EmployeeManagementSystem() = default;

    // Prevent copies
    EmployeeManagementSystem(const EmployeeManagementSystem&) = delete;
    EmployeeManagementSystem& operator=(const EmployeeManagementSystem&) = delete;

public:
    static EmployeeManagementSystem& getInstance();

    // Admin Operations
    void addEmployee(const UserSession& session, std::shared_ptr<Employee> emp);
    void removeEmployee(const UserSession& session, int id);
    void updatePosition(const UserSession& session, int id, const std::string& newPosition);
    void updateSalary(const UserSession& session, int id, double newSalary);

    // View Operations (Available to all authenticated users)
    void viewByCategory(const UserSession& session, EmployeeCategory category) const;
    void viewByPosition(const UserSession& session, const std::string& position) const;
    void viewTotalEmployees(const UserSession& session) const;
    void searchEmployeeById(const UserSession& session, int id) const;
    
    // Quick access wrapper
    std::shared_ptr<Employee> getEmployee(int id) const;
};

#endif