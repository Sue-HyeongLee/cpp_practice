#ifndef __BANK_H__ 
#define __BANK_H__

class Account {
	int id;
	char* name;
	int money;

public:
	Account(int id, char* name, int money);

	Account(const Account& account);

	virtual void DepositMoney(int money);

	void WithDrawMoney(int money);

	void ShowAllInfo(void) const;

	int GetID(void) const;

	char* GetName(void) const;

	int GetMoney(void) const;

	virtual ~Account();

};

#endif
