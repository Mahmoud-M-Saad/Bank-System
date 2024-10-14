# JSON Bank System

## Project Overview

This project is a simple **Small Bank System** implemented in C++. It allows interaction between clients, employees and admins, providing the following features:

- **Admin Features**:
  - Add clients, employees and another admins.
  - Search for clients, employees and another admins by ID.
  - Get All clients, employees and another admins.
  - Update clients, employees and another admins by ID.
  - Delete All clients, employees and another admins.
  - Delete clients, employees and another admins by ID.

- **Employee Features**:
  - Add clients.
  - Search for clients by ID.
  - Get All clients.
  - Update clients by ID.
  - Delete All clients.
  - Delete clients by ID.

- **User Features**:
  - Display his information.
  - Check his balance.
  - Deposit to his balance.
  - Withdraw from his balance.
  - Transfer to another client.
  - Update his Password.

### Project Scope

- The project is designed to be simple and straightforward, focusing on OOP C++ programming techniques taking into account SOLID principles.
- It uses JSON files as a database.
- Also, each model is in a separate class and files to make all their CRUD operations on it.
- Moreover, We perform rigorous validation on each input. For example, phone numbers must start with (010, 012, 011, or 015) followed by 8 digits.

## Prerequisites

To compile and run this project, you'll need:

- A C++ compiler (e.g., GCC, Clang, MSVC).
- A text editor or an Integrated Development Environment (IDE) such as Visual Studio, Code::Blocks, or VSCode.

## Project Structure
``` text
.
├── app
│    ├── database
│    │       ├── admin.json
│    │       ├── client.json
│    │       └── employee.json
│    ├── include
│    │       ├── admin.h
│    │       ├── authFun.h
│    │       ├── client.h
│    │       ├── employee.h
│    │       ├── generalFunctions.h
│    │       ├── person.h
│    │       ├── screen.h
│    │       └── validation.h
│    ├── src
│    │       ├── admin.cpp
│    │       ├── authFun.cpp
│    │       ├── client.cpp
│    │       ├── employee.cpp
│    │       ├── generalFunctions.cpp
│    │       ├── person.cpp
│    │       ├── screen.cpp
│    │       └── validation.cpp
│    ├── thirdParty
│    │       ├── json.hpp
│    │       └── jsonFunctions.h
│    └── main.cpp
├── .gitattributes
├── .gitignore
├── CMakeLists.txt
├── CMakePresets.json
└── README.md

```

Main program go in [app/](app),
Sources go in [src/](app/src),
Header files go in [include/](app/include), 
Database files go in [database/](app/database),
Third-party package files go in [thirdParty/](app/thirdParty).

## How to Compile and Run the Project

## Way 1: Using Microsoft Visual Studio IDE 

  1. Open Microsoft Visual Studio IDE.
  2. Choose `Clone a repository`.
  3. Copy this url
  ```bash
  https://github.com/Mahmoud-M-Saad/Bank-System.git
  ```
  4. Open Bank-System --> app --> main.cpp
  5. Run the compiler or click f5. 

## Way 2: Using Bash 

  1. Clone the repository to your local machine:

  ```bash
  git clone https://github.com/Mahmoud-M-Saad/Bank-System.git
  cd Library-System
  ```

  2. Run the compiler.

## Finally

Hope you enjoy our Bank 😊
