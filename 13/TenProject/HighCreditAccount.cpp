#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include "HighCreditAccount.h"
#include "BankingCommonDec1.h"
using namespace std;

HighCreditAccount::HighCreditAccount(int id, const String& name, int money, int interest, int credit)
	: NormalAccount(id, name, money, interest), credit(credit)
{

}

void HighCreditAccount::DepositMoney(int money) {
	Account::DepositMoney(money * (1 + 0.01 * GetInterest() + CREDIT_CONST::GetCredit(credit)));
}