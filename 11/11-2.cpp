#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


//실수한 점 delete 배열할 떄 delete[] 안 쓴거, strlen하고+1 안한거.
class Book {
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* title, const char* isbn, int price)
		:price(price)
	{
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);

		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->isbn, isbn);

		
	}

	Book(const Book& book) 
		: price(book.price)
	{
		title = new char[strlen(book.title) + 1];
		strcpy(title, book.title);
		isbn = new char[strlen(book.isbn) + 1];
		strcpy(isbn, book.isbn);
	}
	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}

	Book& operator=(const Book& book)
	{
		price = book.price;
		delete[] title;
		delete[] isbn;

		title = new char[strlen(book.title) + 1];
		strcpy(title, book.title);
		isbn = new char[strlen(book.isbn) + 1];
		strcpy(isbn, book.isbn);

		return *this;
	}

	~Book() {
		delete[]title;
		delete[]isbn;
	}
};

class EBook : public Book {
private:
	char* DRMKey;
public:
	EBook(const char* title, const char* isbn, int price, const char* DRMKey)
		:	Book(title, isbn, price)
	{
		this->DRMKey = new char[strlen(DRMKey) + 1];
		strcpy(this->DRMKey, DRMKey);
	}

	EBook(const EBook& ebook)
		: Book(ebook)
	{
		DRMKey = new char[strlen(ebook.DRMKey)+1];
		strcpy(DRMKey, ebook.DRMKey);
	}

	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}

	EBook& operator=(const EBook& ebook) {
		Book::operator=(ebook);
		delete[] DRMKey;

		DRMKey = new char[strlen(ebook.DRMKey) + 1];
		strcpy(DRMKey, ebook.DRMKey);
		return *this;
	}

	~EBook() {
		delete[] DRMKey;
	}
};

int main(void) {
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;

	Book book2("좋은 c", "512", 300);
	book2.ShowBookInfo();
	cout << endl;


	book2 = book;
	book2.ShowBookInfo();
	cout << endl;

	Book book3 = book;
	book3.ShowBookInfo();
	cout << endl;

	EBook ebook("좋은 c++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	cout << endl;

	EBook ebook2("좋은 c++++++ ebook", "555-12345-890-1", 150, "fdx9w0w");
	ebook2.ShowEBookInfo();
	cout << endl;

	ebook2 = ebook;
	ebook.ShowEBookInfo();
	cout << endl;

	EBook ebook3 = ebook;
	ebook3.ShowEBookInfo();
	cout << endl;
	return 0;
	
}