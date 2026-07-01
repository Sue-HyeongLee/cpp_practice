#define _CRT_SECURE_NO_WARNINGS
#include "NameCard.h"
#include <iostream>
#include <cstring>

using namespace std;

NameCard::NameCard(const char* name, const char* company, const char* phone, int num)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);

	len = strlen(company);
	this->company = new char[len + 1];
	strcpy(this->company, company);

	len = strlen(phone);
	this->phone = new char[len + 1];
	strcpy(this->phone, phone);
	this->rank = num;
}

void NameCard::ShowNameCardInfo(void) {
	cout << "이름: " << name << endl;
	cout << "회사: " << company << endl;
	cout << "전화번호: " << phone << endl;
	cout << "직급: "; COMP_POS::ShowPositionInfo(rank);
	return;
}

NameCard::~NameCard() {
	delete []name;
	delete []company;
	delete []phone;
}

void COMP_POS::ShowPositionInfo(int pos) {
	switch (pos) {
	case CLERK:
		cout << "사원" << endl << endl;
		break;
	case SENIOR:
		cout << "주임" << endl << endl;
		break;
	case ASSIST:
		cout << "대리" << endl << endl;
		break;
	case MANAGER:
		cout << "과장" << endl << endl;
		break;
	}
}