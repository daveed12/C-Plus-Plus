#include "MyVector.h"

MyVector::MyVector()
{
	c = start;
	vector = new int[c]();
}

MyVector::MyVector(int n)
{
	c = n;
	vector = new int[c]();
}
int MyVector::capacity()
{
	return c;
}
int MyVector::size()
{
	int *p1 = vector;
	for (int i = 0; i < c; i++)
	{
		if (*p1 == 0)
		{
			s = i;
			break;
		}
		p1++;
	}
	return s;
}
void MyVector::clear()
{
	delete[] vector;
	c = start;
	s = 0;
	vector = new int[c]();
}
void MyVector::push_back(int n)
{	

	bool flag = true;
	int *p1 = vector;

	//If capacity equals zero
	if (c == 0)
	{
		c = start;
		vector = new int[c];
		*vector = n;
	}

	//Checks to see if there is an empty element in the array, if there is fill it in
	for (int i = 0; i < c; i++)
	{	
		
		if (*p1 == 0)
		{
			*p1 = n;
			flag = false;
			break;
		}
		p1++;
	}
	//If there is not an empty element in the array flag is changed to true and there is now a need to make a new array which is larger than the previous
	if (flag == true)
	{
		//Size of the array
		s = c;
		int *tmp = new int[c]();
		//Getting p1 back to the first element
		p1 = p1 - c;

		for (int i = 0; i < c; i++)
		{
			*tmp = *p1;
			tmp++;
			p1++;
		}
		//Getting pointers back to the first element & setting p1 to NULL
		tmp = tmp - c;
		p1 = NULL;
		
		//Increasing vector size
		int growth = s * start;
		c = growth;

		//Deletes old vector
		delete[] vector;

		//Makes new vector with new size
		vector = new int[c]();
		p1 = vector;

		for (int i = 0; i < c; i++)
		{

			if (i == s)
			{
				*p1 = n;
				break;
			}
			//Swaps plus increments over to next element in array
			*p1 = *tmp;
			tmp++;
			p1++;
		}
	}
	
}
int MyVector::at(int n)
{
	if (n >s -1)
	{
		throw(n);
	}
	int *p1 = vector;
	p1 = p1 + n;
	return *p1;
}
MyVector::~MyVector()
{
	if (vector != NULL)
	{
		delete[] vector;
	}
}
