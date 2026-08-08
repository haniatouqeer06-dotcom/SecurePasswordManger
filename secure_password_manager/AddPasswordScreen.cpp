#include"AddPasswordScreen.h"
#include<iostream>

using namespace std;

// constructor

AddPasswordScreen::AddPasswordScreen( sf::RenderWindow& window,PasswordManager& manager): window(window), passwordManager(manager)
{
    // Load required fonts
    regularFont.loadFromFile("assets/fonts/Goldman-Regular.ttf");

    boldFont.loadFromFile("assets/fonts/Goldman-Bold.ttf");
    // No input field is active initially
    websiteActive=false;
    usernameActive=false;
    passwordActive=false;

    // Start in Add Password mode
    editMode = false;
    oldWebsite = "";

    showCursor=true;

    cursor.setSize(sf::Vector2f(2.f,22.f));

    cursor.setFillColor(sf::Color::White);

    // Screen title
    title.setFont(boldFont);
    title.setString("ADD PASSWORD");
    title.setCharacterSize(34);
    title.setFillColor(sf::Color(56,189,248));
    title.setPosition(330.f,60.f);

    // --------------website section-----------
    // website label
    websiteLabel.setFont(regularFont);
    websiteLabel.setString("WEBSITE");
    websiteLabel.setCharacterSize(16);
    websiteLabel.setFillColor(sf::Color(226,232,240));
    websiteLabel.setPosition(250.f,150.f);

    // website input box
    websiteBox.setSize(sf::Vector2f(500.f,55.f));
    websiteBox.setPosition(250.f,180.f);
    websiteBox.setFillColor(sf::Color(23,32,51));
    websiteBox.setOutlineThickness(2.f);
    websiteBox.setOutlineColor(sf::Color(56,189,248));

    //placeholder text
    websiteText.setFont(regularFont);
    websiteText.setString("Enter Website");
    websiteText.setCharacterSize(18);
    websiteText.setFillColor(sf::Color(180,180,180));
    websiteText.setPosition(265.f,195.f);

    //---------------username section------------
    // username
    usernameLabel.setFont(regularFont);
    usernameLabel.setString("USERNAME");
    usernameLabel.setCharacterSize(16);
    usernameLabel.setFillColor(sf::Color(226,232,240));
    usernameLabel.setPosition(250.f,260.f);

    //username input box
    usernameBox.setSize(sf::Vector2f(500.f,55.f));
    usernameBox.setPosition(250.f,290.f);
    usernameBox.setFillColor(sf::Color(23,32,51));
    usernameBox.setOutlineThickness(2.f);
    usernameBox.setOutlineColor(sf::Color(56,189,248));

    //placeholder text
    usernameText.setFont(regularFont);
    usernameText.setString("Enter Username");
    usernameText.setCharacterSize(18);
    usernameText.setFillColor(sf::Color(180,180,180));
    usernameText.setPosition(265.f,305.f);

    // --------------password section----------
    //password label
    passwordLabel.setFont(regularFont);
    passwordLabel.setString("PASSWORD");
    passwordLabel.setCharacterSize(16);
    passwordLabel.setFillColor(sf::Color(226,232,240));
    passwordLabel.setPosition(250.f,370.f);

    // password input box
    passwordBox.setSize(sf::Vector2f(500.f,55.f));
    passwordBox.setPosition(250.f,400.f);
    passwordBox.setFillColor(sf::Color(23,32,51));
    passwordBox.setOutlineThickness(2.f);
    passwordBox.setOutlineColor(sf::Color(56,189,248));

    // password placeholder
    passwordText.setFont(regularFont);
    passwordText.setString("Enter Password");
    passwordText.setCharacterSize(18);
    passwordText.setFillColor(sf::Color(180,180,180));
    passwordText.setPosition(265.f,415.f);


    // ------------save button section---------
    saveButton.setSize(sf::Vector2f(180.f,55.f));
    saveButton.setPosition(300.f,510.f);
    saveButton.setFillColor(sf::Color(23,32,51));
    saveButton.setOutlineThickness(2.f);
    saveButton.setOutlineColor(sf::Color(56,189,248));

    saveText.setFont(regularFont);
    saveText.setString("SAVE");
    saveText.setCharacterSize(16);
    saveText.setFillColor(sf::Color(248,250,252));
    saveText.setPosition(365.f,527.f);


    //--------------backbutton section-----------
    backButton.setSize(sf::Vector2f(180.f,55.f));
    backButton.setPosition(520.f,510.f);
    backButton.setFillColor(sf::Color(23,32,51));
    backButton.setOutlineThickness(2.f);
    backButton.setOutlineColor(sf::Color(148,163,184));

    backText.setFont(regularFont);
    backText.setString("BACK");
    backText.setCharacterSize(16);
    backText.setFillColor(sf::Color(226,232,240));
    backText.setPosition(585.f,527.f);


    //--------------message shown after safe and update---------
    messageText.setFont(regularFont);
    messageText.setCharacterSize(16);
    messageText.setFillColor(sf::Color(56,189,248));
    messageText.setPosition(250.f,590.f);

}

//// Draw all objects on the screen
void AddPasswordScreen::draw()
{
    // Make the cursor blink after every 0.5 second
    if(cursorClock.getElapsedTime().asSeconds()>0.5f)
    {
        showCursor=!showCursor;
        cursorClock.restart();
    }

    // Draw screen title
    window.draw(title);

    // Draw field labels
    window.draw(websiteLabel);
    window.draw(usernameLabel);
    window.draw(passwordLabel);

    // Draw input boxes
    window.draw(websiteBox);
    window.draw(usernameBox);
    window.draw(passwordBox);

    // Draw entered text
    window.draw(websiteText);
    window.draw(usernameText);
    window.draw(passwordText);

    // Draw buttons
    window.draw(saveButton);
    window.draw(saveText);

    window.draw(backButton);
    window.draw(backText);

    // Draw message shown after save/update
    window.draw(messageText);

    // Draw cursor in the active text field
    if(showCursor)
    {
        // Cursor for website field
        if(websiteActive)
        {
            cursor.setPosition( websiteText.getPosition().x+websiteText.getGlobalBounds().width+2,websiteText.getPosition().y );
            
            window.draw(cursor);
        }

        // Cursor for username field
        if(usernameActive)
        {
            cursor.setPosition(usernameText.getPosition().x+usernameText.getGlobalBounds().width+2,usernameText.getPosition().y);

            window.draw(cursor);
        }

        // Cursor for password field
        if(passwordActive)
        {
            cursor.setPosition(passwordText.getPosition().x+passwordText.getGlobalBounds().width+2,passwordText.getPosition().y);

            window.draw(cursor);
        }
    }
}


// Handle keyboard input
void AddPasswordScreen::handleEvent(sf::Event& event)
{
    // Check if user typed a key
    if(event.type==sf::Event::TextEntered)
    {
        // Handle backspace
        if(event.text.unicode==8)
        {
            if(websiteActive && !website.empty())
                website.pop_back();

            else if(usernameActive && !username.empty())
                username.pop_back();

            else if(passwordActive && !password.empty())
                password.pop_back();
        }

        // Add typed character to the active field
        else if(event.text.unicode<128)
        {
            if(websiteActive)
                website+=static_cast<char>(event.text.unicode);

            else if(usernameActive)
                username+=static_cast<char>(event.text.unicode);

            else if(passwordActive)
                password+=static_cast<char>(event.text.unicode);
        }

        // Update website text
        if(website.empty())
        {
            websiteText.setString("Enter Website");
            websiteText.setFillColor(sf::Color(180,180,180));
        }
        else
        {
            websiteText.setString(website);
            websiteText.setFillColor(sf::Color::White);
        }

        // Update username text
        if(username.empty())
        {
            usernameText.setString("Enter Username");
            usernameText.setFillColor(sf::Color(180,180,180));
        }
        else
        {
            usernameText.setString(username);
            usernameText.setFillColor(sf::Color::White);
        }

        // Update password text
        if(password.empty())
        {
            passwordText.setString("Enter Password");
            passwordText.setFillColor(sf::Color(180,180,180));
        }
        else
        {
            // Hide password using '*' characters
            string hidden(password.length(),'*');

            passwordText.setString(hidden);
            passwordText.setFillColor(sf::Color::White);
        }
    }
}

// Handle mouse clicks on the screen
int AddPasswordScreen::handleClick(sf::Vector2f mousePosition)
{
    // Deactivate all input fields
    websiteActive = false;
    usernameActive = false;
    passwordActive = false;

    // Reset outline colors
    websiteBox.setOutlineColor(sf::Color(56,189,248));
    usernameBox.setOutlineColor(sf::Color(56,189,248));
    passwordBox.setOutlineColor(sf::Color(56,189,248));

    // Check if website box is clicked
    if(websiteBox.getGlobalBounds().contains(mousePosition))
    {
        websiteActive = true;
        websiteBox.setOutlineColor(sf::Color(0,255,255));
        return 0;
    }

    // Check if username box is clicked
    if(usernameBox.getGlobalBounds().contains(mousePosition))
    {
        usernameActive = true;
        usernameBox.setOutlineColor(sf::Color(0,255,255));
        return 0;
    }

    // Check if password box is clicked
    if(passwordBox.getGlobalBounds().contains(mousePosition))
    {
        passwordActive = true;
        passwordBox.setOutlineColor(sf::Color(0,255,255));
        return 0;
    }

    // Save button clicked
    if(saveButton.getGlobalBounds().contains(mousePosition))
    {
        return 1;
    }

    // Back button clicked
    if(backButton.getGlobalBounds().contains(mousePosition))
    {
        return 2;
    }

    // No button was clicked
    return 0;
}



// Save a new password or update an existing one
bool AddPasswordScreen::savePassword()
{
    // Check if any field is empty
    if(website.empty() || username.empty() || password.empty())
    {
        messageText.setFillColor(sf::Color(56,189,248));
        messageText.setString("Please fill all fields.");
        return false;
    }

    // Update password if edit mode is active
    if(editMode)
    {
        passwordManager.editPassword(
            oldWebsite,
            username,
            password
        );

        messageText.setString("Password Updated Successfully!");

        // Switch back to add mode
        editMode = false;
        oldWebsite = "";

        title.setString("ADD PASSWORD");
        saveText.setString("SAVE");
    }
    else
    {
        // Save a new password
        passwordManager.addPassword(
            website,
            username,
            password
        );

        messageText.setString("Password Saved Successfully!");
    }

    // Display success message in console
    cout << "Password Saved Successfully!" << endl;

    // Show success message on screen
    messageText.setFillColor(sf::Color(56,189,248));
    messageText.setString("Password Saved Successfully!");

    // Clear stored values
    website.clear();
    username.clear();
    password.clear();

    // Restore placeholder text
    websiteText.setString("Enter Website");
    usernameText.setString("Enter Username");
    passwordText.setString("Enter Password");

    // Change placeholder color back to grey
    websiteText.setFillColor(sf::Color(180,180,180));
    usernameText.setFillColor(sf::Color(180,180,180));
    passwordText.setFillColor(sf::Color(180,180,180));

    return true;
}


// Load existing password details for editing
void AddPasswordScreen::setEditData(PasswordEntry entry)
{
    // Enable edit mode
    editMode = true;

    // Store the original website name
    oldWebsite = entry.getWebsite();

    // Load existing data into input fields
    website = entry.getWebsite();
    username = entry.getUsername();
    password = entry.getPassword();

    // Display website
    websiteText.setString(website);
    websiteText.setFillColor(sf::Color::White);

    // Display username
    usernameText.setString(username);
    usernameText.setFillColor(sf::Color::White);

    // Hide password using '*' characters
    std::string hidden(password.length(), '*');
    passwordText.setString(hidden);
    passwordText.setFillColor(sf::Color::White);

    // Change heading for edit mode
    title.setString("EDIT PASSWORD");

    // Change button text
    saveText.setString("UPDATE");
}