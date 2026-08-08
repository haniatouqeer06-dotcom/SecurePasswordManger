#include "User.h"

// Default constructor
User::User()
{
    username = "";
    password = "";
}

// Parameterized constructor
User::User(string user, string pass)
{
    username = user;
    password = pass;
}

// Set username
void User::setUsername(string user)
{
    username = user;
}

// Set password
void User::setPassword(string pass)
{
    password = pass;
}

// Get username
string User::getUsername()
{
    return username;
}

// Get password
string User::getPassword()
{
    return password;
}