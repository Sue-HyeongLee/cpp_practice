#ifndef __ACCOUNT_ARRAY_H__ 
#define __ACCOUNT_ARRAY_H__
#include "Account.h"

typedef Account* ACCOUNT_PTR;

class AccountArray {
private:
	ACCOUNT_PTR* arr;
	int arrlen;

	AccountArray(const AccountArray& arr) = delete;
	AccountArray& operator=(const AccountArray& arr) = delete;
public:
	AccountArray(int len=100);
	ACCOUNT_PTR& operator[] (int idx);
	ACCOUNT_PTR operator[] (int idx) const;
	int GetArrLen() const;
	~AccountArray();
};

#endif
