#include <iostream>
#include <iomanip>
#include <stack>
#include "myStack.h"

//#define MAX 100//

using namespace std;

struct Pages
{
	string pageTitle;
	string pageDescription;
	string pageURL;
	string dateAccessed;
};

stackType<Pages> pageStack;
stackType<Pages> stackBack;
Pages page;

void displayPage(Pages p)
{
	cout << "Page Title: " << p.pageTitle << endl;
	cout << "Page Description: " << p.pageDescription << endl;
	cout << "URL: " << p.pageURL << endl;
	cout << "Date Accessed: " << p.dateAccessed << endl;
}

void goBack()
{
	if (!pageStack.isEmptyStack() && pageStack.stackTop > 1)
	{
		stackBack.push(pageStack.top());
		pageStack.pop();
		displayPage(pageStack.top());
	}
	else
		cout << "Unable to go back." << endl;
}

void goForward()
{
	if (!stackBack.isEmptyStack())
	{
		pageStack.push(stackBack.top());
		displayPage(pageStack.top());
	}
	else
		cout << "Unable to go forward." << endl;
}

void displayStack(stackType<Pages> pageStack)
{
	while (!pageStack.isEmptyStack())
	{
		cout << "Page " << pageStack.top().pageTitle << endl;
		pageStack.pop();
	}
}

int main()
{
	


	pageStack.initializeStack();

	int choice;
	do
	{
		cout << endl;
		cout << "Select an option from below:" << endl;
		cout << "1. Go Back" << endl;
		cout << "2. Go Forward" << endl;
		cout << "3. List All Pages" << endl;
		cout << "4. Add Page" << endl;
		cout << "5. Delete Page" << endl;
		cout << "0. Exit" << endl;
		cout << endl;

		cin >> choice;
		switch (choice)
		{
		case 0:
			return 0;
		case 1:
			goBack();
			break;
		case 2:
			goForward();
			break;
		case 3:
			displayStack(pageStack);
			break;
		case 4:
			cout << endl << "Enter the page title: ";
			cin >> page.pageTitle;
			cout << endl << "Enter the page description: ";
			cin >> page.pageDescription;
			cout << endl << "Enter the page URL: ";
			cin >> page.pageURL;
			cout << endl << "Enter the access date: ";
			cin >> page.dateAccessed;
			pageStack.push(page);
			cout << endl;
			displayPage(page);
			cout << endl;
			break;
		case 5:
			pageStack.pop();
			displayPage(page);
			cout << endl;
			break;
		default:
			cout << "Select one of the following options." << endl;
			break;
		}
	} while (choice != 0);
	return 0;

}