#include <iostream>
#include <iomanip>
#include <queue>
#include "myQueue.h"

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

queueType<Patient> patientQueue;
queueType<Patient> queueBack;
Patient patients;

void displayPatient(Patient p)
{
	cout << "Patient's First Name: " << p.patientFirstName << endl;
	cout << "Patient's Last Name: " << p.patientLastName << endl;
	cout << "Type of Insurance: " << p.patientInsurance << endl;
	cout << "Social Security Number: " << p.patientSocialSecurity << endl;
	cout << "Address: " << p.patientAddress << endl;
	cout << "Date of Visit: " << p.patientVisitDate << endl;
}

void previousPatient()
{
	if (!patientQueue.isEmptyQueue())
		displayPatient(queueBack.back());
	else
		cout << "Unable to go to previous patient." << endl;
}

void nextPatient()
{
	queueBack.addQueue(patientQueue.front());
	patientQueue.deleteQueue();
	displayPatient(patientQueue.front());
}

int main()
{
	patientQueue.initializeQueue();

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
			cout << endl << "Enter the patient's first name: ";
			cin >> patients.patientFirstName;
			cout << endl << "Enter the patient's last name: ";
			cin >> patients.patientLastName;
			cout << endl << "Enter the patient's insurance: ";
			cin >> patients.patientInsurance;
			cout << endl << "Enter the patient's social security number: ";
			cin >> patients.patientSocialSecurity;
			cout << endl << "Enter the patient's address: ";
			cin >> patients.patientAddress;
			cout << endl << "Enter the patient's visit date: ";
			cin >> patients.patientVisitDate;
			patientQueue.addQueue(patients);
			break;
		case 2:
			nextPatient();
			break;
		case 3:
			previousPatient();
			break;
		case 4:
			patientQueue.deleteQueue();
		case 5:
			displayPatient(patientQueue.front());
			break;
		default:
			cout << "Select an optoin from below." << endl;
			break;
		}
	} while (choice != 0);
	return 0;
}