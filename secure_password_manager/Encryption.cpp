#include "Encryption.h"

// Constructor
Encryption::Encryption()
{
    // Set Caesar Cipher shift value
    shift = 3;
}

// Encrypt the given text
string Encryption::encrypt(string text)
{
    string result = "";

    // Check every character
    for (char c : text)
    {
        // Encrypt only alphabet characters
        if (isalpha(c))
        {
            // Check whether character is uppercase or lowercase
            char base = isupper(c) ? 'A' : 'a';

            // Shift the character forward
            c = (c - base + shift) % 26 + base;
        }

        // Store encrypted character
        result += c;
    }

    // Return encrypted text
    return result;
}

// Decrypt the given text
string Encryption::decrypt(string text)
{
    string result = "";

    // Check every character
    for (char c : text)
    {
        // Decrypt only alphabet characters
        if (isalpha(c))
        {
            // Check whether character is uppercase or lowercase
            char base = isupper(c) ? 'A' : 'a';

            // Shift the character backward
            c = (c - base - shift + 26) % 26 + base;
        }

        // Store decrypted character
        result += c;
    }

    // Return original text
    return result;
}