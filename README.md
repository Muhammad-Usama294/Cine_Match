# 🎬 Cine_Match - Movie Recommendation System

[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Data Structure](https://img.shields.io/badge/Data%20Structure-Binary%20Search%20Tree-green.svg)](https://en.wikipedia.org/wiki/Binary_search_tree)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

A console-based Movie Recommendation System built with C++ using Binary Search Trees (BST) for efficient data management. This project was developed as a Data Structures and Algorithms (DSA) final project, demonstrating practical implementation of BST data structures in a real-world application.

## 📋 Table of Contents

- [Features](#-features)
- [Data Structures](#-data-structures)
- [Technologies Used](#-technologies-used)
- [File Structure](#-file-structure)
- [How to Build and Run](#-how-to-build-and-run)
- [Usage Guide](#-usage-guide)
- [Data File Format](#-data-file-format)
- [Future Enhancements](#-future-enhancements)
- [Authors](#-authors)
- [License](#-license)

## ✨ Features

Cine_Match offers a comprehensive set of features for managing movies and user interactions:

### 👤 User Management
- **User Registration**: Create new user accounts with unique IDs
- **User Login System**: Secure authentication with username and password
- **User Profile Management**: Store and manage user information

### 🎥 Movie Database
- **Add New Movies**: Insert movies with ID, name, genre, and IMDb rating
- **Delete Movies**: Remove movies from the database
- **Search Movies**: Efficiently search movies by ID using BST
- **Display Movies**: View complete movie list with details
- **Genre-based Browsing**: Browse movies by different genres

### ⭐ Rating System
- **Rate Movies**: Users can rate movies on a scale of 1-5
- **View Ratings**: Display all user ratings
- **Update Ratings**: Modify existing ratings
- **Delete Ratings**: Remove previous ratings

### 🎯 Recommendation Engine
- **Movie Recommendations**: Get personalized movie recommendations based on:
  - User rating history
  - Genre preferences
  - IMDb ratings
  - Similar user patterns

### 💾 Data Persistence
- **File-based Storage**: All data persists across sessions
- **Automatic Save**: Changes are automatically saved to files
- **Data Loading**: Previous data loads on startup

## 🌳 Data Structures

The system implements three main Binary Search Trees for optimal data organization and retrieval:

### 1. Movie BST
Stores movie information with the following structure:
```cpp
struct Movie {
    int movieID;           // Unique identifier (BST key)
    char movieName[40];    // Movie title
    char genre[40];        // Movie genre
    float imbdRating;      // IMDb rating (variable name kept as in source)
    Movie* lchild;         // Left child pointer
    Movie* rchild;         // Right child pointer
};
```
- **Key**: Movie ID
- **Purpose**: Efficient movie search, insertion, and deletion operations
- **Time Complexity**: O(log n) average case for balanced tree

### 2. User BST
Manages user accounts:
```cpp
struct User {
    int userID;            // Unique identifier (BST key)
    char userName[40];     // Username
    char password[40];     // Password
    User* lchild;          // Left child pointer
    User* rchild;          // Right child pointer
};
```
- **Key**: User ID
- **Purpose**: User authentication and account management
- **Time Complexity**: O(log n) for login and user lookup

### 3. Rating BST
Tracks user ratings for movies:
```cpp
struct Rating {
    int rating;            // Rating value (1-5)
    int mID;              // Movie ID
    int uID;              // User ID
    Rating* lchild;        // Left child pointer
    Rating* rchild;        // Right child pointer
};
```
- **Key**: Composite of user ID and movie ID
- **Purpose**: Store and retrieve user ratings efficiently
- **Time Complexity**: O(log n) for rating operations

## 🛠️ Technologies Used

- **Programming Language**: C++
- **Data Structure**: Binary Search Trees (BST)
- **File I/O**: Standard C++ file streams for data persistence
- **Graphics Library**: `graphics.h` for enhanced UI elements
- **IDE**: Dev-C++ (project configuration included)

## 📁 File Structure

```
Cine_Match/
├── main.cpp                 # Entry point and main menu logic
├── dof.cpp                  # Core functionality implementation
├── mrs.h                    # Header file with struct definitions and function declarations
├── DSA FINAL PROJ.dev       # Dev-C++ project file
├── Movies.txt               # Movie database (persistent storage)
├── Users.txt                # User accounts (persistent storage)
├── ratings.txt              # User ratings (persistent storage)
└── README.md                # This file
```

### Key Files Description

- **`main.cpp`**: Contains the main application loop, user interface menus, and handles user input for navigation
- **`dof.cpp`**: Implements all the MovieRecommendationSystem functions including BST operations, file I/O, and recommendation algorithms
- **`mrs.h`**: Defines the data structures (Movie, User, Rating) and the MovieRecommendationSystem class with all function prototypes
- **`Movies.txt`**: Stores movie data in a structured format
- **`Users.txt`**: Stores user credentials and information
- **`ratings.txt`**: Stores user-movie rating associations

## 🚀 How to Build and Run

### Option 1: Using Dev-C++ (Recommended)

1. Open `DSA FINAL PROJ.dev` in Dev-C++
2. Build the project (Execute → Compile or press F9)
3. Run the executable (Execute → Run or press F10)

### Option 2: Manual Compilation

#### Windows (with MinGW)
```bash
g++ main.cpp dof.cpp -o CineMatch.exe
CineMatch.exe
```

#### Linux/Mac
```bash
g++ main.cpp dof.cpp -o CineMatch
./CineMatch
```

**Note**: If using graphics features, you may need to link the graphics library (flags vary by system):
```bash
# Windows with WinBGIm
g++ main.cpp dof.cpp -o CineMatch -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

# Or if using a different graphics library, adjust accordingly
```

### Prerequisites

- C++ compiler (GCC 4.8+ or MSVC 2015+)
- Graphics library (optional, for enhanced UI)
- Windows OS (for `graphics.h` support) or compatible graphics library on Linux

## 📖 Usage Guide

### Getting Started

1. **First Run**: On first launch, no data files exist
2. **Create Account**: Select option 2 (SignUp) from the main menu
3. **Login**: Use option 1 (Login) with your credentials

### Creating an Account

```
Main Menu → SignUp (2)
→ Enter User ID (unique integer)
→ Enter Username
→ Enter Password
→ Account created successfully!
```

### Logging In

```
Main Menu → Login (1)
→ Enter User ID
→ Enter Password
→ Access granted to main features
```

### Adding a Movie

```
Main Menu → Login → Add a new Movie (1)
→ Enter Movie ID (unique integer)
→ Enter Movie Name
→ Enter Genre (e.g., Action, Comedy, Drama)
→ Enter IMDb Rating (e.g., 8.5)
→ Movie added successfully!
```

### Rating a Movie

```
Main Menu → Login → Rate a Movie (5)
→ View list of available movies
→ Enter Movie ID to rate
→ Enter rating (1-5 scale)
→ Rating saved successfully!
```

### Browsing Movies

```
Main Menu → Login → Display Movies List (2)
→ View all movies with:
   - Movie ID
   - Movie Name
   - Genre
   - IMDb Rating
```

### Getting Recommendations

```
Main Menu → Login → Recommended Movies For You (8)
→ System analyzes:
   - Your rating history
   - Your genre preferences
   - Similar users' ratings
   - IMDb ratings
→ Displays personalized recommendations
```

### Deleting a Movie

```
Main Menu → Login → Delete a Movie (6)
→ View list of movies
→ Enter Movie ID to delete
→ Movie removed from database
```

### Managing Your Ratings

```
Main Menu → Login → Remove any of your previous Ratings (7)
→ View your ratings
→ Select rating to remove
→ Rating deleted successfully!
```

## 📊 Data File Format

The system uses binary file format for efficient data storage and retrieval. All three data files (Movies.txt, Users.txt, ratings.txt) store data in binary format, not plain text.

### Movies.txt Format
Stores movie records in binary format using the Movie struct (excluding pointer fields):
- Each record contains: `movieID`, `movieName[40]`, `genre[40]`, `imbdRating`
- Written using: `write(reinterpret_cast<char*>(movie), offsetof(Movie, lchild))`
- Only data fields are stored (pointer fields `lchild` and `rchild` are excluded)

### Users.txt Format
Stores user account information in binary format using the User struct:
- Each record contains: `userID`, `userName[40]`, `password[40]`
- Written using: `write(reinterpret_cast<char*>(user), offsetof(User, lchild))`
- Only data fields are stored (pointer fields excluded)

### ratings.txt Format
Stores user ratings in binary format using the Rating struct:
- Each record contains: `rating`, `mID`, `uID`
- Written using: `write(reinterpret_cast<char*>(rating), offsetof(Rating, lchild))`
- Only data fields are stored (pointer fields excluded)

**Note**: The files use binary format for efficient I/O operations. The tree structure (left/right child pointers) is rebuilt in memory when loading data from files.

## 🔮 Future Enhancements

Potential improvements for the system:

1. **Advanced Recommendation Algorithms**
   - Collaborative filtering (user-user and item-item)
   - Content-based filtering using genre similarity
   - Hybrid recommendation approaches
   - Machine learning integration

2. **Enhanced User Experience**
   - Modern graphical user interface (GUI) using Qt or wxWidgets
   - Web-based interface with REST API
   - Mobile application support
   - Search functionality with filters

3. **Database Integration**
   - Migrate from file-based storage to SQL database (MySQL/PostgreSQL)
   - Improved data consistency and transaction support
   - Better scalability for large datasets

4. **Additional Features**
   - Movie reviews and comments
   - Watchlist functionality
   - Social features (follow users, share recommendations)
   - Movie trailers and poster integration
   - Advanced search with multiple criteria
   - User profile customization

5. **Performance Optimizations**
   - Self-balancing BST (AVL or Red-Black Tree) for better worst-case performance
   - Caching frequently accessed data
   - Indexing for faster searches
   - Parallel processing for recommendations

6. **Security Enhancements**
   - Password encryption (hashing with salt)
   - Session management
   - Input validation and sanitization
   - Protection against SQL injection (when using database)

## 👥 Authors

This project was developed as a Data Structures and Algorithms (DSA) Final Project.

**Project Repository**: [Muhammad-Usama294/Cine_Match](https://github.com/Muhammad-Usama294/Cine_Match)

## 📄 License

This project is licensed under the MIT License - see below for details:

```
MIT License

Copyright (c) 2024 Cine_Match Contributors

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

<div align="center">

**🎬 Enjoy using Cine_Match! 🎥**

If you find this project helpful, please consider giving it a ⭐ on GitHub!

[Report Bug](https://github.com/Muhammad-Usama294/Cine_Match/issues) · [Request Feature](https://github.com/Muhammad-Usama294/Cine_Match/issues)

</div>
