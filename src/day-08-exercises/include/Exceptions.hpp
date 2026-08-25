#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

class EMSException : public std::runtime_error {
protected:
    int errorCode;
public:
    EMSException(int code, const std::string& msg) 
        : std::runtime_error("Error " + std::to_string(code) + ": " + msg), errorCode(code) {}
    
    int getCode() const { return errorCode; }
};

class DuplicateInstanceException : public EMSException {
public:
    DuplicateInstanceException() : EMSException(9000, "Duplicate instance of EMS attempted") {}
};

class UnauthorizedHardwareException : public EMSException {
public:
    UnauthorizedHardwareException() : EMSException(9001, "Unauthorized hardware count access") {}
};

class EmployeeNotFoundException : public EMSException {
public:
    EmployeeNotFoundException() : EMSException(9002, "Employee ID not found") {}
};

class UnauthorizedAccessException : public EMSException {
public:
    UnauthorizedAccessException() : EMSException(9003, "Unauthorized access attempt") {}
};

#endif