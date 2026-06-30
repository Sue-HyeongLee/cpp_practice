#ifndef __PRINTER_H__
#define __PRINTER_H__

namespace PRINTER_CONST {
	enum {
		PRINT_LEN = 30
	};
}


class Printer {
private:
	char str[PRINTER_CONST::PRINT_LEN];
public:
	void SetString(const char* str);
	void ShowString(void);
};

#endif
