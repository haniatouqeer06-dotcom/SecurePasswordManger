#include "loginScreen.h"
#include<iostream>

using namespace std;

// Constructor
loginPage::loginPage(sf::RenderWindow& window) : window(window)
{
    // Load fonts
    regularfont.loadFromFile("assets/fonts/Goldman-Regular.ttf");
    boldfont.loadFromFile("assets/fonts/Goldman-Bold.ttf");

    // Initially no input field is selected
    userActive = false;
    passwordActive = false;

    // Cursor is visible by default
    showCursor = true;

    // Screen title
    title.setFont(boldfont);
    title.setString("LOGIN");
    title.setCharacterSize(42);
    title.setFillColor(sf::Color(56, 189, 248));
    title.setPosition(410.f, 80.f);

    // Password label
    passwordLabel.setFont(regularfont);
    passwordLabel.setString("PASSWORD");
    passwordLabel.setCharacterSize(16);
    passwordLabel.setFillColor(sf::Color(226,232,240));
    passwordLabel.setPosition(300.f,300.f);

    // Username input box
    usernamebox.setSize(sf::Vector2f(400.f, 55.f));
    usernamebox.setPosition(300.f, 220.f);
    usernamebox.setFillColor(sf::Color(23, 32, 51));
    usernamebox.setOutlineThickness(2.f);
    usernamebox.setOutlineColor(sf::Color(56, 189, 248));

    // Username label
    userName.setFont(regularfont);
    userName.setString("USERNAME");
    userName.setCharacterSize(16);
    userName.setFillColor(sf::Color(226,232,240));
    userName.setPosition(300.f,190.f);

    // Username placeholder
    usernameText.setFont(regularfont);
    usernameText.setString("Enter Username");
    usernameText.setCharacterSize(18);
    usernameText.setFillColor(sf::Color(180,180,180));
    usernameText.setPosition(315.f,235.f);

    // Password input box
    passwordbox.setSize(sf::Vector2f(400.f, 55.f));
    passwordbox.setPosition(300.f, 330.f);
    passwordbox.setFillColor(sf::Color(23, 32, 51));
    passwordbox.setOutlineThickness(2.f);
    passwordbox.setOutlineColor(sf::Color(56, 189, 248));

    // Password placeholder
    passwordText.setFont(regularfont);
    passwordText.setCharacterSize(18);
    passwordText.setFillColor(sf::Color(248, 250, 252));
    passwordText.setPosition(315.f, 345.f);
    passwordText.setString("Enter Password");
    passwordText.setFillColor(sf::Color(180,180,180));

    // Login button
    loginbox.setSize(sf::Vector2f(180.f, 55.f));
    loginbox.setPosition(410.f, 440.f);
    loginbox.setFillColor(sf::Color(23, 32, 51));
    loginbox.setOutlineThickness(2.f);
    loginbox.setOutlineColor(sf::Color(56, 189, 248));

    // Login button text
    loginbutton.setFont(regularfont);
    loginbutton.setString("LOGIN");
    loginbutton.setCharacterSize(17);
    loginbutton.setFillColor(sf::Color(248, 250, 252));
    loginbutton.setPosition(465.f, 456.f);

    // Back button
    backbox.setSize(sf::Vector2f(120.f, 45.f));
    backbox.setPosition(440.f, 520.f);
    backbox.setFillColor(sf::Color(23, 32, 51));
    backbox.setOutlineThickness(2.f);
    backbox.setOutlineColor(sf::Color(148, 163, 184));

    // Back button text
    backgoundbutton.setFont(regularfont);
    backgoundbutton.setString("BACK");
    backgoundbutton.setCharacterSize(14);
    backgoundbutton.setFillColor(sf::Color(226, 232, 240));
    backgoundbutton.setPosition(478.f, 533.f);

    // Message shown after login attempt
    messagetxt.setFont(regularfont);
    messagetxt.setCharacterSize(14);
    messagetxt.setFillColor(sf::Color(248, 250, 252));
    messagetxt.setPosition(300.f, 590.f);

    // Blinking cursor
    cursor.setSize(sf::Vector2f(2.f,22.f));
    cursor.setFillColor(sf::Color::White);
}

// Draw all login screen components
void loginPage::draw()
{
    // Blink cursor every 0.5 seconds
    if(cursorClock.getElapsedTime().asSeconds() > 0.5f)
    {
        showCursor = !showCursor;
        cursorClock.restart();
    }

    // Draw screen heading
    window.draw(title);

    // Draw labels and input boxes
    window.draw(userName);
    window.draw(passwordLabel);
    window.draw(usernamebox);
    window.draw(passwordbox);

    // Draw entered text
    window.draw(usernameText);
    window.draw(passwordText);

    // Draw cursor in active field
    if(showCursor)
    {
        if(userActive)
        {
            cursor.setPosition(
                usernameText.getPosition().x +
                usernameText.getGlobalBounds().width + 2,
                usernameText.getPosition().y
            );

            window.draw(cursor);
        }

        if(passwordActive)
        {
            cursor.setPosition(
                passwordText.getPosition().x +
                passwordText.getGlobalBounds().width + 2,
                passwordText.getPosition().y
            );

            window.draw(cursor);
        }
    }

    // Draw buttons
    window.draw(loginbox);
    window.draw(loginbutton);

    window.draw(backbox);
    window.draw(backgoundbutton);

    // Draw status message
    window.draw(messagetxt);
}

// Handle keyboard input
void loginPage::handleevent(sf::Event& event)
{
    if (event.type == sf::Event::TextEntered)
    {
        // Handle backspace
        if (event.text.unicode == 8)
        {
            if (userActive && !user.empty())
            {
                user.pop_back();
            }
            else if (passwordActive && !password.empty())
            {
                password.pop_back();
            }
        }
        // Add typed character
        else if (event.text.unicode < 128)
        {
            if (userActive)
            {
                user += static_cast<char>(event.text.unicode);
            }
            else if (passwordActive)
            {
                password += static_cast<char>(event.text.unicode);
            }
        }

        // Update username field
        if(user.empty())
        {
            usernameText.setString("Enter Username");
            usernameText.setFillColor(sf::Color(180,180,180));
        }
        else
        {
            usernameText.setString(user);
            usernameText.setFillColor(sf::Color::White);
        }

        // Hide password using '*'
        if(password.empty())
        {
            passwordText.setString("Enter Password");
            passwordText.setFillColor(sf::Color(180,180,180));
        }
        else
        {
            std::string hiddenPassword(password.length(), '*');
            passwordText.setString(hiddenPassword);
            passwordText.setFillColor(sf::Color::White);
        }
    }
}

// Handle mouse clicks
int loginPage::handleclick(sf::Vector2f mousePosition)
{
    // Reset active fields
    userActive = false;
    passwordActive = false;

    usernamebox.setOutlineColor(sf::Color(56,189,248));
    passwordbox.setOutlineColor(sf::Color(56,189,248));

    // Username field selected
    if (usernamebox.getGlobalBounds().contains(mousePosition))
    {
        userActive = true;
        passwordActive = false;

        usernamebox.setOutlineColor(sf::Color(0,255,255));
        passwordbox.setOutlineColor(sf::Color(56,189,248));

        return 0;
    }

    // Password field selected
    if (passwordbox.getGlobalBounds().contains(mousePosition))
    {
        passwordActive = true;
        userActive = false;

        passwordbox.setOutlineColor(sf::Color(0,255,255));
        usernamebox.setOutlineColor(sf::Color(56,189,248));

        return 0;
    }

    // Login button clicked
    if (loginbox.getGlobalBounds().contains(mousePosition))
    {
        return 1;
    }

    // Back button clicked
    if (backbox.getGlobalBounds().contains(mousePosition))
    {
        return 2;
    }

    return 0;
}

// Return entered username
string loginPage::getUsername()
{
    return user;
}

// Return entered password
string loginPage::getPassword()
{
    return password;
}

// Verify user credentials
bool loginPage::loginUser()
{
    FileManager file;

    if(file.verifyUser(user,password))
    {
        messagetxt.setFillColor(sf::Color(56,189,248));
        messagetxt.setString("Login Successful!");

        cout<<"Login Successful!"<<endl;

        return true;
    }

    // Show message if login fails
    messagetxt.setFillColor(sf::Color(56,189,248));
    messagetxt.setString("Please Register First!");

    cout<<"User not registered."<<endl;

    return false;
}

// Return current username
string loginPage::getUserName()
{
    return user;
}