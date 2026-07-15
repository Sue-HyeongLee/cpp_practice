#ifndef __BANK_H__ 
#define __BANK_H__

#include "String.h"

class Account {
	int id;
	String name;
	int money;

public:
	Account(int id, const String& name, int money);

	virtual void DepositMoney(int money);

	void WithDrawMoney(int money);

	void ShowAllInfo(void) const;

	int GetID(void) const;

	String GetName(void) const;

	int GetMoney(void) const;

};

#endif
