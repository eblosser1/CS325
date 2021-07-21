#include <iostream>
#include <string>
#include <set>

using namespace std;

//create set for unique elements
set<int> graph[10000];

struct Set
{
	int memberID{};
	string memberName;
	string memberGender;
	string memberStatus;

};

//create object.
Set info[10000];

//add member
void addMember(int id, string name, string gender, string status)
{

	info[id].memberID = id;
	info[id].memberName = name;
	info[id].memberGender = gender;
	info[id].memberStatus = status;

	cout << "Member successfully added." << endl;
}

//delete friend
void deleteMember(int id)
{

	for (auto x : graph[id])
	{
		graph[x].erase(graph[x].find(id));
	}

	graph[id].clear();

	cout << "Member " << id << " deleted" << endl;
}

//add friend
void addFriend(int id, int frnd)
{

	// adding friend to list
	graph[id].insert(frnd);
	graph[frnd].insert(id);

	cout << "Friend added" << endl;
}

//print friend list
void printFriendList(int id)
{
	cout << endl;
	cout << info[id].memberName << "'s friends are: " << endl;
	int count = 1;
	
	for (auto frnd : graph[id])
	{
		cout << "Friend " << count << ": " << endl;
		cout << "Member ID: " << info[frnd].memberID << endl;
		cout << "Name: " << info[frnd].memberName << endl;
		cout << "Gender: " << info[frnd].memberGender << endl;
		cout << "Status: " << info[frnd].memberStatus << endl;
		cout << endl;
		count++;
	}
	cout << endl;
}

//print menu
int menu()
{
	int userChoice;
	cout << endl;
	cout << "1. Add member" << endl;
	cout << "2. Delete Member" << endl;
	cout << "3. Add Friend" << endl;
	cout << "4. List Friends" << endl;
	cout << "5. Exit" << endl;
	cout << "Enter the user choice: ";
	cin >> userChoice;

	return userChoice;
}

//get member information
void addUser()
{
	int memID;
	string memName, memGender, memStatus;
	cout << "Enter Member ID: ";
	cin >> memID;
	cout << "Enter Name: ";
	cin >> memName;
	cout << "Enter Gender: ";
	cin >> memGender;
	cout << "Enter Status: ";
	cin >> memStatus;

	addMember(memID, memName, memGender, memStatus);

}

//get user id to be deleted
void deleteUser()
{
	int memID;
	cout << "Enter member id: ";
	cin >> memID;

	deleteMember(memID);
}

//add friend to friend list
void addFrnd()
{
	int memID;
	cout << "Enter member id of the friend: ";
	cin >> memID;

	addFriend(1, memID);
}

//user select action
void operation(int userChoice)
{
	switch (userChoice)
	{
	case 1:
		addUser();
		break;
	case 2:
		deleteUser();
		break;
	case 3:
		addFrnd();
		break;
	case 4:
		printFriendList(1);
		break;
	case 5:
		exit(0);
		break;
	default:
		cout << "Invalid Choice" << endl;
		break;
	}
}

int main()
{
	cout << "Welcome to the Member Management Program" << endl;

	int userChoice = 4;

	while (userChoice != 5)
	{
		userChoice = menu();
		operation(userChoice);

	}

	cout << "Thank you for visiting..." << endl;

	return 0;
}