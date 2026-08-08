#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include <vector>
#include <string>
#include "PasswordEntry.h"

// Handles all password-related operations
class PasswordManager
{
private:

    // Stores all password entries of the current user
    std::vector<PasswordEntry> entries;

    // Username of the currently logged-in user
    std::string currentUsername;

public:

    // Default constructor
    PasswordManager();

    // Constructor to initialize current username
    PasswordManager(std::string username);

    // Sets the current logged-in username
    void setCurrentUsername(std::string username);

    // Adds a new password entry
    void addPassword(
        std::string website,
        std::string username,
        std::string password
    );

    // Deletes a password using website name
    bool deletePassword(std::string website);

    // Updates username and password for a website
    bool editPassword(
        std::string website,
        std::string newUsername,
        std::string newPassword
    );

    // Searches a password and returns its index
    int searchPassword(std::string website);

    // Returns a password entry at the given index
    PasswordEntry getPassword(int index);

    // Returns total number of saved passwords
    int getTotalPasswords();

    // Loads passwords from the user's file
    void loadPasswords();

    // Saves all passwords into the user's file
    void savePasswords();

    // Returns the username of the current user
    std::string getCurrentUsername();
};

#endif