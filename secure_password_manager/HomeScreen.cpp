#include "HomeScreen.h"

// Constructor
HomePage::HomePage(sf::RenderWindow& window) : window(window)
{
    // Load application fonts
    regularFont.loadFromFile("assets/fonts/Goldman-Regular.ttf");
    boldFont.loadFromFile("assets/fonts/Goldman-Bold.ttf");

    // Display application name
    applicationName.setFont(regularFont);
    applicationName.setString("SECURE VAULT");
    applicationName.setCharacterSize(18);
    applicationName.setFillColor(sf::Color(148, 163, 184));
    applicationName.setPosition(40.f, 25.f);

    // Main welcome heading
    welcomeText.setFont(boldFont);
    welcomeText.setString("WELCOME");
    welcomeText.setCharacterSize(58);
    welcomeText.setFillColor(sf::Color(56, 189, 248));
    welcomeText.setPosition(80.f, 190.f);

    // Subtitle below heading
    subtitleText.setFont(regularFont);
    subtitleText.setString("SECURE PASSWORD MANAGER");
    subtitleText.setCharacterSize(22);
    subtitleText.setFillColor(sf::Color(226, 232, 240));
    subtitleText.setPosition(85.f, 285.f);

    // Short application description
    descriptionText.setFont(regularFont);
    descriptionText.setString("PROTECT. MANAGE. SECURE.");
    descriptionText.setCharacterSize(14);
    descriptionText.setFillColor(sf::Color(148, 163, 184));
    descriptionText.setPosition(85.f, 340.f);

    // Login button
    loginButton.setSize(sf::Vector2f(220.f, 60.f));
    loginButton.setPosition(650.f, 240.f);
    loginButton.setFillColor(sf::Color(23, 32, 51));
    loginButton.setOutlineThickness(2.f);
    loginButton.setOutlineColor(sf::Color(56, 189, 248));

    // Login button text
    loginText.setFont(regularFont);
    loginText.setString("LOGIN");
    loginText.setCharacterSize(18);
    loginText.setFillColor(sf::Color(248, 250, 252));
    loginText.setPosition(730.f, 258.f);

    // Register button
    registerButton.setSize(sf::Vector2f(220.f, 60.f));
    registerButton.setPosition(650.f, 340.f);
    registerButton.setFillColor(sf::Color(23, 32, 51));
    registerButton.setOutlineThickness(2.f);
    registerButton.setOutlineColor(sf::Color(56, 189, 248));

    // Register button text
    registerText.setFont(regularFont);
    registerText.setString("REGISTER");
    registerText.setCharacterSize(18);
    registerText.setFillColor(sf::Color(248, 250, 252));
    registerText.setPosition(708.f, 358.f);

    // Decorative line below heading
    leftLine.setSize(sf::Vector2f(120.f, 3.f));
    leftLine.setPosition(85.f, 270.f);
    leftLine.setFillColor(sf::Color(56, 189, 248));

    // Decorative line above login button
    loginTopLine.setSize(sf::Vector2f(220.f, 2.f));
    loginTopLine.setPosition(650.f, 215.f);
    loginTopLine.setFillColor(sf::Color(56, 189, 248));

    // Decorative line below register button
    registerBottomLine.setSize(sf::Vector2f(220.f, 2.f));
    registerBottomLine.setPosition(650.f, 425.f);
    registerBottomLine.setFillColor(sf::Color(56, 189, 248));
}

// Draw all objects on the home screen
void HomePage::draw()
{
    window.draw(applicationName);
    window.draw(welcomeText);
    window.draw(subtitleText);
    window.draw(descriptionText);

    window.draw(loginButton);
    window.draw(loginText);

    window.draw(registerButton);
    window.draw(registerText);

    window.draw(leftLine);
    window.draw(loginTopLine);
    window.draw(registerBottomLine);
}

// Check which button is clicked
int HomePage::handleClick(sf::Vector2f mousePosition)
{
    // Login button clicked
    if (loginButton.getGlobalBounds().contains(mousePosition))
    {
        return 1;
    }

    // Register button clicked
    if (registerButton.getGlobalBounds().contains(mousePosition))
    {
        return 2;
    }

    // No button clicked
    return 0;
}