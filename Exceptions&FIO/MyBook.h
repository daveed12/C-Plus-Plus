
#pragma once
#include "Author.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Exception.h"
using namespace std;

class MyBook
{
	public:
		MyBook();
		MyBook(Author a, string t, int pg, double pr);
		string GetTitle() const;
		int GetPages() const;
		double GetPrice() const;
		Author GetAuthor() const;
		void readData(ifstream &n);
		void writeData(ofstream &n);
	private:
		string title;
		int pages;
		double price;
		Author author;
		

};
