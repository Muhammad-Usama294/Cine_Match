# 🎬 Cine_Match - Movie Recommendation System

[![C++](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)
[![Data Structure](https://img.shields.io/badge/Data%20Structure-Binary%20Search%20Tree-green.svg)](https://en.wikipedia.org/wiki/Binary_search_tree)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

A console-based Movie Recommendation System built with C++ using **Binary Search Trees (BST)** for efficient data management and retrieval. This project demonstrates the practical implementation of data structures and algorithms concepts in a real-world application.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Data Structures](#data-structures)
- [Technologies Used](#technologies-used)
- [File Structure](#file-structure)
- [How to Build and Run](#how-to-build-and-run)
- [Usage Guide](#usage-guide)
- [Data File Format](#data-file-format)
- [Future Enhancements](#future-enhancements)
- [Authors](#authors)
- [License](#license)

## 🎥 Overview

**Cine_Match** is a Data Structures and Algorithms (DSA) final project that implements a comprehensive movie recommendation system. The application uses Binary Search Trees to efficiently store and manage movie data, user accounts, and ratings, providing fast search and retrieval operations.

The system allows users to:
- Register and login to their accounts
- Browse and search through movie databases
- Rate movies based on personal preferences
- Receive movie recommendations
- Manage movie entries (add/delete operations)

## ✨ Features

### 🔐 User Management
- **User Registration**: Create new user accounts with unique IDs
- **User Login**: Secure login system with credential verification
- **User Database**: Persistent storage of user information

### 🎞️ Movie Database Management
- **Add Movies**: Insert new movies with ID, name, genre, and IMDb rating
- **Delete Movies**: Remove movies from the database
- **Search Movies**: Fast movie lookup using BST structure
- **Display Movies**: View complete movie listings with details
- **Genre-Based Browsing**: Explore movies by their genres

### ⭐ Rating System
- **Rate Movies**: Users can rate movies on a scale of 1-5
- **Rating Storage**: Persistent storage of user ratings
- **Rating Management**: Delete or modify previous ratings
- **Rating Display**: View all ratings in the system

### 🎯 Recommendation Engine
- **Personalized Recommendations**: Get movie suggestions based on user preferences
- **IMDb Integration**: Movies include IMDb ratings for quality reference

### 💾 Data Persistence
- **File-Based Storage**: All data persists across sessions
- **Binary File Operations**: Efficient read/write operations
- **Three Data Files**:
  - `Movies.txt` - Movie database
  - `Users.txt` - User accounts
  - `ratings.txt` - User ratings

## 🌳 Data Structures

The system implements **three Binary Search Trees (BST)** for optimal data organization:

### 1. Movie BST
Stores movie information with the following structure:
- **Movie ID** (key for BST ordering)
- **Movie Name** (up to 40 characters)
- **Genre** (up to 40 characters)
- **IMDb Rating** (float value)
- **Left and Right Child Pointers** (BST structure)

**Operations**: O(log n) average case for search, insert, and delete

### 2. User BST
Manages user accounts with:
- **User ID** (key for BST ordering)
- **Username** (up to 40 characters)
- **Password** (up to 40 characters)
- **Left and Right Child Pointers** (BST structure)

**Operations**: Efficient user lookup and authentication

### 3. Rating BST
Tracks user ratings with:
- **Rating Value** (1-5 scale)
- **Movie ID** (reference to movie)
- **User ID** (reference to user)
- **Left and Right Child Pointers** (BST structure)

**Operations**: Quick rating retrieval for recommendations

## 🛠️ Technologies Used

- **Programming Language**: C++
- **Core Data Structure**: Binary Search Trees (BST)
- **File I/O**: Binary and text file operations for data persistence
- **Graphics Library**: `graphics.h` for enhanced user interface
- **Standard Libraries**:
  - `<iostream>` - Input/output operations
  - `<fstream>` - File handling
  - `<cstring>` - String operations
  - `<conio.h>` - Console I/O
  - `<windows.h>` - Windows API functions

## 📁 File Structure

```
Cine_Match/
├── main.cpp                    # Entry point and main menu logic
├── dof.cpp                     # Core functionality implementation
├── mrs.h                       # Header file with struct definitions
├── DSA FINAL PROJ.dev          # Dev-C++ project file
├── Movies.txt                  # Movie database (binary format)
├── Users.txt                   # User accounts (binary format)
├── ratings.txt                 # User ratings (binary format)
├── Makefile.win                # Windows makefile
└── README.md                   # Project documentation
```

### Key Files Description

| File | Description |
|------|-------------|
| `main.cpp` | Contains the main function and primary user interface logic |
| `dof.cpp` | Implements all BST operations and system functionalities |
| `mrs.h` | Defines Movie, User, and Rating structures plus MovieRecommendationSystem class |
| `Movies.txt` | Binary file storing all movie records |
| `Users.txt` | Binary file storing all user accounts |
| `ratings.txt` | Binary file storing all user ratings |

## 🚀 How to Build and Run

### Method 1: Using Dev-C++ IDE (Recommended)

1. Open **Dev-C++** IDE
2. Open the project file: `DSA FINAL PROJ.dev`
3. Click on **Execute** → **Compile** (or press F9)
4. Click on **Execute** → **Run** (or press F10)

### Method 2: Manual Compilation

#### Windows (with MinGW)
```bash
# Navigate to project directory
cd path/to/Cine_Match

# Compile the project
g++ main.cpp dof.cpp -o CineMatch

# Run the executable
CineMatch.exe
```

#### Linux/Unix
```bash
# Navigate to project directory
cd path/to/Cine_Match

# Compile the project (graphics library may need alternative)
g++ main.cpp dof.cpp -o CineMatch

# Run the executable
./CineMatch
```

**Note**: The `graphics.h` library is primarily Windows-based. For Linux systems, you may need to use alternative graphics libraries or comment out graphics-related code.

### Prerequisites

- **C++ Compiler**: GCC/G++ (MinGW for Windows) or any C++11 compatible compiler
- **Dev-C++ IDE**: (Optional but recommended) Version 5.0 or higher
- **Operating System**: Windows (recommended), Linux/Unix (with modifications)

## 📖 Usage Guide

### 1. Starting the Application

When you launch Cine_Match, you'll see the main menu:
```
1. Login
2. SignUp
3. Exit
```

### 2. Creating an Account (SignUp)

1. Select option **2** from the main menu
2. Enter a unique **User ID** (integer)
3. Enter your desired **Username**
4. Enter a **Password**
5. Your account will be created and saved to `Users.txt`

### 3. Logging In

1. Select option **1** from the main menu
2. Enter your **User ID**
3. Enter your **Username**
4. Enter your **Password**
5. Upon successful authentication, you'll access the main system

### 4. Main System Menu

After logging in, you can:

```
1. Add a new Movie
2. Display Movies List
3. Add a new User
4. Display Users List
5. Rate a Movie
6. Delete a Movie
7. Remove any of your previous Ratings
8. Recommended Movies For You
30. Display Ratings
0. Logout
```

#### Adding a Movie
1. Select option **1**
2. Enter Movie ID (unique integer)
3. Enter Movie Name
4. Enter Genre (e.g., Action, Comedy, Drama)
5. Enter IMDb Rating (float, e.g., 8.5)

#### Rating a Movie
1. Select option **5**
2. View the list of available movies
3. Enter the Movie ID you want to rate
4. Enter your rating (1-5 scale)

#### Getting Recommendations
1. Select option **8**
2. The system will display personalized movie recommendations based on:
   - Your previous ratings
   - Movie genres you prefer
   - IMDb ratings

#### Deleting a Movie
1. Select option **6**
2. View the list of movies
3. Enter the Movie ID to delete
4. The movie will be removed from the database and file

### 5. Logging Out

Select option **0** to logout and return to the main menu

## 📊 Data File Format

### Movies.txt Format
Binary file storing Movie structures:
```
Offset 0-3:   Movie ID (int)
Offset 4-43:  Movie Name (char[40])
Offset 44-83: Genre (char[40])
Offset 84-87: IMDb Rating (float)
```

### Users.txt Format
Binary file storing User structures:
```
Offset 0-3:   User ID (int)
Offset 4-43:  Username (char[40])
Offset 44-83: Password (char[40])
```

### ratings.txt Format
Binary file storing Rating structures:
```
Offset 0-3:   Rating (int, 1-5)
Offset 4-7:   Movie ID (int)
Offset 8-11:  User ID (int)
```

**Note**: These files use binary format for efficient storage. Pointers (lchild, rchild) are not stored in files and are reconstructed when loading data.

## 🚀 Future Enhancements

This project has potential for many exciting improvements:

### 🤖 Advanced Recommendation Algorithms
- Implement **Collaborative Filtering** to recommend movies based on similar users' preferences
- Add **Content-Based Filtering** using movie genres and features
- Develop a **Hybrid Recommendation System** combining multiple approaches

### 💻 User Interface Improvements
- Develop a **Modern GUI** using Qt, wxWidgets, or similar frameworks
- Add a **Web Interface** with HTML/CSS/JavaScript frontend
- Create a **Mobile App** version for Android/iOS

### 🗄️ Database Integration
- Migrate from file-based storage to **SQL databases** (MySQL, PostgreSQL)
- Implement **NoSQL** solutions like MongoDB for flexible data structures
- Add **Redis** caching for faster data retrieval

### 🎯 New Features
- **Movie Search** with multiple filters (year, director, actors)
- **User Reviews** and written feedback
- **Watchlist** functionality
- **Friend System** to see what friends are watching
- **Movie Trailers** and poster integration
- **Advanced Statistics** and user analytics
- **Multi-language Support**

### 🔒 Security Enhancements
- Implement **Password Hashing** (bcrypt, SHA-256)
- Add **Session Management**
- Implement **Input Validation** and sanitization
- Add **Two-Factor Authentication** (2FA)

### 📈 Performance Optimizations
- Implement **Self-Balancing BST** (AVL Tree or Red-Black Tree)
- Add **Caching Mechanisms** for frequently accessed data
- Optimize file I/O operations with **buffering**

## 👥 Authors

**DSA Final Project**
- Developed as a comprehensive Data Structures and Algorithms course project
- Demonstrates practical implementation of Binary Search Trees in real-world applications

*For contributions, please open an issue or submit a pull request.*

## 📄 License

This project is licensed under the **MIT License** - see below for details:

```
MIT License

Copyright (c) 2024 Cine_Match Project

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

---

## 🙏 Acknowledgments

- Thanks to the Data Structures and Algorithms course for inspiration
- Binary Search Tree implementation based on standard CS algorithms
- Movie data structure design influenced by real-world database schemas

---

<div align="center">

**⭐ Star this repository if you found it helpful!**

Made with ❤️ using C++ and Binary Search Trees

</div>
