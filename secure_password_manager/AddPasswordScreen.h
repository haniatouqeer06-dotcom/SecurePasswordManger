#ifndef ADDPASSWORDSCREEN_H
#define ADDPASSWORDSCREEN_H

#include <SFML/Graphics.hpp>
#include <string>
#include "PasswordManager.h"

using namespace std;

class AddPasswordScreen
{
private:

    // Main application window
    sf::RenderWindow& window;

    // Reference to password manager
    PasswordManager& passwordManager;

    // Fonts used on this screen
    sf::Font regularFont;
    sf::Font boldFont;

    // Screen heading
    sf::Text title;

    // Labels for input fields
    sf::Text websiteLabel;
    sf::Text usernameLabel;
    sf::Text passwordLabel;

    // Text displayed inside input boxes
    sf::Text websiteText;
    sf::Text usernameText;
    sf::Text passwordText;

    // Button text
    sf::Text saveText;
    sf::Text backText;

    // Message shown after save/update
    sf::Text messageText;

    // Input boxes
    sf::RectangleShape websiteBox;
    sf::RectangleShape usernameBox;
    sf::RectangleShape passwordBox;

    // Buttons
    sf::RectangleShape saveButton;
    sf::RectangleShape backButton;

    // Track which input field is active
    bool websiteActive;
    bool usernameActive;
    bool passwordActive;

    // Used for blinking cursor
    sf::Clock cursorClock;
    bool showCursor;
    sf::RectangleShape cursor;

    // Store user input
    string website;
    string username;
    string password;

    // Variables used while editing a password
    bool editMode;
    string oldWebsite;

public:

    // Constructor
    AddPasswordScreen(
        sf::RenderWindow& window,
        PasswordManager& manager
    );

    // Draw all screen elements
    void draw();

    // Handle keyboard input
    void handleEvent(sf::Event& event);

    // Handle mouse clicks
    int handleClick(sf::Vector2f mousePosition);

    // Save or update password
    bool savePassword();

    // Load password details for editing
    void setEditData(PasswordEntry entry);
};

#endif