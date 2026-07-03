#ifndef __ACCOUNT_H__ 
#define __ACCOUNT_H__
#include "Account.h"
class Bank {
	Account** customers;
	int accnum;

public:
	Bank();
	void MakeAccount(void); // 새 계정 삽입.
	void DepositMoney(void);
	void WithDrawMoney(void);
	void ShowAllAccInfo(void) const;
	~Bank();
};

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

#endif