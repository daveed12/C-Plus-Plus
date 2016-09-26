#pragma once
#include <string>
using namespace std;
class Exception
{

	public:
		Exception();
		Exception(int num);
		const string GetErrorDescription();
		const int GetErrorCode();
	private:
		const int endOfFile = 1;
		const int readError = 2;
		const int couldNotOpen = 3;
		string error;
		int errorCode;
};

