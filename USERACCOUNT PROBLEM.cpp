#include <iostream>
#include <string>

class UserAccount {
private:
    std::string username;
    bool isAdmin;
    static int adminCount; // Static variable to track the number of admin accounts

public:
    // Constructor
    UserAccount(const std::string& username, bool isAdmin = false) : username(username), isAdmin(isAdmin) {
        if (isAdmin) {
            adminCount++; // Increment adminCount if the account is an admin
        }
    }

    // Destructor
    ~UserAccount() {
        if (isAdmin) {
            adminCount--; // Decrement adminCount if the account is an admin
        }
    }

    // Static method to get the current number of admin accounts
    static int getAdminCount() {
        return adminCount;
    }

    // Getter for username
    std::string getUsername() const {
        return username;
    }

    // Getter for isAdmin
    bool getIsAdmin() const {
        return isAdmin;
    }
};

// Initialize the static variable
int UserAccount::adminCount = 0;

int main() {
    // Create some user accounts
    UserAccount user1("Alice");
    UserAccount user2("Bob", true); // Admin account
    UserAccount user3("Charlie", true); // Admin account

    // Print the number of admin accounts
    std::cout << "Number of admin accounts: " << UserAccount::getAdminCount() << std::endl;

    // Create another admin account
    UserAccount user4("Diana", true); // Admin account

    // Print the updated number of admin accounts
    std::cout << "Number of admin accounts: " << UserAccount::getAdminCount() << std::endl;

    return 0;
}