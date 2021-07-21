#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ifstream inFile;
ofstream outFile;

//define files
const string filePath = "C:/Users/eblosser/Documents/CS325/bookData.txt";
const string tempPath = "C:/Users/eblosser/Documents/CS325/bookData.tmp";

//create book struct
struct Book
{
	string bookAuthor;
	string bookTitle;
	string bookPublisher;
	string bookDescription;
	string bookISBN;
	string yearPublished;
};

//create library vector with struct data type
vector<Book> library;
vector<Book>::iterator bookIter;

//add element of struct
void addBook(string a, string t, string p, string d, string isbn, string year)
{
	Book book;
	book.bookAuthor = a;
	book.bookTitle = t;
	book.bookPublisher = p;
	book.bookDescription = d;
	book.bookISBN = isbn;
	book.yearPublished = year;

	cout << "Enter Author: ";
	cin >> a;
	cout << "Enter Book Title: ";
	cin >> t;
	cout << "Enter Book Publisher: ";
	cin >> p;
	cout << "Enter Book Description: ";
	cin >> d;
	cout << "Enter Book ISBN: ";
	cin >> isbn;
	cout << "Enter Year Published: ";
	cin >> year;
	library.push_back(book);

	//addBook(a, t, p, d, isbn, year);
	outFile.open(filePath, ios_base::app);
	outFile << a << endl
		<< t << endl
		<< p << endl
		<< d << endl
		<< isbn << endl
		<< year << endl;
	outFile.close();

	cout << "The book has been added." << endl;
	cout << endl;
}

void ReadFile(string filePath)
{
	string a, t, p, d, isbn, year;
	inFile.open(filePath);
	while (!inFile.eof())
	{
		inFile >> a >> t >> p >> d >> isbn >> year;
		//addBook(a, t, p, d, isbn, year);
	}
	inFile.close();
}

//remove element of struct
void removeBook(string filepath)
{
	string title;
	cout << "Enter title of book to be deleted: ";
	cin >> title;

	for (auto iter = library.begin(); iter != library.end(); iter++)
	{
		if (iter->bookTitle == title)
		{
			iter = library.erase(iter);
			break;
		}
	}

	inFile.open(filePath);
	ofstream temp;
	temp.open(tempPath);
	string tmp;
	while (!inFile.eof())
	{
		getline(inFile, tmp);
		if (tmp == title)
			break;
		temp << tmp << endl;
	}
	inFile.close();
	remove("C:/Users/eblosser/Documents/CS325/bookData.txt");
	temp.close();
	int result = rename("C:/Users/eblosser/Documents/CS325/bookData.tmp", "C:/Users/eblosser/Documents/CS325/bookData.txt");
	if (result == 0)
	{
		puts("File renamed successful.");
		cout << endl;
	}
	else
		perror("Error renaming file.");
		cout << endl;
}

//clear library
void deleteLibrary()
{
	library.clear();
	cout << "Inventory has been cleared." << endl;
	cout << endl;

	outFile.open("C:/Users/eblosser/Documents/CS325/bookData.txt", ofstream::out, ofstream::trunc);
	outFile.close();
}

//author search
void authorSearch()
{
	string author;
	cout << "Enter author to search: ";
	cin >> author;
	bool found = false;
	cout << author << endl;

	for (bookIter = library.begin(); bookIter != library.end(); ++bookIter)
	{
		cout << (*bookIter).bookAuthor;
	}

	/*for (auto it = library.begin(); it != library.end(); ++it)
		if ((*it).bookAuthor == author)
		{
			cout << (*it).bookAuthor;
			cout << (*it).bookTitle;
		}
		else
			cout << "Could not locate author." << endl;
	
	/*for (bookIter = library.begin(); bookIter != library.end(); bookIter++)
	{
		if (bookIter->bookAuthor == author)
		{
			cout << "Author: " << bookIter->bookAuthor << endl;
			cout << "Title: " << bookIter->bookTitle << endl;
		}
		else
			cout << "Could not locate author." << endl;
			cout << endl;
	}*/

	/*auto it = std::find_if(library.begin(), library.end(), [author](const Book& b) {
		return b.bookAuthor == author;
		});
	if (it != library.end())
	{
		cout << it->bookAuthor;
		cout << it->bookTitle;
	}*/	
}

//isbn search
void isbnSearch()
{
	string bookNumber;
	cout << "Enter ISBN to search: ";
	cin >> bookNumber;

	for (auto iter = library.begin(); iter != library.end(); iter++)
	{
		if (iter->bookISBN == bookNumber)
		{
			cout << "Author: " << iter->bookAuthor << endl;
			cout << "Title: " << iter->bookTitle << endl;
		}
		else
			cout << "Could not locate ISBN." << endl;
			cout << endl;
	}
}


int main()
{
	string a, t, p, d, isbn, year;
	ReadFile(filePath);
	int choice;
	do
	{
		cout << "Please choose an option." << endl;
		cout << "1. Add Book" << endl;
		cout << "2. Remove Book" << endl;
		cout << "3. Remove All Books" << endl;
		cout << "4. Search By Author" << endl;
		cout << "5. Search By ISBN" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			addBook(a, t, p, d, isbn, year);
			break;
		case 2:
			removeBook(filePath);
			break;
		case 3:
			deleteLibrary();
			break;
		case 4:
			authorSearch();
			break;
		case 5:
			isbnSearch();
			break;
		case 0:
			return 0;
		default:
			cout << "That is not a valid option." << endl;
			break;
		}


	} while (choice != 0);

	return 0;
}

