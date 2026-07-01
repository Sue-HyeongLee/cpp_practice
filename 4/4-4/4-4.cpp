#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "NameCard.h"
using namespace std;

int main(void) {

	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manASSIST("KIM", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manASSIST.ShowNameCardInfo();
	
}