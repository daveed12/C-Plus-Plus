#include "Exception.h"



Exception::Exception()
{
}

Exception::Exception(int num)
{
	if (num == endOfFile)
	{
		errorCode = num;
		error = "End of file reached";
	}
	else if (num == readError)
	{
		errorCode = num;
		error = "Error: Reading malfunction.";
	}
	else if (num == couldNotOpen)
	{
		errorCode = num;
		error = "Error: File could not be opened.";
	}
}

const string Exception::GetErrorDescription()
{
	return error;
}

const int Exception::GetErrorCode()
{
	return errorCode;
}
