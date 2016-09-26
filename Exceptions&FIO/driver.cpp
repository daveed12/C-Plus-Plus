//Author: David De La Cruz
// Date last modified: September 2016
#include "driver.h"

const int READERROR = 2;

int main()
{
	// Display Menu 
	int option = 0;
	const int CREATE = 1;
	const int READ = 2;

	cout << "\nSelect one of the following two options: ";
	cout << "\n   1 - create a test file";
	cout << "\n   2 - read the test file and display the results";
	cout << "\n>> ";

	// run the selected option
	cin >> option;
	if (option == CREATE)
	{
		createTestFile();
		cout << "\nTest file has been created.";
	}
	else if (option == READ)
	{
		readTestFile();
	}
	else
	{
		cout << "\nInvalid option.";
	}

	system("PAUSE");
	return 0;
}

void createTestFile()
{
	int pages[] = { 256, 400, 322 };
	double price[] = { 24.95, 12.99, 14.29 };
	// create a vector for storing the account objects
	vector<MyBook> books;


	// create three Author objects
	Author p1("J.K.Rowling", "Edinburgh, Scotland");
	Author p2("Suzanne Collins", "Connecticut, USA");
	Author p3("J.R.R. Tolkien", "Bournmouth, England");

	// Create three Book objects
	MyBook b1(p1, "Harry Potter and the Sorcerer's Stone", pages[0], price[0]);
	MyBook b2(p2, "Mockingjay", pages[1], price[1]);
	MyBook b3(p3, "The Hobbit", pages[2], price[2]);

	// add the books to the vector
	books.push_back(b1);
	books.push_back(b2);
	books.push_back(b3);

	ofstream outputFile;
	outputFile.open("bookData.txt");
	for (unsigned i = 0; i < books.size(); i++) 
	{
		books[i].writeData(outputFile);
	}
}
void displayBooks(const vector<MyBook> &books)
{
	int precision = 2;
	
	for (int i = 0; i < books.size(); i++)
	{	
		cout << books[i].GetTitle() << endl;
		cout << books[i].GetAuthor().GetName() << endl;
		cout << books[i].GetAuthor().GetAddress() << endl;
		cout << books[i].GetPages() << " pages" << endl;
		cout << fixed << setprecision(precision)<< "$" << books[i].GetPrice() << "\n\n";
	}
}
void readTestFile()
{
	vector<MyBook> books;
	ifstream readFile;
	try 
	{
		openFile(readFile, "bookData.txt");
	}
	catch (Exception &f)
	{
		cout << f.GetErrorDescription() << endl;
		return;
	}
	int i = 0;
	do
	{
		MyBook text;
		try
		{
			text.readData(readFile);
			books.push_back(text);
		}
		catch (Exception &e)
		{
			if (e.GetErrorCode() == 1)
			{
				readFile.close();
			}
			else if (e.GetErrorCode() == READERROR)
			{
				cout << e.GetErrorDescription() << endl;
				return;
			}
		}
	} while(!(readFile.eof()));
	displayBooks(books);
}
void openFile(ifstream& in, const string& _name)
{
	int failOpen = 3;
	in.open(_name);
	if (in.fail()) 
	{
		throw Exception(failOpen);
	}
}