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

 * 2단계
 class를 만들어보자. 캡슐화와 은닉화는 어떻게? 생성자와 소멸자는 어떻게?
 version 0.1의 Account 구조체는 char형 배열을 뒀지만 동적 할당으로 생성해보자.(문자열 포인터)
 또한 객체를 저장하는 배열을 포인터로 만들어보자! 

 * 3단계
 복사 생성자를 활용하진 않지만 heap 영역을 사용할 경우, 얕은 복사는 문제가 될 수 있다. 따라서
 따라서 우리는 깊은 복사를 해야한다.
 객체 생성자할  &를 붙여야 하는 이유는 객체 생성자 호출 시점 때문이다.
 1. int num = num과 같이 대입할 때
 2. 인자에 넣을 때 넣어지면서 객체 초기화된다.
 3. return할 때 임시변수/임시객체로 나와진다.
 2 번째 경우로 그래서 무한 굴레에 빠지기 문에 &를 무조건 붙여야한다.

 * 4단계
Bank와 Account에서 const 붙일 수 있는 멤버 함수들은 다 const 붙이기 (이미 해서 생략)

* 5단계 
controller class 만들기 사실 이미 Bank가 controller라 만들 필요는 없으나 Showmenu 관련된거만 추가.

* 6단계 상속을 이용해보자. NormalAccount class와 HighCreditClass를 만들자.
Bank에서 필요 이상의 수정은 하지말자. MakeAccount는 수정이 있을 수밖에 없다.
*/


int main(void) {

	Bank* bank = new Bank;
	
	
	int select = 0;
	while (select != 5) {
		
		bank->ShowMenu();
		cin >> select;

		cout << endl << endl;


		switch (select) {
		case BANK_CONST::MAKE:
			bank->MakeAccount();
			break;
		case BANK_CONST::DEPOSIT:
			bank->DepositMoney();
			break;
		case BANK_CONST::WITHDRAW:
			bank->WithDrawMoney();
			break;
		case BANK_CONST::INQUIRE:
			bank->ShowAllAccInfo();
			break;
		case BANK_CONST::EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
		

		cout << endl << endl;
	
	}

	delete bank;
	return 0;
	
}
