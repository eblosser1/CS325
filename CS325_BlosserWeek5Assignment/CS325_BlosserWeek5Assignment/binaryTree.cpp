#include <iostream>
#include <fstream>
#include <string>
#include "binarySearchTree.h"
#include "computerType.h"
#include "computerBinaryTree.h"

using namespace std;

void createComputerList(ifstream& infile, computerBinaryTree& computerList);

void displayMenu();

int main()
{
	computerBinaryTree computerList;
	int choice;
	string title;

	ifstream infile;

	infile.open("Computer.txt");
	if (!infile)
	{
		cout << "The input file does not exist. Program ending..." << endl;
		return 1;
	}

	createComputerList(infile, computerList);
	infile.close();

	displayMenu();
	cout << "Enter your choice: ";
	cin >> choice;
	cin.ignore(100, '/n');

	cout << endl;

	while (choice != 9)
	{
		switch (choice)
		{
		case 1:
			cout << "Enter the title: ";
			getline(cin, title);
			cout << endl;

			if (computerList.computerSearch(title))
				cout << "The store carries " << title << endl;
			else
				cout << "The store does not carry " << title << endl;

			break;

		case 2:
			cout << "Enter the title: ";
			getline(cin, title);
			cout << endl;

			if (computerList.computerSearch(title))
			{
				if (computerList.isComputerAvailable(title))
				{
					computerList.computerCheckOut(title);
					cout << "Congratulations on your purchase!" << endl;
				}
				else
					cout << "Currently " << title << "is out of stock." << endl;
			}
			else
				cout << "The store does not carry " << title << endl;

			break;

		case 3:
			cout << "Enter the title: ";
			getline(cin, title);
			cout << endl;

			if (computerList.computerSearch(title))
			{
				computerList.computerCheckIn(title);
				cout << "Thank you for updating " << title << endl;
			}
			else
				cout << "The store does not carry " << title << endl;

			break;

		case 4:
			cout << "Enter the title: ";
			getline(cin, title);
			cout << endl;

			if (computerList.computerSearch(title))
			{
				if (computerList.isComputerAvailable(title))
					cout << title << " is currently in stock." << endl;
				else
					cout << title << " is currently out of stock." << endl;
			}
			else
				cout << "The store does not carry " << title << endl;

			break;

		case 5:
			computerList.computerPrintTitle();
			break;

		case 6:
			computerList.inorderTraversal();
			break;

		default: cout << "Invalid selection." << endl;
		}

		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore(100, '\n');

		cout << endl;
	}
	
	return 0;
}

void createComputerList(ifstream& infile, computerBinaryTree& computerList)
{
	string title;
	string star1;
	string star2;
	string producer;
	string director;
	string productCo;
	int inStock;

	computerType newComputer;

	getline(infile, title);

	while (infile)
	{
		getline(infile, star1);
		getline(infile, star2);
		getline(infile, producer);
		getline(infile, director);
		getline(infile, productionCo);
		infile >> inStock;
		infile.ignore(100, '\n');
		newComputer.setComputerInfo(title, star1, star2, producer, director, productionCo, inStock);
		computerList.insert(newComputer);

		getline(infile, title);
	}
}

void displayMenu()
{
	cout << "Select one of the follow:" << endl;
	cout << "1: To check whether the store carries a particular computer." << endl;
	cout << "2: To check out a computer." << endl;
	cout << "3: To check in a computer." << endl;
	cout << "4: To check if a computer is in stock." << endl;
	cout << "5: To print the titles of all the computers." << endl;
	cout << "6: To print a list of all the computers." << endl;
	cout << "9: To exit" << endl;
}