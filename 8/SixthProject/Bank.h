#ifndef __ACCOUNT_H__ 
#define __ACCOUNT_H__
#include "Account.h"
namespace BANK_CONST {
	enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

	enum {NORMAL=1, CREDIT=2};
}


class Bank {
	Account** customers;
	int accnum;

public:
	Bank();
	Bank(const Bank& bank);
	void ShowMenu(void) const;
	void MakeAccount(void); // 새 계정 삽입.
	void DepositMoney(void);
	void WithDrawMoney(void);
	void ShowAllAccInfo(void) const;
	~Bank();
};

#endif