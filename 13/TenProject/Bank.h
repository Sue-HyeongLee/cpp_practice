#ifndef __BANK_H__ 
#define __BANK_H__
#include "Account.h"
#include "BoundCheckArray.h"

class Bank {
	BoundCheckArray<Account*> customers;
	int accnum;
public:
	Bank();
	Bank(const Bank& bank) = delete;
	void ShowMenu(void) const;
	void MakeAccount(void); // 새 계정 삽입.
	void DepositMoney(void);
	void WithDrawMoney(void);
	void ShowAllAccInfo(void) const;
	~Bank();
};

#endif