#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>
#include "Exceptions.hpp"

enum class EmployeeCategory { SoftwareEngineer, HardwareEngineer, Management };

class Employee {
protected:
    int id;
    std::string name;
    std::string position;
    double salary;
    EmployeeCategory category;

public:
    Employee(int id, std::string name, std::string position, double salary, EmployeeCategory category);
    virtual ~Employee() = default;

    int getId() const;
    std::string getName() const;
    std::string getPosition() const;
    double getSalary() const;
    EmployeeCategory getCategory() const;

    void setPosition(const std::string& newPosition);
    void setSalary(double newSalary);

    virtual void printDetails(bool showSalary) const = 0;

    // Requirement 2: Throws 9001 if not overridden by HardwareEngineer
    virtual int getHardwareCount() const;
    virtual void setHardwareCount(int count);
};

#endif