#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include "String.h"

/*
	햇갈렸던 부분들이 너무 많아 String class를 정의해보는 것이 쉬울줄 알았는데 어려웠다.
	특히 operator>>를 정의하는 부분에서 일단 String을 NULL로 되었을 때 넣으려고 한 부분에서
	1차 에러 그리고, 배열로 정의되지 않은 char pointer에 cin.operator<<을 하려했던 점도 안
	되서 에러였다.

	그래서 책에서의 방법은 char s 배열을 안에서 정의 후, 거기다 cin<<s를 한 후 그 s를 바탕으로
	대입 연산을 String객체에 하는 방법이었다.

	그리고 operaotor+나 operaotr+=을 할 때 새로운 char 배열을 생성했어야 했다.
	+는 확실하지만, +=할 때는 그냥 strcat을 붙였다가 낭패봤는데, 왜냐면 바로 붙이면
	내가 처음에 new로 정했던 할당 크기를 당연히 넘기 때문이다..

	다른 문제들은 strlen하고+1로 NULL자리 넣어주기, delete할 때 []빼먹기 등등이 있었다.
*/

int main(void) {
	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
		cout << "동일 문자열!" << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;

	String str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;
}