#define _CRT_SECURE_NO_WARNINGS
#include "Bank.h"
#include <string.h>
#include <iostream>
using namespace std;

Account* customers[100];
int accnum = 0;

// 계좌 개설.
Account::Account(int id, char * name, int money)
: id(id), money(money)
{
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy(this->name, name);
}

// 입금
void Account::DepositMoney(int money) {

	this->money += money;

}

//출금

void Account::WithDrawMoney(int money) {

	this->money -= money;

}

//계좌 정보 전체 출력

void Account::ShowAllInfo(void) const {
		cout << "계좌ID: " << id << endl;
		cout << "이름: " << name << endl;
		cout << "잔액: " << money << endl;

		cout << endl;
	
}

int Account::GetID(void) const {
	return id;
}

char* Account::GetName(void) const {
	return name;
}

int Account::GetMoney(void) const{
	return money;
}

Account::~Account() {
	delete[]name;
}