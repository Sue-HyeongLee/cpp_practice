#ifndef __BANK_H__ 
#define __BANK_H__

namespace ACCOUNT_CONST {
	enum { A = 1, B = 2, C = 3 };

	int GetCredit(int credit);
}

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

class NormalAccount : public Account {
private:
	int interest;
public:
	NormalAccount(int id, char* name, int money, int interest);
	void DepositMoney(int money) override;
	int GetInterest(void) const;
};

class HighCreditAccount : public NormalAccount {
private:
	int credit;
public:
	HighCreditAccount(int id, char* name, int money, int interest, int credit);
	void DepositMoney(int money) override;
};
#endif
