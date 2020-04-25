#include "pch.h"


void picalculator();
void ContainsCommonItem();
void mergeArrays();
void twoSum();
void moveZeroes();


class Node
{
	friend class LinkedList;
private:
	int number;
	Node* next;

public:
	Node(int number) : number(number), next(nullptr) {}
};

class LinkedList
{
private:
	Node* head;
	Node* tail;

public:
	LinkedList() : head(nullptr), tail(nullptr) {}

	void addNode(int num)
	{
		Node* newNode = new Node(num);
		tail = head;

		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node* current = head;
			Node* previous = nullptr;

			while (current != nullptr)
			{
				if (current->number < newNode->number)
					break;

				previous = current;
				current = current->next;
			}

			if (current == head)
			{
				newNode->next = head;
				head = newNode;
			}
			else
			{
				newNode->next = current;
				previous->next = newNode;
			}
			tail = previous->next;	//bug
		}
	}

	void appendNode(int num)
	{
		Node* newNode = new Node(num);
		tail->next = newNode;
		tail = newNode;
	}

	void printNodes()
	{
		Node* current = head;
		int i = 1;
		std::cout << "\n\n\tFirst number in the list: " << head->number;
		while (current != nullptr)
		{
			std::cout << "\n\n\tNumber in the " << i << ". node: " << current->number;
			i++;
			current = current->next;
		}
		std::cout << "\n\n\tLast number in the list: " << tail->number;
	}
};


int main()
{
	int a;
	LinkedList myList;

	myList.addNode(11);
	myList.addNode(12);
	myList.addNode(9);
	myList.appendNode(8);
	myList.appendNode(1);
	

	myList.printNodes();
}