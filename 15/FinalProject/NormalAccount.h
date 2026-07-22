#ifndef __NORMALCREDIT_H__ 
#define __NORMALCREDIT_H__ 

#include "Account.h"

class NormalAccount : public Account {
private:
	int interest;
public:
	NormalAccount(int id, const String& name, int money, int interest);
	void DepositMoney(int money) override;
	int GetInterest(void) const;
};

#endif
