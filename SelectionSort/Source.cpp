#include <string>
#include <iostream>

using namespace std;

//Parameters: Two integers passed by reference
//Returns: Nothing
//Purpose: Sets the first number equal to the second and the second equal to the first
void Swap(int &n1, int &n2);

int main()
{
	int num[] = { 3,5,2,1,15,21,12,4,19,2 };
	int size = sizeof(num)/sizeof(num[0]);
	//Loops in order to swap numbers (N^2 complexity)
	for (int i = 0; i <size -1;  i++)
	{
		if (num[i] > num[i + 1])
		{
			Swap(num[i + 1], num[i]);
			
		}
		for (int j = 0; j <size -1; j++)
		{
			if (num[j] > num[j + 1])
			{
				Swap(num[j + 1],num[j]);
			}
		}
		
	}
	//Prints each element in the array
	for (int i = 0; i < size; i++)
	{
		cout << num[i] << " ";
	}
	cout << "\n";
	system("PAUSE");

}

void Swap(int &n1, int &n2)
{
	int tmp = 0;
	tmp = n1;
	n1 = n2;
	n2 = tmp;
}