#define _CRT_SECURE_NO_WARNINGS
#include "BankingCommonDec1.h"

double CREDIT_CONST::GetCredit(int credit) {
	if (credit == A) {
		return 0.07;
	}
	else if (credit == B) {
		return 0.04;
	}
	else
		return 0.02;
}