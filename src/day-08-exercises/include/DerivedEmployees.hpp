#ifndef DERIVED_EMPLOYEES_HPP
#define DERIVED_EMPLOYEES_HPP

#include "Employee.hpp"

class SoftwareEngineer : public Employee {
public:
    SoftwareEngineer(int id, std::string name, std::string position, double salary);
    void printDetails(bool showSalary) const override;
};

class HardwareEngineer : public Employee {
private:
    int hardwareUnits;
public:
    HardwareEngineer(int id, std::string name, std::string position, double salary, int units = 5);
    void printDetails(bool showSalary) const override;
    
    int getHardwareCount() const override;
    void setHardwareCount(int count) override;
};

class ManagementStaff : public Employee {
public:
    ManagementStaff(int id, std::string name, std::string position, double salary);
    void printDetails(bool showSalary) const override;
};

#endif