#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <SFML/Graphics.hpp>

class HomePage
{
private:

    // Main application window
    sf::RenderWindow& window;


    // Fonts
    sf::Font regularFont;
    sf::Font boldFont;


    // Text objects
    sf::Text welcomeText;
    sf::Text subtitleText;
    sf::Text descriptionText;
    sf::Text applicationName;


    // Login button
    sf::RectangleShape loginButton;
    sf::Text loginText;


    // Register button
    sf::RectangleShape registerButton;
    sf::Text registerText;


    // Decorative lines
    sf::RectangleShape leftLine;
    sf::RectangleShape loginTopLine;
    sf::RectangleShape registerBottomLine;


public:

    // Constructor
    HomePage(sf::RenderWindow& window);


    // Draw complete home page
    void draw();
    int handleClick(sf::Vector2f mousePosition);
};

#endif