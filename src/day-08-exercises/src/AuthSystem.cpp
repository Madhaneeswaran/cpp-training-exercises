#include "AuthSystem.hpp"

AuthSystem::AuthSystem() {
    // In-memory Hardcoded Credentials
    users["root"] = {"admin123", Role::ADMIN};
    users["manager"] = {"boss123", Role::ADMIN};
    users["engineer"] = {"eng123", Role::ENGINEER};
}

UserSession AuthSystem::login(const std::string& username, const std::string& password) {
    auto it = users.find(username);
    if (it != users.end() && it->second.first == password) {
        return {username, it->second.second, true};
    }
    throw UnauthorizedAccessException(); // Error 9003
}

void AuthSystem::checkAdminAccess(const UserSession& session) const {
    if (!session.isAuthenticated || session.role != Role::ADMIN) {
        throw UnauthorizedAccessException(); // Error 9003
    }
}