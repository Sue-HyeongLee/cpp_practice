#include <iostream>
#include "Bank.h"
#include <stdlib.h>
using namespace std;

/*
 
 * 1단계
 통장의 계좌번호는 중복되지 아니한다.
 입금 및 출금액은 무조건 0보다 크다.
 고객의 계좌 정보는 계좌번호, 고객 이름, 고객의 잔액 세 가지만 저장 및 관리한다.
 둘 이상의 고객 정보 저장을 위해서 배열을 사용한다.
 계좌번호는 정수의 형태이다.

 *2단계
 class를 만들어보자. 캡슐화와 은닉화는 어떻게? 생성자와 소멸자는 어떻게?
 version 0.1의 Account 구조체는 char형 배열을 뒀지만 동적 할당으로 생성해보자.(문자열 포인터)
 또한 객체를 저장하는 배열을 포인터로 만들어보자! 
*/


int main(void) {

	Bank* bank = new Bank;
	
	
	int select = 0;
	while (select != 5) {
		cout << "-----Menu------" << endl;
		cout << "1. 계좌 개설" << endl;
		cout << "2. 입금" << endl;
		cout << "3. 출금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택: ";

		cin >> select;

		cout << endl << endl;


		switch (select) {
		case MAKE:
			bank->MakeAccount();
			break;
		case DEPOSIT:
			bank->DepositMoney();
			break;
		case WITHDRAW:
			bank->WithDrawMoney();
			break;
		case INQUIRE:
			bank->ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
		

		cout << endl << endl;
	
	}

	delete bank;
	return 0;
	
}
