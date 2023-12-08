# School Database Manager with AES Encryption

This C program efficiently manages a school database, organizing student information such as classes, levels, and majors. Notably, it reads encrypted data from an existing database, decrypts it using the AES-256-CBC algorithm for processing and updates, and encrypts the modified data before storing it back. This robust encryption and decryption mechanism ensure the privacy and confidentiality of student records, maintaining a secure database environment.

 ### This is project is part of bootcamp and collabration with Checkpoint - for more data look in [Project Details](#project-details)

# Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Setup and Execution](#setup-and-execution)
- [Structure](#structure)
- [Usage](#usage)
  - [Operations Menu](#operations-menu)
  - [Data Encryption](#data-encryption)
- [Project Details](#project-details)
- [Recommendations](#recommendations)
  - [Checking for Memory Leaks with Valgrind](#checking-for-memory-leaks-with-valgrind)
- [Contributing](#contributing)
- [License](#license)

## Features

- **School Database Management**: Manages student records, classes, levels, and majors.
- **Data Encryption**: Encrypts sensitive information before storage for confidentiality.

## Requirements

Ensure you have OpenSSL installed on your system.

- **Linux**: `sudo apt-get install libssl-dev`
- **macOS**: `brew install openssl`

## Setup and Execution
### Compilation
```bash
gcc crypt.c -o crypt -lcrypto
gcc main.c -o student_db -lcrypto
```
### Execution
```bash
./crypt
./student_db
```

## Structure

The program consists of the following main components:

- **Memory Functions:** Functions to manage memory allocation and deallocation.
- **Utility Functions:** Various utility functions for input validation, output formatting, and calculations.
- **Database Functions:** Functions for initializing, parsing, and manipulating the student database.
- **Menu Functions:** Functions that enable user interaction through a menu-based interface.

## Usage

### Operations Menu

The program presents a menu for various operations:

- **Add Student**: Insert new student records.
- **Remove Student**: Delete existing student entries.
- **Update Student**: Modify student information.
- **Search Student**: Look up specific student details.
- **Top Students**: Find high-performing students.
- **Unstable Students**: Identify students with grades below 60.
- **Level Average**: Calculate the average grade for a specific level.
- **Print Database**: Display the database content.
- **Export Database**: Save database content to a file.
- **Clear Database**: Remove all entries from the database.

### Data Encryption

All stored data undergoes encryption to maintain privacy and data protection.

## Project Details
- **Bootcamp:** Participated in the July-August 2023 bootcamp organized by Scale Up Velocity.
- **Collaboration:** This project was in collaboration with Checkpoint Company.
- **Objective:** The project aimed to manage and solve a correct system of a database for the problem described.


## Recommendations

This project was primarily developed and tested in a Linux environment (like Ubuntu). Consider using tools such as Valgrind for memory debugging to ensure code stability.

### Checking for Memory Leaks with Valgrind
To check for memory leaks in your program using Valgrind, follow these steps:
1. Compile your code with debugging:
    ```bash
    gcc -g crypt.c -o crypt -lcrypto
    ```

2. Run Valgrind and redirect the output to a file named `valgrind_output.txt`:
    ```bash
    valgrind --leak-check=full ./crypt > valgrind_output.txt 2>&1
    ```


## Contributing

Contributions and improvements to the program are welcome! Feel free to fork this repository, make changes, and submit pull requests.

## License

This program is licensed under the MIT License.


