#include "Author.h"


//Default Constructor
Author::Author()
{
	name = "";
	address = "";
}
//Parameterized Constructor
Author::Author(string n, string a)
{
	name = n;
	address = a;
}
//Returns name of Author
string Author::GetName()
{
	return name;
}
//Returns Address of Author
string Author::GetAddress()
{
	return address;
}
void Author::writeData(ofstream &f)
{
	f << name << endl;
	f << address << endl;
}
void Author::readData(ifstream &f)
{
	int endOfFile = 1;
	int readError = 2;

	if (f.eof())
	{
		throw Exception(endOfFile);
	}
	if (f.bad() && !(f.eof()))
	{
		throw Exception(readError);
	}
	getline(f, name);
	getline(f, address);

}