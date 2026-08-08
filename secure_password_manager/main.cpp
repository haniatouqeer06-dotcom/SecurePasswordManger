#include <SFML/Graphics.hpp>
#include<iostream>

#include "HomeScreen.h"
#include "loginScreen.h"
#include "RegisterScreen.h"
#include "Dashboard.h"
#include "AddPasswordScreen.h"

using namespace std;

int main()
{
    // Create application window
    sf::RenderWindow window(sf::VideoMode(1000,650),"Secure Vault");

    // Create all screens
    HomePage home(window);
    loginPage login(window);
    RegisterScreen registerScreen(window);

    // These screens will be created after login/register
    Dashboard* dashboard = nullptr;
    AddPasswordScreen* addScreen = nullptr;

    // Current screen tracker
    // 0 = Home
    // 1 = Login
    // 2 = Register
    // 3 = Dashboard
    // 4 = Add Password
    int currentScreen = 0;

    // Main application loop
    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            // Close window
            if(event.type==sf::Event::Closed)
            {
                window.close();
            }

            //-----------------HOME SCREEN ---------------

            if(currentScreen==0)
            {
                if(event.type==sf::Event::MouseButtonPressed)
                {
                    sf::Vector2f mousePosition =
                    window.mapPixelToCoords(
                    sf::Mouse::getPosition(window));

                    int result = home.handleClick(mousePosition);

                    // Open login screen
                    if(result==1)
                    {
                        currentScreen=1;
                    }

                    // Open register screen
                    else if(result==2)
                    {
                        currentScreen=2;
                    }
                }
            }

            //--------------- LOGIN SCREEN---------------

            else if(currentScreen==1)
            {
                // Handle typing
                if(event.type == sf::Event::MouseButtonPressed)
                    login.handleclick(
                        window.mapPixelToCoords(
                        sf::Mouse::getPosition(window)));

                login.handleevent(event);

                if(event.type==sf::Event::MouseButtonPressed)
                {
                    sf::Vector2f mousePosition =
                    window.mapPixelToCoords(
                    sf::Mouse::getPosition(window));

                    int result = login.handleclick(mousePosition);

                    // Login button
                    if(result==1)
                    {
                        if(login.loginUser())
                        {
                            // Create dashboard for logged-in user
                            delete dashboard;

                            dashboard = new Dashboard(
                                window,
                                login.getUserName()
                            );

                            dashboard->refreshPasswords();

                            // Create add password screen
                            addScreen = new AddPasswordScreen(
                                window,
                                dashboard->getPasswordManager()
                            );

                            currentScreen = 3;
                        }
                    }

                    // Back button
                    else if(result==2)
                    {
                        currentScreen=0;
                    }
                }
            }

            //================ REGISTER SCREEN =================

            else if(currentScreen==2)
            {
                // Handle typing
                registerScreen.handleEvent(event);

                if(event.type==sf::Event::MouseButtonPressed)
                {
                    sf::Vector2f mousePosition =
                    window.mapPixelToCoords(
                    sf::Mouse::getPosition(window));

                    int result = registerScreen.handleClick(mousePosition);

                    // Register button
                    if(result==1)
                    {
                        if(registerScreen.registerUser())
                        {
                            // Create dashboard for new user
                            delete dashboard;

                            dashboard = new Dashboard(
                                window,
                                registerScreen.getUserName()
                            );

                            dashboard->refreshPasswords();

                            addScreen = new AddPasswordScreen(
                                window,
                                dashboard->getPasswordManager()
                            );

                            currentScreen = 3;
                        }
                    }

                    // Back button
                    else if(result==2)
                    {
                        currentScreen=0;
                    }
                }
            }

            //================ DASHBOARD =================

            else if(currentScreen==3)
            {
                // Handle keyboard events
                if(dashboard != nullptr)
                {
                    dashboard->handleEvent(event);
                }

                if(event.type==sf::Event::MouseButtonPressed)
                {
                    sf::Vector2f mousePosition =
                    window.mapPixelToCoords(
                    sf::Mouse::getPosition(window));

                    int result = 0;

                    if(dashboard != nullptr)
                    {
                        result = dashboard->handleClick(mousePosition);
                    }

                    // Logout
                    if(result==2)
                    {
                        currentScreen=0;
                    }

                    // Open add password screen
                    else if(result==1)
                    {
                        currentScreen = 4;
                    }

                    // Back to login
                    else if(result==3)
                    {
                        currentScreen=1;
                    }

                    // Delete account
                    else if(result==4)
                    {
                        if(dashboard != nullptr)
                        {
                            if(dashboard->deleteAccount())
                            {
                                delete dashboard;
                                dashboard = nullptr;

                                currentScreen = 0;
                            }
                        }
                    }

                    // Edit password
                    else if(result==5)
                    {
                        if(dashboard != nullptr && addScreen != nullptr)
                        {
                            addScreen->setEditData(
                                dashboard->getSelectedEntry()
                            );

                            currentScreen = 4;
                        }
                    }

                    // Delete selected password
                    else if(result==6)
                    {
                        if(dashboard != nullptr)
                        {
                            if(dashboard->deleteSavedPassword(
                                dashboard->getSelectedPassword()
                            ))
                            {
                                std::cout << "Password Deleted" << std::endl;
                            }
                        }
                    }
                }
            }

            //================ ADD PASSWORD =================

            else if(currentScreen==4)
            {
                // Handle typing
                if(addScreen != nullptr)
                {
                    addScreen->handleEvent(event);
                }

                if(event.type==sf::Event::MouseButtonPressed)
                {
                    sf::Vector2f mousePosition =
                    window.mapPixelToCoords(
                    sf::Mouse::getPosition(window));

                    int result = addScreen->handleClick(mousePosition);

                    // Save password
                    if(result==1)
                    {
                        if(addScreen->savePassword())
                        {
                            // Refresh dashboard after saving
                            dashboard->refreshPasswords();

                            currentScreen = 3;
                        }
                    }

                    // Back to dashboard
                    else if(result==2)
                    {
                        currentScreen = 3;
                    }
                }
            }
        }

        // Clear window before drawing
        window.clear(
            sf::Color(11,16,32)
        );

        // Draw current screen
        if(currentScreen==0)
        {
            home.draw();
        }

        else if(currentScreen==1)
        {
            login.draw();
        }

        else if(currentScreen==2)
        {
            registerScreen.draw();
        }

        else if(currentScreen==3)
        {
            if(dashboard != nullptr)
            {
                dashboard->draw();
            }
        }

        else if(currentScreen==4)
        {
            if(addScreen!=nullptr)
            {
                addScreen->draw();
            }
        }

        // Display everything on the screen
        window.display();
    }

    return 0;
}