#define _CRT_SECURE_NO_WARNINGS
#include "Bank.h"
#include <string.h>
#include <iostream>
using namespace std;

// 계좌 개설.
Account::Account(int id, const String& name, int money)
: id(id), money(money), name(name)
{

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

String Account::GetName(void) const {
	return name;
}

int Account::GetMoney(void) const{
	return money;
}