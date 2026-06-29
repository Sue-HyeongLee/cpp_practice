#ifndef __BANK_H__ 
#define __BANK_H__

typedef struct {
	int id;
	char name[50];
	int money;
} account;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
extern account customers[100];
extern int accnum;

void Init(void);

void DepositMoney(void);

void WithDrawMoney(void);

void ShowAllAccInfo(void);
#endif
