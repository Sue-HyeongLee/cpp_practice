#pragma once

#include <iostream>
using namespace std;

class AccountException {
public:
	void virtual ShowException(void) = 0;
};

class OverDepositException :public AccountException {
private:
	int money;
public:
	OverDepositException(int money) 
		:money(money)
	{

	}
	void ShowException(void) override {
		cout << money << "는 현재 갖고 있는 금액보다 높습니다." << endl;
	}
};

class MinusMoneyException : public AccountException {
private:
	int money;
public:
	MinusMoneyException(int money) 
		: money(money)
	{

	}
	void ShowException(void) override {
		cout << money << "는 음수의 금액입니다." << endl;
	}
};