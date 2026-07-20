#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "String.h"

String::String() {
	this->arr = NULL;
}

String::String(const char* arr) {
	this->arr = new char[strlen(arr) + 1];
	strcpy(this->arr, arr);
}

String::String(const String& str) {
	this->arr = new char[strlen(str.arr)+1];
	strcpy(this->arr, str.arr);
}

String& String::operator= (const String& str) {
	delete[] this->arr;
	this->arr = new char[strlen(str.arr) + 1];
	strcpy(this->arr, str.arr);
	return *this;
}

String:: ~String() {
	delete[]arr;
}

String String::operator+(const String& str) const {
	char* temp = new char[strlen(arr) + strlen(str.arr) + 1];
	strcpy(temp,arr);
	strcat(temp, str.arr);
	String new_str(temp);
	delete[] temp;
	return new_str;

}

String& String::operator+=(const String& str) {
	char* temp = new char[strlen(arr) + strlen(str.arr) + 1];
	strcpy(temp, arr);
	strcat(temp, str.arr);
	delete[] arr;
	arr = temp;
	return *this;
}

bool String::operator==(const String& str) const {
	if (strcmp(arr, str.arr) == 0) {
		return true;
	}
	else
		return false;
}

ostream& operator<< (ostream& os, const String& str) {
	os << str.arr;
	return os;
}

istream& operator>> (istream& is, String& str) {
	char s[100];
	cin >> s;
	str = String(s);
	return is;
}