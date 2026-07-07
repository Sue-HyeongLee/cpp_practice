#ifndef __HIGHCREDIT_H__ 
#define __HIGHCREDIT_H__ 

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount {
private:
	int credit;
public:
	HighCreditAccount(int id, char* name, int money, int interest, int credit);
	void DepositMoney(int money) override;
};
#endif