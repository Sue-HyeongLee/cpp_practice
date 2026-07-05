#define _CRT_SECURE_NO_WARNINGS
#include "Bank.h"
#include "Account.h"
#include <string.h>
#include <iostream>
using namespace std;


Bank::Bank() {
	customers = new Account*[100];
	accnum = 0;
	
}

Bank::Bank(const Bank& bank) {
	customers = new Account * [100];
	for (int i = 0; i < bank.accnum; i++)
		customers[i] = new Account(*(bank.customers[i])); //와 여기도 이렇게 새로 해줘야하지.
	accnum = bank.accnum;
}

void Bank::ShowMenu(void) const {
	cout << "-----Menu------" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
}

void Bank::MakeAccount(void) {
	int id;
	char name[50];
	int money;
	cout << "계좌 id 입력해주세요: ";
	cin >> id;
	cout << "이름을 입력해주세요: ";
	cin >> name;
	cout << "고객의 잔액을 입력해주세요: ";
	cin >> money;
	customers[accnum] = new Account(id, name, money);
	accnum++;
}

void Bank::DepositMoney(void) {
	int id;
	int input;
	cout << "[입    금]" << endl;
	cout << "계좌 ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> input;

	for (int i = 0; i < accnum; i++) {
		if (customers[i]->GetID() == id) {
			customers[i]->DepositMoney(input);
			cout << "입금완료" << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl << endl;
}

void Bank::WithDrawMoney(void) {
	int id;
	int sub;
	cout << "[출    금]" << endl;
	cout << "계좌 ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> sub;

	for (int i = 0; i < accnum; i++) {
		if (customers[i]->GetID() == id) {
			if (customers[i]->GetMoney() < sub) {
				cout << "잔액부족" << endl << endl;
				return;
			}
			customers[i]->WithDrawMoney(sub);
			cout << "출금완료" << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl << endl;
}

void Bank::ShowAllAccInfo(void) const {
	for (int i = 0; i < accnum; i++) {
		customers[i]->ShowAllInfo();
	}
	cout << endl << endl;
}

Bank::~Bank() {

	for (int i = 0; i < accnum; i++) {
		delete customers[i]; //이거 깜빡했다.
	}
	delete []customers;
}