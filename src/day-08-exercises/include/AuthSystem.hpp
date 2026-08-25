#ifndef AUTH_SYSTEM_HPP
#define AUTH_SYSTEM_HPP

#include <string>
#include <unordered_map>
#include "Exceptions.hpp"

enum class Role { ADMIN, ENGINEER, NONE };

struct UserSession {
    std::string username;
    Role role;
    bool isAuthenticated = false;
};

class AuthSystem {
private:
    std::unordered_map<std::string, std::pair<std::string, Role>> users;

public:
    AuthSystem();
    UserSession login(const std::string& username, const std::string& password);
    void checkAdminAccess(const UserSession& session) const;
};

#endif