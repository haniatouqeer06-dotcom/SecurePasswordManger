#include "RegisterScreen.h"
#include "PasswordManager.h"
#include<iostream>
using namespace std;

RegisterScreen::RegisterScreen(sf::RenderWindow& window) : window(window)
{
    //----- Load Fonts -----

    regularFont.loadFromFile("assets/fonts/Goldman-Regular.ttf");
    boldFont.loadFromFile("assets/fonts/Goldman-Bold.ttf");


    //----- Initialize Active Fields -----

    nameActive = false;
    usernameActive = false;
    passwordActive = false;
    confirmPasswordActive = false;


    //----- Cursor Settings -----

    showCursor = true;

    cursor.setSize(sf::Vector2f(2.f,22.f));
    cursor.setFillColor(sf::Color::White);


    //----- Register Screen Title -----

    title.setFont(boldFont);
    title.setString("REGISTER");
    title.setCharacterSize(38);
    title.setFillColor(sf::Color(56, 189, 248));
    title.setPosition(390.f, 35.f);


    //----- Full Name Label -----

    nameLabel.setFont(regularFont);
    nameLabel.setString("FULL NAME");
    nameLabel.setCharacterSize(14);
    nameLabel.setFillColor(sf::Color(226, 232, 240));
    nameLabel.setPosition(300.f, 110.f);


    //----- Full Name Input Box -----

    nameBox.setSize(sf::Vector2f(400.f, 45.f));
    nameBox.setPosition(300.f, 135.f);
    nameBox.setFillColor(sf::Color(23, 32, 51));
    nameBox.setOutlineThickness(2.f);
    nameBox.setOutlineColor(sf::Color(56, 189, 248));


    //----- Full Name Text -----

    nameText.setFont(regularFont);
    nameText.setCharacterSize(16);
    nameText.setFillColor(sf::Color(248, 250, 252));
    nameText.setPosition(315.f, 147.f);


    //----- Username Label -----

    usernameLabel.setFont(regularFont);
    usernameLabel.setString("USERNAME");
    usernameLabel.setCharacterSize(14);
    usernameLabel.setFillColor(sf::Color(226, 232, 240));
    usernameLabel.setPosition(300.f, 195.f);


    //----- Username Input Box -----

    usernameBox.setSize(sf::Vector2f(400.f, 45.f));
    usernameBox.setPosition(300.f, 220.f);
    usernameBox.setFillColor(sf::Color(23, 32, 51));
    usernameBox.setOutlineThickness(2.f);
    usernameBox.setOutlineColor(sf::Color(56, 189, 248));


    //----- Username Text -----

    usernameText.setFont(regularFont);
    usernameText.setCharacterSize(16);
    usernameText.setFillColor(sf::Color(248, 250, 252));
    usernameText.setPosition(315.f, 232.f);


    //----- Password Label -----

    passwordLabel.setFont(regularFont);
    passwordLabel.setString("PASSWORD");
    passwordLabel.setCharacterSize(14);
    passwordLabel.setFillColor(sf::Color(226, 232, 240));
    passwordLabel.setPosition(300.f, 280.f);


    //----- Password Input Box -----

    passwordBox.setSize(sf::Vector2f(400.f, 45.f));
    passwordBox.setPosition(300.f, 305.f);
    passwordBox.setFillColor(sf::Color(23, 32, 51));
    passwordBox.setOutlineThickness(2.f);
    passwordBox.setOutlineColor(sf::Color(56, 189, 248));


    //----- Password Text -----

    passwordText.setFont(regularFont);
    passwordText.setCharacterSize(16);
    passwordText.setFillColor(sf::Color(248, 250, 252));
    passwordText.setPosition(315.f, 317.f);


    //----- Confirm Password Label -----

    confirmPasswordLabel.setFont(regularFont);
    confirmPasswordLabel.setString("CONFIRM PASSWORD");
    confirmPasswordLabel.setCharacterSize(14);
    confirmPasswordLabel.setFillColor(sf::Color(226, 232, 240));
    confirmPasswordLabel.setPosition(300.f, 365.f);


    //----- Confirm Password Input Box -----

    confirmPasswordBox.setSize(sf::Vector2f(400.f, 45.f));
    confirmPasswordBox.setPosition(300.f, 390.f);
    confirmPasswordBox.setFillColor(sf::Color(23, 32, 51));
    confirmPasswordBox.setOutlineThickness(2.f);
    confirmPasswordBox.setOutlineColor(sf::Color(56, 189, 248));


    //----- Confirm Password Text -----

    confirmPasswordText.setFont(regularFont);
    confirmPasswordText.setCharacterSize(16);
    confirmPasswordText.setFillColor(sf::Color(248, 250, 252));
    confirmPasswordText.setPosition(315.f, 402.f);


    //----- Register Button -----

    registerButton.setSize(sf::Vector2f(180.f, 50.f));
    registerButton.setPosition(410.f, 465.f);
    registerButton.setFillColor(sf::Color(23, 32, 51));
    registerButton.setOutlineThickness(2.f);
    registerButton.setOutlineColor(sf::Color(56, 189, 248));


    //----- Register Button Text -----

    registerButtonText.setFont(regularFont);
    registerButtonText.setString("REGISTER");
    registerButtonText.setCharacterSize(16);
    registerButtonText.setFillColor(sf::Color(248, 250, 252));
    registerButtonText.setPosition(450.f, 479.f);


    //----- Back Button -----

    backButton.setSize(sf::Vector2f(120.f, 40.f));
    backButton.setPosition(440.f, 535.f);
    backButton.setFillColor(sf::Color(23, 32, 51));
    backButton.setOutlineThickness(2.f);
    backButton.setOutlineColor(sf::Color(148, 163, 184));


    //----- Back Button Text -----

    backButtonText.setFont(regularFont);
    backButtonText.setString("BACK");
    backButtonText.setCharacterSize(14);
    backButtonText.setFillColor(sf::Color(226, 232, 240));
    backButtonText.setPosition(478.f, 546.f);


    //----- Message Text -----

    messageText.setFont(regularFont);
    messageText.setCharacterSize(13);
    messageText.setFillColor(sf::Color(248, 250, 252));
    messageText.setPosition(300.f, 595.f);
}

void RegisterScreen::draw()
{
    //---------------- Cursor Blink ----------------

    if(cursorClock.getElapsedTime().asSeconds() > 0.5f)
    {
        showCursor = !showCursor;
        cursorClock.restart();
    }

    //---------------- Title ----------------

    window.draw(title);

    //---------------- Name Field ----------------

    window.draw(nameLabel);
    window.draw(nameBox);
    window.draw(nameText);

    //---------------- Username Field ----------------

    window.draw(usernameLabel);
    window.draw(usernameBox);
    window.draw(usernameText);

    //---------------- Password Field ----------------

    window.draw(passwordLabel);
    window.draw(passwordBox);
    window.draw(passwordText);

    //---------------- Confirm Password Field ----------------

    window.draw(confirmPasswordLabel);
    window.draw(confirmPasswordBox);
    window.draw(confirmPasswordText);

    //---------------- Draw Cursor ----------------

    if(showCursor)
    {
        // Cursor in Name Field
        if(nameActive)
        {
            cursor.setPosition(
                nameText.getPosition().x +
                nameText.getGlobalBounds().width + 2,
                nameText.getPosition().y
            );

            window.draw(cursor);
        }

        // Cursor in Username Field
        if(usernameActive)
        {
            cursor.setPosition(
                usernameText.getPosition().x +
                usernameText.getGlobalBounds().width + 2,
                usernameText.getPosition().y
            );

            window.draw(cursor);
        }

        // Cursor in Password Field
        if(passwordActive)
        {
            cursor.setPosition(
                passwordText.getPosition().x +
                passwordText.getGlobalBounds().width + 2,
                passwordText.getPosition().y
            );

            window.draw(cursor);
        }

        // Cursor in Confirm Password Field
        if(confirmPasswordActive)
        {
            cursor.setPosition(
                confirmPasswordText.getPosition().x +
                confirmPasswordText.getGlobalBounds().width + 2,
                confirmPasswordText.getPosition().y
            );

            window.draw(cursor);
        }
    }

    //---------------- Register Button ----------------

    window.draw(registerButton);
    window.draw(registerButtonText);

    //---------------- Back Button ----------------

    window.draw(backButton);
    window.draw(backButtonText);

    //---------------- Message ----------------

    window.draw(messageText);
}

void RegisterScreen::handleEvent(sf::Event& event)
{
    // Checks if the user has typed any key
    if (event.type == sf::Event::TextEntered)
    {
        // Handles Backspace key
        if (event.text.unicode == 8)
        {
            // Removes the last character from the active field
            if (nameActive && !name.empty())
                name.pop_back();
            else if (usernameActive && !username.empty())
                username.pop_back();
            else if (passwordActive && !password.empty())
                password.pop_back();
            else if (confirmPasswordActive && !confirmPassword.empty())
                confirmPassword.pop_back();
        }

        // Adds typed character to the active text field
        else if (event.text.unicode < 128)
        {
            if (nameActive)
                name += static_cast<char>(event.text.unicode);
            else if (usernameActive)
                username += static_cast<char>(event.text.unicode);
            else if (passwordActive)
                password += static_cast<char>(event.text.unicode);
            else if (confirmPasswordActive)
                confirmPassword += static_cast<char>(event.text.unicode);
        }

        // Updates the Full Name field
        if(name.empty())
        {
            // Displays placeholder when empty
            nameText.setString("Enter Name");
            nameText.setFillColor(sf::Color(180,180,180));
        }
        else
        {
            // Displays entered name
            nameText.setString(name);
            nameText.setFillColor(sf::Color::White);
        }

        // Updates the Username field
        if(username.empty())
        {
            // Displays placeholder when empty
            usernameText.setString("Enter Username");
            usernameText.setFillColor(sf::Color(180,180,180));
        }
        else
        {
            // Displays entered username
            usernameText.setString(username);
            usernameText.setFillColor(sf::Color::White);
        }

        // Creates hidden password using '*' characters
        std::string hiddenPassword(password.length(), '*');

        // Updates the Password field
        if(password.empty())
        {
            // Displays placeholder when empty
            passwordText.setString("Enter Password");
            passwordText.setFillColor(sf::Color(180,180,180));
        }
        else
        {
            // Displays hidden password
            passwordText.setString(hiddenPassword);
            passwordText.setFillColor(sf::Color::White);
        }

        // Creates hidden confirm password using '*' characters
        std::string hiddenConfirmPassword(confirmPassword.length(), '*');

        // Updates the Confirm Password field
        if(confirmPassword.empty())
        {
            // Displays placeholder when empty
            confirmPasswordText.setString("Confirm Password");
            confirmPasswordText.setFillColor(sf::Color(180,180,180));
        }
        else
        {
            // Displays hidden confirm password
            confirmPasswordText.setString(hiddenConfirmPassword);
            confirmPasswordText.setFillColor(sf::Color::White);
        }
    }
}

int RegisterScreen::handleClick(sf::Vector2f mousePosition)
{
    // Reset all active input fields
    nameActive = false;
    usernameActive = false;
    passwordActive = false;
    confirmPasswordActive = false;

    // Restore default outline color for all input boxes
    nameBox.setOutlineColor(sf::Color(56,189,248));
    usernameBox.setOutlineColor(sf::Color(56,189,248));
    passwordBox.setOutlineColor(sf::Color(56,189,248));
    confirmPasswordBox.setOutlineColor(sf::Color(56,189,248));

    // Check if the Name box is clicked
    if (nameBox.getGlobalBounds().contains(mousePosition))
    {
        // Activate the Name field
        nameActive = true;

        // Highlight the selected input box
        nameBox.setOutlineColor(sf::Color(0,255,255));

        return 0;
    }

    // Check if the Username box is clicked
    if (usernameBox.getGlobalBounds().contains(mousePosition))
    {
        // Activate the Username field
        usernameActive = true;

        // Highlight the selected input box
        usernameBox.setOutlineColor(sf::Color(0,255,255));

        return 0;
    }

    // Check if the Password box is clicked
    if (passwordBox.getGlobalBounds().contains(mousePosition))
    {
        // Activate the Password field
        passwordActive = true;

        // Highlight the selected input box
        passwordBox.setOutlineColor(sf::Color(0,255,255));

        return 0;
    }

    // Check if the Confirm Password box is clicked
    if (confirmPasswordBox.getGlobalBounds().contains(mousePosition))
    {
        // Activate the Confirm Password field
        confirmPasswordActive = true;

        // Highlight the selected input box
        confirmPasswordBox.setOutlineColor(sf::Color(0,255,255));

        return 0;
    }

    // Check if the Register button is clicked
    if (registerButton.getGlobalBounds().contains(mousePosition))
    {
        // Return 1 to start the registration process
        return 1;
    }

    // Check if the Back button is clicked
    if (backButton.getGlobalBounds().contains(mousePosition))
    {
        // Return 2 to go back to the previous screen
        return 2;
    }

    // No valid button or input box was clicked
    return 0;
}


bool RegisterScreen::registerUser()
{
    // Check if any required field is empty
    if(name.empty() || username.empty() || password.empty() || confirmPassword.empty())
    {
        messageText.setFillColor(sf::Color::Red);
        messageText.setString("Please fill all fields.");
        return false;
    }

    // Check whether both passwords match
    if(password != confirmPassword)
    {
        messageText.setFillColor(sf::Color::Red);
        messageText.setString("Passwords do not match.");
        return false;
    }

    // Create a FileManager object to handle file operations
    FileManager file;

    // Check if the username is already registered
    if(file.userExists(username))
    {
        messageText.setString("Username Already Registered!");
        cout << "Error: Username already exists." << endl;
        return false;
    }

    // Save the new user information
    if(file.saveUser(username, password))
    {

        // Create an empty password file for the new user
        PasswordManager manager(username);
        manager.savePasswords();
        // Show success message
        messageText.setFillColor(sf::Color::Green);
        messageText.setString("Registration Successful!");

        cout << "Registration Successful!" << endl;
        cout << "User account created successfully." << endl;

        // Clear all stored input data
        // name.clear();
        // username.clear();
        // password.clear();
        // confirmPassword.clear();

        // // Clear all text fields on the screen
        // nameText.setString("");
        // usernameText.setString("");
        // passwordText.setString("");
        // confirmPasswordText.setString("");

        return true;
    }

    // Display an error message if registration fails
    messageText.setFillColor(sf::Color::Red);
    messageText.setString("Registration Failed.");

    return false;
}

string RegisterScreen::getName()
{
    // Return the user's full name
    return name;
}

string RegisterScreen::getUserName()
{
    // Return the entered username
    return username;
}

string RegisterScreen::getPassword()
{
    // Return the entered password
    return password;
}