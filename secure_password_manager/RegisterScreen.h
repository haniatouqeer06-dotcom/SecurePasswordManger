#ifndef REGISTERSCREEN_H
#define REGISTERSCREEN_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Filemanager.h"

class RegisterScreen
{
private:
    sf::RenderWindow& window;

    sf::Font regularFont;
    sf::Font boldFont;

    sf::Text title;
    sf::Text nameLabel;
    sf::Text usernameLabel;
    sf::Text passwordLabel;
    sf::Text confirmPasswordLabel;

    sf::Text nameText;
    sf::Text usernameText;
    sf::Text passwordText;
    sf::Text confirmPasswordText;

    sf::Text registerButtonText;
    sf::Text backButtonText;
    sf::Text messageText;

    sf::RectangleShape nameBox;
    sf::RectangleShape usernameBox;
    sf::RectangleShape passwordBox;
    sf::RectangleShape confirmPasswordBox;

    sf::RectangleShape registerButton;
    sf::RectangleShape backButton;

    bool nameActive;
    bool usernameActive;
    bool passwordActive;
    bool confirmPasswordActive;

    std::string name;
    std::string username;
    std::string password;
    std::string confirmPassword;

    sf::Clock cursorClock;
    bool showCursor;
    sf::RectangleShape cursor;

public:
    RegisterScreen(sf::RenderWindow& window);

    void draw();
    void handleEvent(sf::Event& event);
    int handleClick(sf::Vector2f mousePosition);
    bool registerUser();
    string getName();
    string getUserName();
    string getPassword();
};

#endif