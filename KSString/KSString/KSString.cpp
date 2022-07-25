#define _CRT_SECURE_NO_WARNINGS
#include "KSString.h"


using namespace std;
KSString::KSString(std::string OuterString)
{
	length = OuterString.size();
	data = new char[length + 1];
	strcpy(data, OuterString.data());

}

int KSString::len()
{
	return this->length;
}

KSString& KSString::operator=(const string &str)
{

	delete[] data;
	length = str.size();
	data = new char[length + 1];
	strcpy(data, str.data());
	return *this;
}

KSString::~KSString()
{

}
