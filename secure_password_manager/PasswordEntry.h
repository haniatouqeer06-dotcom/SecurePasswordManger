#ifndef PASSWORDENTRY_H
#define PASSWORDENTRY_H

#include <string>
using namespace std;

// PasswordEntry class stores individual password records
class PasswordEntry
{
private:
    string website;
    string username;
    string password;

public:
    // Default constructor
    PasswordEntry();

    // Parameterized constructor
    PasswordEntry(string site, string user, string pass);

    // Setters
    void setWebsite(string site);
    void setUsername(string user);
    void setPassword(string pass);

    // Getters
    string getWebsite();
    string getUsername();
    string getPassword();
    
};

#endif