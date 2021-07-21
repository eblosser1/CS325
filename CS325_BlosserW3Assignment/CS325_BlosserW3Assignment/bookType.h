#include <iostream>
#include <string>

using namespace std;

class bookType
{
	friend ostream& operator<< (ostream&, const bookType&);

public:
	void setBookInfo(string author, string title, string publisher, string description, string ISBN, string year);
	void printInfo();
	bookType(string author = "", string title = "", string publisher = "", string description = "", string ISBN = "", string year = "");

	bool operator==(const bookType&) const;
	bool operator!=(const bookType&) const;

	string bookAuthor;
	string bookTitle;
	string bookPublisher;
	string bookDescription;
	string bookISBN;
	string yearPublished;
};

void bookType::setBookInfo(string author, string title, string publisher, string description, string ISBN, string year)
{
	bookAuthor = author;
	bookTitle = title;
	bookPublisher = publisher;
	bookDescription = description;
	bookISBN = ISBN;
	yearPublished = year;
}

void bookType::printInfo()
{
	cout << "Book Author: " << bookAuthor << endl;
	cout << "Book Title: " << bookTitle << endl;
	cout << "Book Publisher: " << bookPublisher << endl;
	cout << "Book Description: " << bookDescription << endl;
	cout << "Book ISBN: " << bookISBN << endl;
	cout << "Year Published: " << yearPublished << endl;
}

bool bookType::operator==(const bookType& other) const
{
	return (bookTitle == other.bookTitle);
}

bool bookType::operator!=(const bookType& other) const
{
	return (bookTitle != other.bookTitle);
}

ostream& operator<< (ostream& osObject, const bookType& book)
{
	osObject << endl;
	osObject << "Book Author: " << book.bookAuthor << endl;
	osObject << "Book Title: " << book.bookTitle << endl;
	osObject << "Book Publisher: " << book.bookPublisher << endl;
	osObject << "Book Description: " << book.bookDescription << endl;
	osObject << "Book ISBN: " << book.bookISBN << endl;
	osObject << "Year Published: " << book.yearPublished << endl;
	return osObject;
}

//MAIN.CPP
#include <iostream>
#include <fstream>
#include <string>

#include "bookType.h"
#include "bookListType.h"

using namespace std;

void createBookList(ifstream& infile, bookListType& bookList);
void displayMenu();

int main()
{
	bookListType bookList;
	int choice;
	char ch;
	string title;

	ifstream infile;
	infile.open("bookData.txt");
	if (!infile)
	{
		cout << "The input file does not exist." << endl;
		return 1;
	}

	createBookList(infile, bookList);
	infile.close();

	displayMenu();
	cout << "Enter your choice: ";
	cin >> choice;
	cin.get(ch);
	cout << endl;

	while (choice != 0)
	{
		switch (choice)
		{
		case 1:

		}
	}
}