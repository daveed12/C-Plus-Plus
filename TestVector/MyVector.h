//David De La Cruz
//I didnt copy any code
//CS 1410

#pragma once
#include <iostream>
using namespace std;

const int start = 2;
class MyVector
{
	public:
		MyVector();
		MyVector(int n);
		~MyVector();
		int size();
		int capacity();
		void clear();
		void push_back(int n);
		int at(int n);
	private:
		int s;
		int c;
		int *vector;
};

