#include "Filemanager.h"
#include <fstream>
#include <sstream>

// Save a new user's login information
bool FileManager::saveUser(string username, string password)
{
    // Open file in append mode
    ofstream file("users.txt", ios::app);

    // Return false if file cannot be opened
    if (!file)
        return false;

    // Save username and password
    file << username << " " << password << endl;

    file.close();
    return true;
}


// Check if username and password are correct
bool FileManager::verifyUser(string username, string password)
{
    ifstream file("users.txt");

    string user;
    string pass;

    // Read all saved users
    while (file >> user >> pass)
    {
        // Login successful
        if (user == username && pass == password)
        {
            file.close();
            return true;
        }
    }

    file.close();

    // Login failed
    return false;
}


// Save a password entry for the current user
bool FileManager::savePassword(string owner, PasswordEntry entry)
{
    // Open password file in append mode
    ofstream file("passwords.txt", ios::app);

    if (!file)
        return false;

    // Store owner, website, username and password
    file << owner << "|"
         << entry.getWebsite() << "|"
         << entry.getUsername() << "|"
         << entry.getPassword()
         << endl;

    file.close();

    return true;
}


// Load all passwords of a specific user
vector<PasswordEntry> FileManager::loadPasswords(string owner)
{
    vector<PasswordEntry> passwords;

    ifstream file("passwords.txt");

    string line;

    // Read file line by line
    while (getline(file, line))
    {
        stringstream ss(line);

        string user;
        string website;
        string username;
        string password;

        // Split data using '|'
        getline(ss, user, '|');
        getline(ss, website, '|');
        getline(ss, username, '|');
        getline(ss, password, '|');

        // Store only current user's passwords
        if (user == owner)
        {
            PasswordEntry entry(
                website,
                username,
                password
            );

            passwords.push_back(entry);
        }
    }

    file.close();

    return passwords;
}


// Delete a password from the list
bool FileManager::deletePassword(string owner, int index)
{
    // Load all passwords
    vector<PasswordEntry> passwords = loadPasswords(owner);

    // Check if index is valid
    if (index < 0 || index >= passwords.size())
        return false;

    // Remove selected password
    passwords.erase(passwords.begin() + index);

    // Rewrite updated data
    ofstream file("passwords.txt");

    for (PasswordEntry p : passwords)
    {
        file << owner << "|"
             << p.getWebsite() << "|"
             << p.getUsername() << "|"
             << p.getPassword()
             << endl;
    }

    file.close();

    return true;
}


// Update an existing password entry
bool FileManager::updatePassword(string owner, int index, PasswordEntry newEntry)
{
    // Load all passwords
    vector<PasswordEntry> passwords = loadPasswords(owner);

    // Check if index is valid
    if (index < 0 || index >= passwords.size())
        return false;

    // Replace old password with new one
    passwords[index] = newEntry;

    // Save updated list
    ofstream file("passwords.txt");

    for (PasswordEntry p : passwords)
    {
        file << owner << "|"
             << p.getWebsite() << "|"
             << p.getUsername() << "|"
             << p.getPassword()
             << endl;
    }

    file.close();

    return true;
}


// Check whether a username already exists
bool FileManager::userExists(string username)
{
    ifstream file("users.txt");

    if(!file)
    {
        return false;
    }

    string fileUsername;
    string filePassword;

    // Read every user from file
    while(file >> fileUsername >> filePassword)
    {
        if(fileUsername == username)
        {
            file.close();
            return true;
        }
    }

    file.close();

    return false;
}


// Delete a user account from users file
bool FileManager::deleteUser(string username)
{
    ifstream file("users.txt");

    if(!file)
    {
        return false;
    }

    // Temporary file to store remaining users
    ofstream temp("temp.txt");

    string fileUsername;
    string filePassword;

    bool found = false;

    // Copy every user except the one being deleted
    while(file >> fileUsername >> filePassword)
    {
        if(fileUsername == username)
        {
            found = true;
        }
        else
        {
            temp << fileUsername << " "
                 << filePassword << endl;
        }
    }

    file.close();
    temp.close();

    // Replace old file with updated file
    remove("users.txt");
    rename("temp.txt", "users.txt");

    return found;
}