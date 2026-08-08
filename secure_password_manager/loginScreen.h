#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Filemanager.h"

using namespace std;

class loginPage
{
private:

    // Main application window
    sf::RenderWindow& window;

    // Fonts used on the login screen
    sf::Font regularfont;
    sf::Font boldfont;

    // Text objects
    sf::Text title;
    sf::Text userName;
    sf::Text passwordLabel;
    sf::Text usernameText;
    sf::Text passwordText;
    sf::Text loginbutton;
    sf::Text backgoundbutton;
    sf::Text messagetxt;

    // Input boxes and buttons
    sf::RectangleShape usernamebox;
    sf::RectangleShape passwordbox;
    sf::RectangleShape loginbox;
    sf::RectangleShape backbox;
    sf::RectangleShape cursor;

    // Track which input field is active
    bool userActive;
    bool passwordActive;

    // Used to create blinking cursor effect
    sf::Clock cursorClock;
    bool showCursor;

    // Store entered username and password
    std::string user;
    std::string password;

public:

    // Constructor
    loginPage(sf::RenderWindow& window);

    // Draw all screen components
    void draw();

    // Handle keyboard input
    void handleevent(sf::Event& event);

    // Handle mouse clicks
    int handleclick(sf::Vector2f mousePosition);

    // Return entered username
    string getUsername();

    // Return entered password
    string getPassword();

    // Verify user login
    bool loginUser();

    // Return current username
    string getUserName();
};

#endif