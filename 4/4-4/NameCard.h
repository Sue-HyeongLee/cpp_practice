#pragma once
#include <iostream>
using namespace std;
namespace COMP_POS {
	enum {CLERK, SENIOR, ASSIST, MANAGER};

	void ShowPositionInfo(int pos);
}

class NameCard {
private:
	char * name;
	char* company;
	char* phone;
	int rank;
public:
	NameCard(const char* name, const char* company, const char* phone, int num);
	void ShowNameCardInfo(void);
	~NameCard();


};
