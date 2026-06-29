#include <iostream>

int main(void)
{
	int num;

	std::cout << "Enter a number: ";
	std::cin >> num;

	for (int i = 1; i <= 9; i++) {
		std::cout << num << " x " << i << " = " << num * i << std::endl;
	}
}