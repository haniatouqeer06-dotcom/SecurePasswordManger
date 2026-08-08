#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <SFML/Graphics.hpp>
#include <string>
#include "PasswordManager.h"
#include "Filemanager.h"

class Dashboard
{
private:

    // View used for scrolling
    sf::View dashboardView;

    // Variables used for scrolling and searching
    float scrollOffset;
    std::vector<int> searchResults;

    // Main application window
    sf::RenderWindow& window;

    // Fonts used in dashboard
    sf::Font regularFont;
    sf::Font boldFont;

    // Dashboard text
    sf::Text title;
    sf::Text welcomeText;
    sf::Text searchText;
    sf::Text logoutText;
    sf::Text deleteText;
    sf::Text backText;

    // Top section buttons
    sf::RectangleShape searchBox;
    sf::RectangleShape addButton;
    sf::RectangleShape logoutButton;
    sf::RectangleShape backButton;
    sf::RectangleShape deleteButton;

    sf::Text addButtonText;
    sf::Text messageText;

    // Password cards
    sf::RectangleShape passwordCards[100];

    // Website and username shown on each card
    sf::Text websiteTexts[100];
    sf::Text usernameTexts[100];

    // Action buttons on every password card
    sf::RectangleShape viewButtons[100];
    sf::RectangleShape editButtons[100];
    sf::RectangleShape deleteButtons[100];

    sf::Text viewTexts[100];
    sf::Text editTexts[100];
    sf::Text deleteTexts[100];

    // Message shown when no passwords are available
    sf::Text emptyTitle;
    sf::Text emptySubtitle;

    // Search bar variables
    std::string searchInput;
    bool searchActive;

    // Handles all password operations
    PasswordManager passwordManager;

    // Stores currently selected password
    int selectedPassword;
    bool showPasswordDetails;

    // Close button for password details popup
    sf::RectangleShape closeButton;
    sf::Text closeText;

    // Search cursor blinking
    sf::Clock searchCursorClock;
    bool showSearchCursor;

    // Delete confirmation popup
    bool showDeletePopup;

    sf::RectangleShape popupBox;

    sf::RectangleShape yesButton;
    sf::RectangleShape noButton;

    sf::Text popupText;
    sf::Text yesText;
    sf::Text noText;

public:

    // Constructor
    Dashboard(
        sf::RenderWindow& window,
        std::string username
    );

    // Draw all dashboard components
    void draw();

    // Handle keyboard and mouse events
    void handleEvent(
        sf::Event& event
    );

    // Handle button clicks
    int handleClick(
        sf::Vector2f mousePosition
    );

    // Delete current user account
    bool deleteAccount();

    // Return PasswordManager object
    PasswordManager& getPasswordManager();

    // Reload all saved passwords
    void refreshPasswords();

    // Delete selected password
    bool deleteSavedPassword(int index);

    // Return selected password index
    int getSelectedPassword();

    // Return selected password entry
    PasswordEntry getSelectedEntry();
};

#endif