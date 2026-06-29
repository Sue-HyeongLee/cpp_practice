#include <iostream>

int main(void)
{
	int money= 0;
	int result = 0;
	while (true) {
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin >> money;
		if (money == -1)
			break;
		result = 50 + money * 0.12;
		std::cout << "이번 달 급여: " << result << "만원" << std::endl;
	}
	
	std::cout << "프로그램을 종료합니다." << std::endl;


}