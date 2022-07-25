#pragma once
#include "iostream"
#include <string.h>

class KSString
{
private:
	char* data;
	int length;
public:
	KSString();
	~KSString();
	KSString(std::string OuterString);


	KSString& operator=(const std::string& );


	int len();

};

