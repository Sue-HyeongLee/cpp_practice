#define _CRT_SECURE_NO_WARNINGS
#include "Bank.h"
#include <string.h>
#include <iostream>
using namespace std;

account customers[100];
int accnum = 0;

// 계좌 개설.
void Init(void){
	int id;
	char name[20];
	int money;

	cout << "계좌 id 입력해주세요: ";
	cin >> id;
	cout << "이름을 입력해주세요: ";
	cin >> name;
	cout << "고객의 잔액을 입력해주세요: ";
	cin >> money;

	customers[accnum].id = id;
	customers[accnum].money = money;
	strcpy(customers[accnum].name, name);
	accnum++;
}

// 입금
void DepositMoney(void) {
	int id;
	int input;
	cout << "[입    금]" << endl;
	cout << "계좌 ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> input;

	for (int i = 0; i < accnum; i++) {
		if (customers[i].id == id) {
			customers[i].money += input;
			cout << "입금완료" << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl << endl;

}

//출금

void WithDrawMoney(void) {
	int id;
	int sub;
	cout << "[출    금]" << endl;
	cout << "계좌 ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> sub;

	for (int i = 0; i < accnum; i++) {
		if (customers[i].id == id) {
			if (customers[i].money < sub) {
				cout << "잔액부족" << endl << endl;
				return;
			}
			customers[i].money -= sub;
			cout << "출금완료" << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl << endl;

}

//계좌 정보 전체 출력

void ShowAllAccInfo(void) {
	for (int i = 0; i < accnum; i++) {
		cout << "계좌ID: " << customers[i].id << endl;
		cout << "이름: " << customers[i].name << endl;
		cout << "잔액: " << customers[i].money << endl;

		cout << endl;
	}
}

