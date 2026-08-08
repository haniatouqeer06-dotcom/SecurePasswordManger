#include "PasswordEntry.h"

// Default constructor
PasswordEntry::PasswordEntry()
{
    website = "";
    username = "";
    password = "";
}

// Parameterized constructor
PasswordEntry::PasswordEntry(string site, string user, string pass)
{
    website = site;
    username = user;
    password = pass;
}

// Set website
void PasswordEntry::setWebsite(string site)
{
    website = site;
}

// Set username
void PasswordEntry::setUsername(string user)
{
    username = user;
}

// Set password
void PasswordEntry::setPassword(string pass)
{
    password = pass;
}

// Get website
string PasswordEntry::getWebsite()
{
    return website;
}

// Get username
string PasswordEntry::getUsername()
{
    return username;
}

// Get password
string PasswordEntry::getPassword()
{
    return password;
}