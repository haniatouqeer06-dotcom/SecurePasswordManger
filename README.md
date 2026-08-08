# Secure Password Manager

## Project Overview

**Secure Password Manager** is a desktop application developed in **C++** using **Object-Oriented Programming (OOP)** and **SFML** for the graphical user interface.

The application allows users to register and log in to their accounts and securely manage credentials for different websites. Users can add, view, search, edit, and delete saved passwords through an interactive dashboard.

The project combines **C++ OOP, file handling, GUI development, and basic encryption concepts** to create a practical password management application.

## Features

* User registration and login
* User-specific password storage
* Add, view, search, edit, and delete passwords
* Password encryption and decryption
* File-based data storage
* Interactive SFML graphical interface
* Search bar and scrolling password dashboard
* Logout and account deletion
* Delete confirmation and status messages

## Technologies Used

* C++
* Object-Oriented Programming (OOP)
* SFML
* File Handling
* Vectors and Strings
* Encryption and Decryption

## How It Works

After registration, the application creates user-specific data files for storing saved credentials. Passwords are encrypted before being stored and decrypted when they are displayed to the user.

Users can manage their saved credentials directly from the dashboard. Changes such as adding, editing, or deleting passwords are reflected in the corresponding user data.

The application also maintains user information for authentication and account management.

## Development Process

The project was developed step by step, starting with the basic authentication system and gradually adding password management and GUI functionality.

1. Designed the application screens and navigation.
2. Implemented user registration and login.
3. Added file handling for user and password data.
4. Developed the password management system.
5. Implemented encryption and decryption.
6. Created the SFML dashboard and input screens.
7. Added search, edit, delete, logout, and account deletion features.
8. Tested the complete application flow and fixed data-management issues.

## What I Learned

This project helped me gain practical experience with:

* C++ OOP concepts
* Classes, objects, constructors, and encapsulation
* Vectors, strings, references, and dynamic memory
* File handling
* Basic encryption and decryption
* SFML GUI development
* Mouse and keyboard event handling
* Debugging and modular development
* Basic cybersecurity and password-management concepts

## How to Run

### Requirements

* C++ compiler
* SFML library
* C++ development environment

### Steps

1. Clone or download the repository.
2. Make sure SFML is installed and configured.
3. Make sure the `assets/fonts/` folder is present.
4. Run the `build.sh` script to compile the project.
5. Run the generated application.
6. Register an account and start managing your passwords.

## Project Structure

```text
Secure-Password-Manager/
├── .cpp files
├── .h files
├── build.sh
├── README.md
├── assets/
│   └── fonts/
└── users.txt
```

## Security Note

This project uses a **Caesar Cipher** for educational demonstration of encryption and decryption. It is **not intended for storing real-world sensitive passwords** and should not be considered a production-level password manager.

## Future Improvements

* Stronger encryption algorithms
* Password generator
* Password strength checker
* Improved authentication
* Additional security features
* Improved UI and user experience

## Project Purpose

This project demonstrates the practical use of **C++ OOP, SFML GUI development, file handling, and basic cybersecurity concepts** by building a functional desktop password management application.

## Demo Video

A short demonstration of the Secure Password Manager, showcasing its main features, user interface, and complete application workflow.

https://github.com/user-attachments/assets/7cc54c78-8a08-4a6b-9595-ede89eed357d

