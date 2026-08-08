#include "PasswordManager.h"
#include "Encryption.h"
#include <fstream>
#include<iostream>
using namespace std;

//==================== DEFAULT CONSTRUCTOR ====================
// Creates an empty PasswordManager object
PasswordManager::PasswordManager()
{
    currentUsername = "";
}

//==================== PARAMETERIZED CONSTRUCTOR ====================
// Initializes PasswordManager with the current logged-in username
PasswordManager::PasswordManager(std::string username)
{
    currentUsername = username;
}

//==================== SET CURRENT USERNAME ====================
// Changes the current username
void PasswordManager::setCurrentUsername(
    std::string username
)
{
    currentUsername = username;
}

//==================== ADD PASSWORD ====================
// Creates a new password entry and saves it
void PasswordManager::addPassword(
    std::string website,
    std::string username,
    std::string password
)
{

    cout << "Current User = " << currentUsername << endl;
    cout << "Website = " << website << endl;
    cout << "Username = " << username << endl;
    cout << "Password = " << password << endl;
    // Create a new password object
    PasswordEntry newEntry(
        website,
        username,
        password
    );

    // Store it in the vector
    entries.push_back(newEntry);

    // Save updated data into file
    savePasswords();
}

//==================== DELETE PASSWORD ====================
// Deletes password using website name
bool PasswordManager::deletePassword(
    std::string website
)
{
    // Search all saved passwords
    for (int i = 0; i < entries.size(); i++)
    {
        // Check if website matches
        if (
            entries[i].getWebsite()
            ==
            website
        )
        {
            // Remove password from vector
            entries.erase(
                entries.begin() + i
            );

            // Save updated list
            savePasswords();

            return true;
        }
    }

    // Password not found
    return false;
}

//==================== EDIT PASSWORD ====================
// Updates username and password of an existing website
bool PasswordManager::editPassword(
    std::string website,
    std::string newUsername,
    std::string newPassword
)
{
    // Search the required website
    for (int i = 0; i < entries.size(); i++)
    {
        if (
            entries[i].getWebsite()
            ==
            website
        )
        {
            // Update username
            entries[i].setUsername(
                newUsername
            );

            // Update password
            entries[i].setPassword(
                newPassword
            );

            // Save changes
            savePasswords();

            return true;
        }
    }

    // Website not found
    return false;
}

//==================== SEARCH PASSWORD ====================
// Returns index of password if found
int PasswordManager::searchPassword(
    std::string website
)
{
    // Search every saved password
    for (int i = 0; i < entries.size(); i++)
    {
        if (
            entries[i].getWebsite()
            ==
            website
        )
        {
            // Return matching index
            return i;
        }
    }

    // Not found
    return -1;
}

//----------------------GET PASSWORD ----------------------
// Returns password entry at given index
PasswordEntry PasswordManager::getPassword(
    int index
)
{
    return entries[index];
}

//--------------------TOTAL PASSWORDS ---------------------
// Returns number of saved passwords
int PasswordManager::getTotalPasswords()
{
    return entries.size();
}

//--------------------- SAVE PASSWORDS ----------------------
// Saves all password entries into user's file
void PasswordManager::savePasswords()
{
    std::ofstream file(
        currentUsername + "_passwords.txt"
    );

    if (!file.is_open())
    {
        return;
    }

    Encryption encryption;

    for(int i = 0; i < entries.size(); i++)
    {
        std::string encryptedPassword =
            encryption.encrypt(
                entries[i].getPassword()
            );

        file
            << entries[i].getWebsite()
            << "|"
            << entries[i].getUsername()
            << "|"
            << encryptedPassword
            << "\n";
    }

    file.close();
}

//---------------------LOAD PASSWORDS ----------------------
// Loads passwords from file into vector
void PasswordManager::loadPasswords()
{
    entries.clear();

    std::ifstream file(
        currentUsername + "_passwords.txt"
    );

    if(!file.is_open())
    {
        std::ofstream createFile(
            currentUsername + "_passwords.txt"
        );

        createFile.close();
        return;
    }

    Encryption encryption;

    std::string website;
    std::string username;
    std::string encryptedPassword;

    while(
        getline(file, website, '|') &&
        getline(file, username, '|') &&
        getline(file, encryptedPassword)
    )
    {
        std::string decryptedPassword =
            encryption.decrypt(
                encryptedPassword
            );

        entries.push_back(
            PasswordEntry(
                website,
                username,
                decryptedPassword
            )
        );
    }

    file.close();
}

//----------------------- GET CURRENT USERNAME -----------------------
// Returns username of logged-in user
std::string PasswordManager::getCurrentUsername()
{
    return currentUsername;
}