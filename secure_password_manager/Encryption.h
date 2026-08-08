#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
using namespace std;

// Encryption class handles Caesar Cipher encryption/decryption
class Encryption
{
private:
    int shift;

public:
    // Constructor
    Encryption();

    // Encrypt text
    string encrypt(string text);

    // Decrypt text
    string decrypt(string text);
};

#endif