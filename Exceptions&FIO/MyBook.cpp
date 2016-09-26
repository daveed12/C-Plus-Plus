#include "MyBook.h"


//Default Constructor
MyBook::MyBook()
{
	title = "";
	pages = 0;
	price = 0.00;

}
//Parameterized Constructor
MyBook::MyBook(Author a, string t, int pa, double pr)
{
	author = a;
	title = t;
	pages = pa;
	price = pr;
}
//Returns object of Class Author
Author MyBook::GetAuthor() const
{
	return author;
}
//Returns title of book
string MyBook::GetTitle() const
{
	return title;
}
//Returns amount of pages of book
int MyBook::GetPages() const
{
	return pages;
}
//Returns price of book
double MyBook::GetPrice() const
{
	return price;
}
void MyBook::writeData(ofstream &n)
{
	n << GetTitle() << endl;
	GetAuthor().writeData(n);
	n << GetPages() << endl;
	n << GetPrice() << endl;


}
void MyBook::readData(ifstream &n)
{
	int readError = 2;
	int endOfFile = 1;
	string bPrice = "";
	string bPages = "";

	if (n.eof())
	{
		throw Exception(endOfFile);
	}
	if (n.bad() && (!(n.eof())))
	{
		throw Exception(readError);
	}
	getline(n, title);
	author.readData(n);
	getline(n, bPrice);
	getline(n, bPages);
	try
	{
		if (!(stoi(bPrice)))
		{
			throw Exception(readError);
		}
		price = stoi(bPrice);
	}
	catch(Exception &f)
	{
		cout << f.GetErrorDescription() << endl;
	}
	try
	{
		if (!(stod(bPages)))
		{
			throw Exception(readError);
		}
		pages = stod(bPages);
	}
	catch (Exception &f)
	{
		cout << f.GetErrorDescription() << endl;
	}
}
