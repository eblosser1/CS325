#include <iostream>
#include <queue>

using namespace std;

struct Patient
{
	string patientFirstName;
	string patientLastName;
	string patientInsurance;
	string patientSocialSecurity;
	string patientAddress;
	string patientVisitDate;
};

queue<Patient> patientQueue;
queue<Patient> queueBack;
Patient patients;

void enQueue()
{
	cout << endl << "Enter the patient's first name: ";
	cin >> patients.patientFirstName;
	cout << "Enter the patient's last name: ";
	cin >> patients.patientLastName;
	cout << "Enter the patient's insurance: ";
	cin >> patients.patientInsurance;
	cout << "Enter the patient's social security number: ";
	cin >> patients.patientSocialSecurity;
	cout << "Enter the patient's address: ";
	cin >> patients.patientAddress;
	cout << "Enter the patient's visit date: ";
	cin >> patients.patientVisitDate;
	patientQueue.push(patients);
}

void DeQueue()
{
	patientQueue.pop();
	cout << endl;
	cout << "******PATIENT HAS BEEN DELETED******" << endl;
}

void Peek(Patient p)
{
	cout << "Patient's First Name: " << p.patientFirstName << endl;
	cout << "Patient's Last Name: " << p.patientLastName << endl;
	cout << "Type of Insurance: " << p.patientInsurance << endl;
	cout << "Social Security Number: " << p.patientSocialSecurity << endl;
	cout << "Address: " << p.patientAddress << endl;
	cout << "Date of Visit: " << p.patientVisitDate << endl;
}

void IsEmpty()
{
	if (patientQueue.empty())
		cout << "No patients are currently scheduled." << endl;
}

void Size()
{
	patientQueue.size();
}

void previousPatient()
{
	if (!patientQueue.empty())
		Peek(queueBack.back());
	else
		cout << "Unable to go to previous patient." << endl;
}

void nextPatient()
{
	queueBack.push(patientQueue.front());
	patientQueue.pop();
	Peek(patientQueue.front());
}

int main()
{
	int choice;
	do
	{
		cout << endl;
		cout << "Select an option from below:" << endl;
		cout << "1. Add Patient" << endl;
		cout << "2. Next Patient" << endl;
		cout << "3. Previous Patient" << endl;
		cout << "4. Delete Patient" << endl;
		cout << "5. View Current" << endl;
		cout << "0. Exit" << endl;
		cout << endl;

		cin >> choice;
		switch (choice)
		{
		case 0:
			return 0;
		case 1:
			enQueue();
			break;
		case 2:
			nextPatient();
			break;
		case 3:
			previousPatient();
			break;
		case 4:
			DeQueue();
			break;
		case 5:
			Peek(patientQueue.front());
			break;
		default:
			cout << "Invalid choice. Select an optoin from below." << endl;
			break;
		}
	} while (choice != 0);
	return 0;
}

