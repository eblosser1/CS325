#include <iostream>
#include <iomanip>

using namespace std;

class computerType
{
	friend ostream& operator<< (ostream&, const computerType&);

public:
	void setComputerInfo(string code, string name, string os, string hardDrive, string ram, string price, int setInStock);
	int getNoOfCopiesInStock() const;
	void checkOut();
	void checkIn();
	void printTitle() const;
	void printInfo() const;
	bool checkCode(string code);
	void updateInStock(int num);
	void setCopiesInStock(int num);
	string getCode() const;
	computerType(string code = "", string name = "", string os = "", string hardDrive = "", string ram = "", string price = "", int setInStock = 0);

	bool operator==(const computerType&) const;
	bool operator!=(const computerType&) const;
	bool operator<(const computerType&) const;
	bool operator<=(const computerType&) const;
	bool operator>(const computerType&) const;
	bool operator>=(const computerType&) const;

private:
	string code;
	string name;
	string os;
	string hardDrive;
	string ram;
	string price;
	int copiesInStock;
};