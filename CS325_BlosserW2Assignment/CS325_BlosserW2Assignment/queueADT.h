#ifndef H_QueueADT
#define H_QueueADT

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

template <class Type>
class queueADT
{
public:
	virtual void initializeQueue() = 0;
	//Method to initialize the queue to an empty state.
	//Postcondition: queue is empty.

	virtual bool isEmptyQueue() const = 0;
	//Function to determine whether the queue is empty.
	//Postcondition: Returns true if the queue is empy,
	//		otherwise returns false.

	virtual bool isFullQueue() const = 0;
	//Function to determine whether the queue is full.
	//Postcondition: Returns true if the queue is full,
	//		otherwise returns false.

	virtual Type front() const = 0;
	//Function to return the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program
	//		terminates; otherwise, the top element
	//		of the queue is returned

	virtual Type back() const = 0;
	//Function to return the last element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program
	//		terminates; otherwise, the last element
	//		of the queue is returned

	virtual void addQueue(const Type& queueElement) = 0;
	//Function to add queueElement to the queue.
	//Precondition: The queue exists and is not full.
	//Postcondition: The queue is changed and queueElement
	//		is added to the top of the queue.

	virtual void deleteQueue() = 0;
	//Function to remove the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: The queue is changed and the first
	//		element is removed from the queue.
};
#endif

