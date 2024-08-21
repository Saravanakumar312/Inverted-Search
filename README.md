
# Inverted Search Project

## Overview
The Inverted Search project is a file management and searching tool that creates an inverted index from a set of text files. This index allows efficient searching of words across multiple files, providing information on where each word appears and how frequently.

## Features
- **Create Database**: Reads multiple text files and builds an inverted index, associating each word with the files in which it appears.
- **Display Database**: Prints the contents of the database, showing the words and their occurrences across different files.
- **Update Database**: Updates the existing database when new files are added, ensuring the index stays current.
- **Search**: Allows users to search for a specific word across the indexed files and displays the results, including the frequency of the word in each file.
- **Save Database**: Saves the current state of the database to a file for later use.

## Files and Directories

### Source Files
- **`main.c`**: Contains the `main` function that drives the program, handles user input, and invokes appropriate operations (create, display, update, search, save).
- **`inverted_search.h`**: Header file defining structures, macros, and function prototypes used across the program.
- **`file_list.c`**: Contains functions related to file list management, including validation and file list creation.
- **`display_database.c`**: Implements functions to display the contents of the database.
- **`insert.c`**: Contains functions for inserting words and updating the word list.
- **`search.c`**: Implements the search functionality to find words in the indexed files.
- **`update.c`**: Provides functions to update the database with new or modified files.
- **`save_db.c`**: Contains functions to save the current state of the database to a file.

### Compilation
To compile the project, use the following command:

```bash
gcc -o inverted_search main.c file_list.c display_database.c insert.c search.c update.c save_db.c
```

### Running the Program
After compilation, you can run the program by providing text files as command-line arguments:

```bash
./inverted_search file1.txt file2.txt file3.txt
```

### Usage
Upon running the program, you will be prompted with options to create, display, update, search, or save the database. Simply enter the number corresponding to your choice.

## Example
Here’s a simple example of how to use the program:

```bash
$ ./inverted_search file1.txt file2.txt
Select your choice among following options:
1. Create DATABASE
2. Display DATABASE
3. Update DATABASE
4. Search
5. Save DATABASE
6. Exit
Enter your choice: 1
```

## Contributing
Contributions are welcome! Please feel free to submit a Pull Request with your changes.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact
If you have any questions or suggestions, please feel free to reach out to me at [saravanakumar3129@gmail.com](mailto:saravanakumar3129@gmail.com).
```

Feel free to adjust any part of this file to better fit your project's specifics or your preferences.
