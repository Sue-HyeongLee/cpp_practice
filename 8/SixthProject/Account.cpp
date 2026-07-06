#define _CRT_SECURE_NO_WARNINGS
#include "Bank.h"
#include <string.h>
#include <iostream>
using namespace std;

int ACCOUNT_CONST::GetCredit(int credit) {
	if (credit == A) {
		return 0.07;
	}
	else if (credit == B) {
		return 0.04;
	}
	else
		return 0.02;
}

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

Account::Account(const Account& account)
	: id(account.id), money(account.money)
{
	name = new char[strlen(account.name) + 1];
	strcpy(name, account.name);
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

NormalAccount::NormalAccount(int id, char* name, int money, int interest) 
	:Account(id, name, money), interest(interest)
{

}

void NormalAccount::DepositMoney(int money) {
	Account::DepositMoney(money * (1 + 0.01 * interest));
}

int NormalAccount::GetInterest(void) const {
	return interest;
}

HighCreditAccount::HighCreditAccount(int id, char* name, int money, int interest, int credit) 
	: NormalAccount(id, name, money, interest), credit(credit)
{

}

void HighCreditAccount::DepositMoney(int money) {
	Account::DepositMoney(money * (1 + 0.01 * GetInterest()+ACCOUNT_CONST::GetCredit(credit)));
}