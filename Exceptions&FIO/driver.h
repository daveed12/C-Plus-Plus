//Author: David De La Cruz
//Exceptions&FIO

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Author.h"
#include "MyBook.h"
#include "Exception.h"

using namespace std;
// The displayBooks function
// Purpose: Display all of the data about a book
// Parameters: A vector of Book objects
// Returns: none
void displayBooks(const vector<MyBook>&books);

// The createTestFile function
// Purpose: Create a test file using the book data
// Parameters: none
// Returns: none
void createTestFile();

// The readTestFile function
// Purpose: Read the test file and display the results
// Parameters: none
// Returns: none
void readTestFile();

// The openFile function
// Purpose: Open a file for reading
// Parameters: an istream object and a file name
// Returns: none
// Throws a FileException if the file cannot be opened
void openFile(ifstream&, const string&);