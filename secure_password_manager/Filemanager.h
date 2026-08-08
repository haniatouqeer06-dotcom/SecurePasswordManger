#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include "PasswordEntry.h"

using namespace std;

// FileManager handles all file operations
class FileManager
{
public:

    // Save new user data
    bool saveUser(string username, string password);

    // Check user login
    bool verifyUser(string username, string password);

    // Save password entry
    bool savePassword(string owner, PasswordEntry entry);

    // Load all passwords of a user
    vector<PasswordEntry> loadPasswords(string owner);

    // Delete password entry
    bool deletePassword(string owner, int index);

    // Update password entry
    bool updatePassword(string owner, int index, PasswordEntry newEntry);

    
    bool userExists(string username);
    bool deleteUser(string username);
};

#endif