#pragma once
#include <string>
#include <fstream>
#include "Exception.h"
using namespace std;

class Author
{
	public:
		Author();
		Author(string name, string address);
		string GetName();
		string GetAddress();
		void readData(ifstream &f);
		void writeData(ofstream &f);
	private:
		string name;
		string address;
		
};



