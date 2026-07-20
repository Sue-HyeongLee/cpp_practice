#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include "NormalAccount.h"
using namespace std;

NormalAccount::NormalAccount(int id, const String& name, int money, int interest)
	:Account(id, name, money), interest(interest)
{

}

void NormalAccount::DepositMoney(int money) {
	Account::DepositMoney(money * (1 + 0.01 * interest));
}

int NormalAccount::GetInterest(void) const {
	return interest;
}