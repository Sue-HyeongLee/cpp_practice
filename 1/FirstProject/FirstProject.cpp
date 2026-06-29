#include <iostream>
#include "Bank.h"
#include <stdlib.h>
using namespace std;

/*
 통장의 계좌번호는 중복되지 아니한다.
 입금 및 출금액은 무조건 0보다 크다.
 고객의 계좌 정보는 계좌번호, 고객 이름, 고객의 잔액 세 가지만 저장 및 관리한다.
 둘 이상의 고객 정보 저장을 위해서 배열을 사용한다.
 계좌번호는 정수의 형태이다.
*/


int main(void) {

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
			Init();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithDrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
		

		cout << endl << endl;
	
	}
	return 0;
	
}
