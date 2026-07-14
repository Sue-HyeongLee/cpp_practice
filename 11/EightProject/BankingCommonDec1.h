#ifndef __BANKINGCOMMON_H__ 
#define __BANKINGCOMMON_H__ 

namespace BANK_CONST {
	enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

	enum { NORMAL = 1, CREDIT = 2 };
}


namespace CREDIT_CONST {
	enum { A = 1, B = 2, C = 3 };

	double GetCredit(int credit);
}

#endif