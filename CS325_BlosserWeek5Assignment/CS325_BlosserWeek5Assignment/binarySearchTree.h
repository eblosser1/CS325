#include <iostream>
#include <iomainip>
#include "binaryTreeADT.h"

using namespace std;

template <class elemType>
struct nodeType
{
	elemType info; //store data in info
	nodeType<elemType>* lLink; //point to the left child
	nodeType<elemType>* rLink; //point to the right child

};

template <class elemType>
class bSearchTreeType : public binaryTreeType<elemType>
{
public:
	bool search(const elemType& searchItem) const; //determine if item is in search tree and returns true if found
	void insert(const elemType& insertItem); //insert item into search tree
	void deleteNode(const elemType& deleteItem); //delete item from search tree

protected:
	void deleteFromTree(nodeType<elemType>*& p); //delete node which p points to from the search tree
};

template <class elemType>
bool bSearchTreeType<elemType>::search(const elemType& searchItem) const
{
	nodeType<elemType>* current;
	bool found = false;

	if (root == nullptr)
		cout << "Cannot search an empty tree." << endl;
	else
	{
		current = root;

		while (current != nullptr && !found)
		{
			if (current->info == searchItem)
				found = true;
			else if (current->info > searchItem)
				current = current->lLink;
			else
				current = current->rLink;
		}
	}
	return found;
}

template <class elemType>
void bSearchTreeType<elemType>::insert(const elemType& insertItem)
{
	nodeType<elemType>* current; //pointer to traverse tree
	nodeType<elemType>* trailCurrent; //pointer to follow current
	nodeType<elemType>* newNode; //pointer to create node

	newNode = new nodeType<elemType>;
	newNode->info = insertItem;
	newNode->lLink = nullptr;
	newNode->rLink = nullptr;

	if (root == nullptr)
		root = newNode;
	else
	{
		currrent = root;

		while (current != nullptr)
		{
			trailCurrent = current;

			if (current->info == insertItem)
			{
				cout << "The item to be inserted is already in the tree -- duplicates are not allowed." << endl;
				return;
			}
			else if (current->info > insertItem)
				current = current->lLink;
			else
				current = current->rLink;
		}

		if (trailCurrent->info > insertItem)
			trailCurrent->lLink = newNode;
		else
			trailCurrent->rLink = newNode;
	}
}

template <class elemType>
void bSearchTreeType<elemType> ::deleteNode(const elemType& deleteItem)
{
	nodeType<elemType>* current; //pointer to traverse tree
	nodeType<elemType>* trailCurrent; // pointer to follow current
	bool found = false;

	if (root == nullptr)
		cout << "Cannot delete from an empty tree." << endl;
	else
	{
		current = root;
		trailCurrent = root;

		while (current != nullptr && !found)
		{
			if (current->info == deleteItem)
				found = true;
			else
			{
				trailCurrent = current;
				if (current->info > deleteItem)
					current = current->lLink;
				else
					current = current->rLink;
			}
		}
		if (current == nullptr)
			cout << "The item to be deleted is not in the tree." << endl;
		else if (found)
		{
			if (current == root)
				deleteFromTree(root);
			else if (trailCurrent->info > deleteItem)
				deleteFromTree(trailCurrent->lLink);
			else
				deleteFromTree(trailCurrent->rLink);
		}
		else
			cout << "The item to be delete is not in the tree." << endl;
	}
}

template <class elemType>
void bSearchTreeType<elemType>::deleteFromTree(nodeType<elemType>*& p)
{
	nodeType<elemType>* current; //pointer to traverse tree
	nodeType<elemType>* trailCurrent; //pointer to follow current
	nodeType<elemType>* temp; //pointer to delete node

	if (p == nullptr)
		cout << "Error: The node to be deleted does not exist." << endl;
	else if (p->lLink == nullptr && p->rLink == nullptr)
	{
		temp = p;
		p = nullptr;
		delete temp;
	}
	else if (p->lLink == nullptr)
	{
		temp = p;
		p = temp->rLink;
		delete temp;
	}
	else if (p->rLink == nullptr)
	{
		temp = p;
		p = temp->lLink;
		delete temp;
	}
	else
	{
		current = p->lLink;
		trailCurrent = nullptr;

		while (current->rLink != nullptr)
		{
			trailCurrent = current;
			current = current->rLink;
		}

		p->info = current->info;

		if (trailCurrent == nullptr)
			p->lLink = current->lLink;
		else
			trailCurrent->rLink = current->lLink;

		delete current;
	}
}
