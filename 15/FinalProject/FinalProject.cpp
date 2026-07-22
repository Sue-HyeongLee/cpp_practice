#include <iostream>
#include "Bank.h"
#include <stdlib.h>
#include "BankingCommonDec1.h"
#include "AccountException.h"
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
 객체 생성자할 떄 &를 붙여야 하는 이유는 객체 생성자 호출 시점 때문이다.
 1. int num = num과 같이 대입할 때
 2. 인자에 넣을 때 넣어지면서 객체 초기화된다.
 3. return할 때 임시변수/임시객체로 나와진다.
 2 번째 경우로 그래서 무한 굴레에 빠지기 떄문에 &를 무조건 붙여야한다.

 * 4단계
Bank와 Account에서 const 붙일 수 있는 멤버 함수들은 다 const 붙이기 (이미 해서 생략)

* 5단계 
controller class 만들기 사실 이미 Bank가 controller라 만들 필요는 없으나 Showmenu 관련된거만 추가.

* 6단계 상속을 이용해보자. NormalAccount class와 HighCreditClass를 만들자.
Bank에서 필요 이상의 수정은 하지말자. MakeAccount는 수정이 있을 수밖에 없다.

* 7단계 프로그램을 여러개로 나눠서 관리하자.
이미 나는 했었기에 NormalAccount, HighCreditAccount, BankingCommonDecl만 추가해주었다.
심지어 getCredit이 double을 반환하지 않고, int를 반환해 문제가 생긴 거 수정했다.

* 8단계 좀 많이 애먹었는데, Account 대입 연산자 오버라이딩과 객체 배열 class를 만드는 건데 이거 자체로 만드는덴 얼마 안들엇다.
다만 처음에는 Bank.h에서 AccountArray * customers;로 선언해 customers[i] = new Account(*(bank.customers[i]));
와 같은 모든 것들을 싹 다 (*customers)[i] = new Account(*(bank.(*customers)[i]));로 만들어줘야해서 고생했다.
하지만 생각해보니, 굳이 AccountArray * customers;로 선언할 필요 없이 AccountArray customers;로 선언해도
stack 영역관점에서 12바이트밖에 차지 않고, 나머지 부분은 어차피 안에서 알아서 new로 할당해주므로 상관 없다.
굳이 포인터를 쓰지 않았으면 훨씬 더 빨리 풀었을 문제.
AccountArray(int len=100); 이거 때문에 AccountArray 관련해서 정의를 안해주고 가도 되는 것도 컸다.
굳이 포인터를 써야할까 말아야할까가 고민되었던 문제. 포인터를 안써도되면 안쓰는게 좋다.

* 8단계는 중간에 구현하기 힘들어서 책의 도움을 받고 고민을 많이 해보았다. 아 그리고 Bank 통째로 복사하는 것도 안되게끔 delete해놓았다. 이것도 할 이유도 없고 하려면 굉장히 구현하기도 힘들다.

* 9단계는 String class 활용하기. Bank.cpp에 문제가 있어 수정도하였다.
12-1에서 구현했던 String class를 활용하니 account의 복사생성자, 대입연산자 오버라이딩, 소멸자의 필요가
사라졌다. String class내에 알아서 잘 구현되어있으니, 우리가 메모리할당을 하지 않아도 된다.
따라서 이러한게 사라짐을 볼 수 있다. account.h와 account.cpp이 많이 바뀌었다.
String을 우리 프로젝트에서 사용하면서 굉장히 편해졌다.
적절한 class의 정의는 우리를 매우 편하게 한다.

* 10단계 AccountArray를 BoundCheckArray로 우리가 배운 클래스 테플릿을 활용한다.
다양한 데이터에 적요할 수 있는 클래스 템플릿으로 Account *를 데이터 타입을 갖게해서 적용해본다.
마지막에 BoundCheckArray<Account *> customers;가 생각이 안 난 것이 크다. 그냥 정의하면 됐는데.

* 11단계 예외처리 해주기. 입출금할 떄 0보다 낮은 금액이 들어오거나, 출금할 때 기존 금액보다 큰 금액을 빠져나갈려하면
  예외처리로 해결해주어야한다. 

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
