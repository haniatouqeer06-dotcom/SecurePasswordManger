#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

// User class stores registered user information
class User
{
private:
    string username;
    string password;

public:
    // Default constructor
    User();

    // Parameterized constructor
    User(string user, string pass);

    // Set username
    void setUsername(string user);

    // Set password
    void setPassword(string pass);

    // Get username
    string getUsername();

    // Get password
    string getPassword();
};

#endif