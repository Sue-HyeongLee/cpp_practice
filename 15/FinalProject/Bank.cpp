#define _CRT_SECURE_NO_WARNINGS
#include "Bank.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDec1.h"
#include "String.h"
#include "AccountException.h"
#include <cstring>
#include <iostream>
using namespace std;


Bank::Bank() 
	:accnum(0)
{

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
	int select;
	int id;
	String name;
	int money;
	int interest;
	int credit;

	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2. 신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> select;
	cout << "계좌 id 입력해주세요: ";
	cin >> id;
	cout << "이름을 입력해주세요: ";
	cin >> name;
	cout << "고객의 잔액을 입력해주세요: ";
	cin >> money;
	cout << "이자율: ";
	cin >> interest;
	if (select == BANK_CONST::NORMAL) {
		customers[accnum] = new NormalAccount(id, name, money, interest);
		
	}
	if (select == BANK_CONST::CREDIT) {
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> credit;
		customers[accnum] = new HighCreditAccount(id, name, money, interest, credit);
	}

	
	accnum++;
	return;
}

void Bank::DepositMoney(void){
	int id;
	int input;
	cout << "[입    금]" << endl;
	cout << "계좌 ID: ";
	cin >> id;
	while (true) {
		cout << "입금액: ";
		cin >> input;
		try {
			for (int i = 0; i < accnum; i++) {
				if (customers[i]->GetID() == id) {
					customers[i]->DepositMoney(input);
					cout << "입금완료" << endl;
					return;

				}
			}
			cout << "유효하지 않은 ID입니다." << endl << endl;
		}
		catch (AccountException& expn) {
			expn.ShowException();
			cout << "입금액만 재 입력해주세요."<<endl;
		}
	}
	
	
}

void Bank::WithDrawMoney(void) {
	int id;
	int sub;
	cout << "[출    금]" << endl;
	cout << "계좌 ID: ";
	cin >> id;
	while (true) {
		try {
			cout << "출금액: ";
			cin >> sub;
			for (int i = 0; i < accnum; i++) {
				if (customers[i]->GetID() == id) {
					customers[i]->WithDrawMoney(sub);
					cout << "출금완료" << endl;
					return;
				}
			}
			cout << "유효하지 않은 ID입니다." << endl << endl;
		}
		catch (AccountException& expn) {
			expn.ShowException();
			cout << "출금액을 재입력해주세요." << endl;
		}
	}
	
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
}