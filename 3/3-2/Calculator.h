#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

class Calculator {
private:
	int add;
	int sub;
	int div;
	int mul;
public:
	void Init(void); // 설립
	double Add(double x, double y); // 덧셈
	double Min(double x, double y); // 뺄셈
	double Mul(double x, double y); // 곱셈
	double Div(double x, double y); // 나눗셈
	void ShowOpCount(void); // 보여줌
};

#endif