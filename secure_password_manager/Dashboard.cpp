#include "Dashboard.h"
#include "Filemanager.h"
#include<iostream>
using namespace std;

// Constructor
Dashboard::Dashboard( sf::RenderWindow& window, std::string username ) : window(window), passwordManager(username)
{
    // Load fonts
    regularFont.loadFromFile("assets/fonts/Goldman-Regular.ttf");

    boldFont.loadFromFile("assets/fonts/Goldman-Bold.ttf");

    // Initialize variables
    searchActive = false;
    selectedPassword = -1;
    showPasswordDetails = false;
    searchActive = false;
    showSearchCursor = true;

    // Load saved passwords
    passwordManager.setCurrentUsername(username);
    passwordManager.loadPasswords();
    refreshPasswords();

    // Dashboard title
    title.setFont(boldFont);
    title.setString("SECURE VAULT");
    title.setCharacterSize(30);
    title.setFillColor(sf::Color(56, 189, 248));
    title.setPosition(40.f, 30.f);

    // Welcome text
    welcomeText.setFont(regularFont);
    welcomeText.setString("PASSWORD DASHBOARD");
    welcomeText.setCharacterSize(18);
    welcomeText.setFillColor(sf::Color(226, 232, 240));
    welcomeText.setPosition(40.f, 80.f);

    // Search box
    searchBox.setSize(sf::Vector2f(400.f, 50.f));
    searchBox.setPosition(120.f,140.f);
    searchBox.setFillColor(sf::Color(23, 32, 51));
    searchBox.setOutlineThickness(2.f);
    searchBox.setOutlineColor(sf::Color(56, 189, 248));

    // Search placeholder
    searchText.setFont(regularFont);
    searchText.setCharacterSize(16);
    searchText.setFillColor(sf::Color(248, 250, 252));
    searchText.setPosition(140.f,156.f);
    searchText.setString("Search Password...");
    searchText.setFillColor(sf::Color(170,170,170));

    // Add Password button
    addButton.setSize(sf::Vector2f(180.f, 50.f));
    addButton.setPosition(760.f,140.f);
    addButton.setFillColor(sf::Color(23, 32, 51));
    addButton.setOutlineThickness(2.f);
    addButton.setOutlineColor(sf::Color(56, 189, 248));

    addButtonText.setFont(regularFont);
    addButtonText.setString("ADD PASSWORD");
    addButtonText.setCharacterSize(14);
    addButtonText.setFillColor(sf::Color(248, 250, 252));
    addButtonText.setPosition(790.f,156.f);

    // Delete account button
    deleteButton.setSize(sf::Vector2f(170.f,45.f));
    deleteButton.setPosition(530.f,30.f);

    deleteButton.setFillColor(sf::Color(23,32,51));
    deleteButton.setOutlineThickness(2.f);
    deleteButton.setOutlineColor(sf::Color(148,163,184));

    deleteText.setFont(regularFont);
    deleteText.setString("DELETE ACCOUNT");
    deleteText.setCharacterSize(13);
    deleteText.setFillColor(sf::Color(226,232,240));
    deleteText.setPosition(545.f,44.f);

    // Back button
    backButton.setSize(sf::Vector2f(120.f,45.f));
    backButton.setPosition(720.f,30.f);

    backButton.setFillColor(sf::Color(23,32,51));
    backButton.setOutlineThickness(2.f);
    backButton.setOutlineColor(sf::Color(148,163,184));

    backText.setFont(regularFont);
    backText.setString("BACK");
    backText.setCharacterSize(14);
    backText.setFillColor(sf::Color(226,232,240));
    backText.setPosition(757.f,44.f);

    // Logout button
    logoutButton.setSize(sf::Vector2f(120.f,45.f));
    logoutButton.setPosition(860.f,30.f);

    logoutButton.setFillColor(sf::Color(23,32,51));
    logoutButton.setOutlineThickness(2.f);
    logoutButton.setOutlineColor(sf::Color(148,163,184));

    logoutText.setFont(regularFont);
    logoutText.setString("LOGOUT");
    logoutText.setCharacterSize(14);
    logoutText.setFillColor(sf::Color(226,232,240));
    logoutText.setPosition(892.f,44.f);

    // Status message
    messageText.setFont(regularFont);
    messageText.setCharacterSize(18);
    messageText.setFillColor(sf::Color(56,189,248));
    messageText.setPosition(300.f,320.f);

    // Close button for popup
    closeButton.setSize(sf::Vector2f(35.f,35.f));
    closeButton.setFillColor(sf::Color(220,60,60));
    closeButton.setPosition(680.f,190.f);

    closeText.setFont(regularFont);
    closeText.setCharacterSize(20);
    closeText.setFillColor(sf::Color::White);
    closeText.setString("X");
    closeText.setPosition(692.f,196.f);

    // Empty dashboard message
    emptyTitle.setFont(regularFont);
    emptyTitle.setCharacterSize(28);
    emptyTitle.setFillColor(sf::Color::White);
    emptyTitle.setString("No Passwords Saved Yet");

    // Hide delete popup initially
    showDeletePopup = false;

    // Delete confirmation popup
    popupBox.setSize(sf::Vector2f(420.f,180.f));
    popupBox.setPosition(290.f,220.f);
    popupBox.setFillColor(sf::Color(20,28,45));
    popupBox.setOutlineThickness(2);
    popupBox.setOutlineColor(sf::Color(56,189,248));

    popupText.setFont(regularFont);
    popupText.setCharacterSize(22);
    popupText.setFillColor(sf::Color::White);
    popupText.setString("Delete Password?");
    popupText.setPosition(370.f,245.f);

    // YES button
    yesButton.setSize(sf::Vector2f(120.f,45.f));
    yesButton.setPosition(340.f,320.f);
    yesButton.setFillColor(sf::Color::Transparent);
    yesButton.setOutlineThickness(2);
    yesButton.setOutlineColor(sf::Color(34,197,94));

    yesText.setFont(regularFont);
    yesText.setCharacterSize(16);
    yesText.setString("YES");
    yesText.setFillColor(sf::Color(34,197,94));
    yesText.setPosition(383.f,333.f);

    // NO button
    noButton.setSize(sf::Vector2f(120.f,45.f));
    noButton.setPosition(540.f,320.f);
    noButton.setFillColor(sf::Color::Transparent);
    noButton.setOutlineThickness(2);
    noButton.setOutlineColor(sf::Color(239,68,68));

    noText.setFont(regularFont);
    noText.setCharacterSize(16);
    noText.setString("NO");
    noText.setFillColor(sf::Color(239,68,68));
    noText.setPosition(590.f,333.f);

    // Center empty message
    float titleX = (1000.f - emptyTitle.getGlobalBounds().width) / 2.f;
    emptyTitle.setPosition(titleX, 290.f);

    emptySubtitle.setFont(regularFont);
    emptySubtitle.setCharacterSize(18);
    emptySubtitle.setFillColor(sf::Color(170,170,170));
    emptySubtitle.setString("Click 'Add Password' to get started.");

    float subtitleX = (1000.f - emptySubtitle.getGlobalBounds().width) / 2.f;
    emptySubtitle.setPosition(subtitleX, 340.f);

    // Create password cards
    for(int i=0; i<100; i++)
    {
        float y = 250.f + i * 120.f;

        // Card background
        passwordCards[i].setSize(sf::Vector2f(920.f,100.f));
        passwordCards[i].setPosition(40.f,y);
        passwordCards[i].setFillColor(sf::Color(20,28,45));
        passwordCards[i].setOutlineThickness(2.f);
        passwordCards[i].setOutlineColor(sf::Color(56,189,248));

        // Website text
        websiteTexts[i].setFont(regularFont);
        websiteTexts[i].setCharacterSize(20);
        websiteTexts[i].setFillColor(sf::Color::White);
        websiteTexts[i].setPosition(60.f,y+15);

        // Username text
        usernameTexts[i].setFont(regularFont);
        usernameTexts[i].setCharacterSize(16);
        usernameTexts[i].setFillColor(sf::Color(180,180,180));
        usernameTexts[i].setPosition(60.f,y+50);

        // View button
        viewButtons[i].setSize(sf::Vector2f(90.f,35.f));
        viewButtons[i].setPosition(610.f,y+30);

        viewButtons[i].setFillColor(sf::Color::Transparent);
        viewButtons[i].setOutlineThickness(2.f);
        viewButtons[i].setOutlineColor(sf::Color(34,197,94));

        viewTexts[i].setFont(regularFont);
        viewTexts[i].setString("VIEW");
        viewTexts[i].setCharacterSize(14);
        viewTexts[i].setFillColor(sf::Color(170,255,150));
        viewTexts[i].setPosition(635.f,y+38);

        // Edit button
        editButtons[i].setSize(sf::Vector2f(90.f,35.f));
        editButtons[i].setPosition(720.f,y+30);

        editButtons[i].setFillColor(sf::Color::Transparent);
        editButtons[i].setOutlineThickness(2.f);
        editButtons[i].setOutlineColor(sf::Color(245,158,11));

        editTexts[i].setFont(regularFont);
        editTexts[i].setString("EDIT");
        editTexts[i].setCharacterSize(14);
        editTexts[i].setFillColor(sf::Color(255,215,70));
        editTexts[i].setPosition(747.f,y+38);

        // Delete button
        deleteButtons[i].setSize(sf::Vector2f(100.f,35.f));
        deleteButtons[i].setPosition(830.f,y+30);

        deleteButtons[i].setFillColor(sf::Color::Transparent);
        deleteButtons[i].setOutlineThickness(2.f);
        deleteButtons[i].setOutlineColor(sf::Color(239,68,68));

        deleteTexts[i].setFont(regularFont);
        deleteTexts[i].setString("DELETE");
        deleteTexts[i].setCharacterSize(14);
        deleteTexts[i].setFillColor(sf::Color(255,95,80));
        deleteTexts[i].setPosition(845.f,y+38);
    }

    // Default website text settings
    for(int i=0;i<100;i++)
    {
        websiteTexts[i].setFont(regularFont);
        websiteTexts[i].setCharacterSize(18);
        websiteTexts[i].setFillColor(sf::Color::White);

        websiteTexts[i].setPosition(
            40.f,
            240.f + i*45.f
        );
    }

    // Initially show all passwords
    for(int i = 0; i < passwordManager.getTotalPasswords(); i++)
    {
        searchResults.push_back(i);
    }

    // Save default view
    dashboardView = window.getDefaultView();

    // Initial scroll position
    scrollOffset = 0.f;
}

void Dashboard::draw()
{
    // Apply scrolling view
    window.setView(dashboardView);

    // Draw dashboard heading
    window.draw(title);
    window.draw(welcomeText);

    // Draw search bar
    window.draw(searchBox);
    window.draw(searchText);

    // Blink the search cursor
    if(searchCursorClock.getElapsedTime().asSeconds() > 0.5f)
    {
        showSearchCursor = !showSearchCursor;
        searchCursorClock.restart();
    }

    // Draw cursor only when search box is active
    if(searchActive && showSearchCursor)
    {
        sf::RectangleShape cursor;

        cursor.setSize(sf::Vector2f(2.f,22.f));
        cursor.setFillColor(sf::Color::White);

        cursor.setPosition(
            searchText.getPosition().x +
            searchText.getGlobalBounds().width + 3,
            searchText.getPosition().y
        );

        window.draw(cursor);
    }

    // Draw top navigation buttons
    window.draw(addButton);
    window.draw(addButtonText);

    window.draw(deleteButton);
    window.draw(deleteText);

    window.draw(backButton);
    window.draw(backText);

    window.draw(logoutButton);
    window.draw(logoutText);

    // Show empty message if no passwords exist
    if(passwordManager.getTotalPasswords()==0)
    {
        window.draw(emptyTitle);
        window.draw(emptySubtitle);
    }
    else
    {
        // Draw all passwords when search box is empty
        if(searchInput.empty())
        {
            for(int i=0; i<passwordManager.getTotalPasswords(); i++)
            {
                window.draw(passwordCards[i]);

                window.draw(websiteTexts[i]);
                window.draw(usernameTexts[i]);

                window.draw(viewButtons[i]);
                window.draw(viewTexts[i]);

                window.draw(editButtons[i]);
                window.draw(editTexts[i]);

                window.draw(deleteButtons[i]);
                window.draw(deleteTexts[i]);
            }
        }
        // Draw only matching passwords after searching
        else
        {
            for(int k=0; k<searchResults.size(); k++)
            {
                int i = searchResults[k];

                window.draw(passwordCards[i]);

                window.draw(websiteTexts[i]);
                window.draw(usernameTexts[i]);

                window.draw(viewButtons[i]);
                window.draw(viewTexts[i]);

                window.draw(editButtons[i]);
                window.draw(editTexts[i]);

                window.draw(deleteButtons[i]);
                window.draw(deleteTexts[i]);
            }
        }
    }

    // Display status messages
    window.draw(messageText);

    // Show password details popup
    if(showPasswordDetails && selectedPassword != -1)
    {
        PasswordEntry entry =
            passwordManager.getPassword(selectedPassword);

        sf::RectangleShape popup;
        popup.setSize(sf::Vector2f(450.f,220.f));
        popup.setPosition(270.f,180.f);
        popup.setFillColor(sf::Color(20,28,45));
        popup.setOutlineThickness(2.f);
        popup.setOutlineColor(sf::Color(56,189,248));

        sf::Text info;
        info.setFont(regularFont);
        info.setCharacterSize(18);
        info.setFillColor(sf::Color::White);

        info.setString(
            "Website : " + entry.getWebsite() +
            "\n\nUsername : " + entry.getUsername() +
            "\n\nPassword : " + entry.getPassword()
        );

        info.setPosition(300.f,220.f);

        window.draw(popup);
        window.draw(info);

        window.draw(closeButton);
        window.draw(closeText);
    }

    // Restore the default view for fixed UI elements
    window.setView(window.getDefaultView());

    // Draw delete confirmation popup
    if(showDeletePopup)
    {
        window.draw(popupBox);

        window.draw(popupText);

        window.draw(yesButton);
        window.draw(noButton);

        window.draw(yesText);
        window.draw(noText);
    }
}


void Dashboard::handleEvent(sf::Event& event)
{
    // Handle typing inside the search bar
    if(event.type == sf::Event::TextEntered)
    {
        if(searchActive)
        {
            // Remove last character on Backspace
            if(event.text.unicode == 8)
            {
                if(!searchInput.empty())
                    searchInput.pop_back();
            }
            // Add typed character
            else if(event.text.unicode < 128)
            {
                searchInput += static_cast<char>(event.text.unicode);
            }

            // Restore placeholder when search box is empty
            if(searchInput.empty())
            {
                searchText.setString("Search Password...");
                searchText.setFillColor(sf::Color(170,170,170));

                searchResults.clear();
            }
            else
            {
                // Display the typed text
                searchText.setString(searchInput);
                searchText.setFillColor(sf::Color::White);

                // Update matching search results
                searchResults.clear();

                if(searchInput.empty())
                {
                    for(int i=0;i<passwordManager.getTotalPasswords();i++)
                    {
                        searchResults.push_back(i);
                    }
                }
                else
                {
                    // Find passwords whose website matches the search
                    for(int i=0;i<passwordManager.getTotalPasswords();i++)
                    {
                        if(passwordManager.getPassword(i).getWebsite().find(searchInput)
                            != std::string::npos)
                        {
                            searchResults.push_back(i);
                        }
                    }
                }
            }
        }

        // Refresh search results after every key press
        if(!searchInput.empty())
        {
            searchResults.clear();

            for(int i=0;i<passwordManager.getTotalPasswords();i++)
            {
                std::string website =
                    passwordManager.getPassword(i).getWebsite();

                if(website.find(searchInput) != std::string::npos)
                {
                    searchResults.push_back(i);
                }
            }
        }
    }

    // Handle mouse wheel scrolling
    if(event.type == sf::Event::MouseWheelScrolled)
    {
        // Move the dashboard view
        scrollOffset -= event.mouseWheelScroll.delta * 50;

        // Prevent scrolling above the first card
        if(scrollOffset < 0)
            scrollOffset = 0;

        // Calculate maximum scroll limit
        float maxScroll =
            passwordManager.getTotalPasswords() * 120 - 250;

        if(maxScroll < 0)
            maxScroll = 0;

        // Prevent scrolling beyond the last card
        if(scrollOffset > maxScroll)
            scrollOffset = maxScroll;

        // Update the view position
        dashboardView.setCenter(
            500,
            325 + scrollOffset
        );
    }
}

int Dashboard::handleClick(sf::Vector2f mousePosition)
{
    // Handle delete confirmation popup
    if(showDeletePopup)
    {
        if(yesButton.getGlobalBounds().contains(mousePosition))
        {
            deleteSavedPassword(selectedPassword);

            showDeletePopup = false;
            selectedPassword = -1;

            return 0;
        }

        if(noButton.getGlobalBounds().contains(mousePosition))
        {
            showDeletePopup = false;
            return 0;
        }
    }

    // Close password details popup
    if(showPasswordDetails)
    {
        if(closeButton.getGlobalBounds().contains(mousePosition))
        {
            showPasswordDetails = false;
            selectedPassword = -1;
            return 0;
        }
    }

    // Activate search bar when clicked
    if(searchBox.getGlobalBounds().contains(mousePosition))
    {
        searchActive = true;

        if(searchInput.empty())
        {
            searchText.setString("");
        }

        return 0;
    }
    else
    {
        // Deactivate search bar
        searchActive = false;

        if(searchInput.empty())
        {
            searchText.setString("Search Password...");
            searchText.setFillColor(sf::Color(170,170,170));
        }
    }

    // Check if View button is clicked
    for(int i=0; i<passwordManager.getTotalPasswords(); i++)
    {
        if(viewButtons[i].getGlobalBounds().contains(mousePosition))
        {
            selectedPassword = i;
            showPasswordDetails = true;
            return 0;
        }
    }

    // Check Edit and Delete buttons
    for(int i=0; i<passwordManager.getTotalPasswords(); i++)
    {
        if(editButtons[i].getGlobalBounds().contains(mousePosition))
        {
            selectedPassword = i;
            return 5;
        }

        if(deleteButtons[i].getGlobalBounds().contains(mousePosition))
        {
            selectedPassword = i;

            // Show confirmation popup before deleting
            showDeletePopup = true;

            return 0;
        }
    }

    // Open Add Password screen
    if(addButton.getGlobalBounds().contains(mousePosition))
    {
        return 1;
    }

    // Go back to previous screen
    if(backButton.getGlobalBounds().contains(mousePosition))
    {
        return 3;
    }

    // Delete current user account
    if(deleteButton.getGlobalBounds().contains(mousePosition))
    {
        return 4;
    }

    // Logout from the dashboard
    if(logoutButton.getGlobalBounds().contains(mousePosition))
    {
        return 2;
    }

    // No button was clicked
    return 0;
}

// Delete the currently logged-in user's account
bool Dashboard::deleteAccount()
{
    // Create FileManager object to access user file
    FileManager file;

    // Show success message on the dashboard
    messageText.setString("Account Deleted Successfully!");

    // Delete the user from the file
    if(file.deleteUser(passwordManager.getCurrentUsername()))
    {
        std::cout << "Account Deleted Successfully!" << std::endl;
        return true;
    }

    // Return false if deletion fails
    return false;
}


// Return the PasswordManager object
PasswordManager& Dashboard::getPasswordManager()
{
    return passwordManager;
}

// Reload all saved passwords and update the dashboard
void Dashboard::refreshPasswords()
{
    // Load latest passwords from file
    passwordManager.loadPasswords();

    // Update all password cards
    for(int i=0; i<passwordManager.getTotalPasswords(); i++)
    {
        websiteTexts[i].setString(
            "Website : " +
            passwordManager.getPassword(i).getWebsite()
        );

        usernameTexts[i].setString(
            "Username : " +
            passwordManager.getPassword(i).getUsername()
        );

        // Set position of each password card
        float y = 250.f + i * 120.f;

        passwordCards[i].setPosition(40.f, y);

        websiteTexts[i].setPosition(60.f, y + 15.f);
        usernameTexts[i].setPosition(60.f, y + 50.f);

        viewButtons[i].setPosition(610.f, y + 30.f);
        viewTexts[i].setPosition(635.f, y + 38.f);

        editButtons[i].setPosition(720.f, y + 30.f);
        editTexts[i].setPosition(747.f, y + 38.f);

        deleteButtons[i].setPosition(830.f, y + 30.f);
        deleteTexts[i].setPosition(845.f, y + 38.f);
    }

    // Clear unused card text
    for(int i=passwordManager.getTotalPasswords(); i<100; i++)
    {
        websiteTexts[i].setString("");
        usernameTexts[i].setString("");
    }

    // Reset search results
    searchResults.clear();

    // Add all passwords to the search list
    for(int i=0; i<passwordManager.getTotalPasswords(); i++)
    {
        searchResults.push_back(i);
    }
}

// Delete a saved password
bool Dashboard::deleteSavedPassword(int index)
{
    // Check if index is valid
    if(index < 0 || index >= passwordManager.getTotalPasswords())
    {
        return false;
    }

    // Get website name of selected password
    std::string website =
        passwordManager.getPassword(index).getWebsite();

    // Delete password and refresh dashboard
    if(passwordManager.deletePassword(website))
    {
        refreshPasswords();
        return true;
    }

    return false;
}

// Return the selected password index
int Dashboard::getSelectedPassword()
{
    return selectedPassword;
}

// Return the selected password entry
PasswordEntry Dashboard::getSelectedEntry()
{
    return passwordManager.getPassword(selectedPassword);
}