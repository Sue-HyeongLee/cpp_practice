#pragma once
#include <iostream>
using namespace std;

class String {
private:
	char* arr;
	friend ostream& operator<<(ostream& os, const String& str);
	friend istream& operator>>(istream& is, String& str);
public:
	String();
	String(const char* arr);
	String(const String& str);
	String& operator= (const String& str);
	~String();
	String operator+(const String& str) const;
	String& operator+=(const String& str);
	bool operator==(const String& str) const;
};

ostream& operator<< (ostream& os, const String& str);
istream& operator>> (istream& is, String& str);