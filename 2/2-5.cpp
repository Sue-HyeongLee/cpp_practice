#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(void) {
	char str1[30] = "Hi!";
	char str2[30] = " I'm Sue";
	char str3[30];
	int len = strlen(str1);
	strcat(str1, str2);
	strcpy(str3, str2);
	cout << len << endl;
	cout << str1 << endl;
	cout << str3<<endl;


	if (!strcmp(str2, str3))
		cout << "같은 문자열입니다!" << endl;

	
	

}