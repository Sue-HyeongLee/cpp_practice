#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Gun {
private:
	int bullet;
public:
	Gun(int bnum) :bullet(bnum) {
	
	}
	void Shot() {
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police {
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff) 
		: handcuffs(bcuff)
	{
		if (bnum > 0) {
			pistol = new Gun(bnum);
		}
		else
			pistol = NULL;
	}

	Police(const Police& police) 
		:handcuffs(police.handcuffs)
	{
		if (police.pistol == NULL) {
			pistol = NULL;
		}
		else {
			pistol = new Gun(*police.pistol);
		}
		
	}
	void PutHandcuff() {
		cout << "SNap!" << endl;
		handcuffs--;
	}
	void Shot() {
		if (pistol == NULL) {
			cout << "Hut Bang!" << endl;
		}
		else
			pistol->Shot();
	}

	Police& operator=(const Police& police) {
		if (pistol != NULL) {
			delete pistol;
		}
		if (police.pistol == NULL) {
			pistol = NULL;
		}
		else {
			pistol = new Gun(*police.pistol);
		}
		
		handcuffs = police.handcuffs;
		return *this;
	}

	~Police() {
		if (pistol != NULL) {
			delete pistol;
		}
	}
};

int main(void) {
	
	Police pman1(0, 3);
	Police pman2 = pman1;

	pman2.Shot();
	pman2.PutHandcuff();

	Police pman3(5,7);
	pman3.Shot();
	pman3.PutHandcuff();

	pman3 = pman2;
	pman3.Shot();
	pman3.PutHandcuff();
	
	return 0;
}