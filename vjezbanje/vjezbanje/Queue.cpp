#include "pch.h"


class QNode
{
	friend class Queue;
private:
	int num;
	QNode* next;

public:
	QNode(int num) :num(num), next(nullptr) {}
};


class Queue
{
private:
	QNode* first;
	QNode* last;
	int totalNodes;

public:
	Queue() : first(nullptr), last(nullptr), totalNodes(0) {}

	int getTotalNodes() { return totalNodes; }

	int dequeue()
	{
		if (first == nullptr)
			return 0;

		if (first == last)
			last = nullptr;

		first = first->next;
		totalNodes--;
	}

	void enqueue(int num)
	{
		QNode* newNode = new QNode(num);
		totalNodes++;

		if (first == nullptr)
		{
			first = newNode;
			last = newNode;
			return;
		}

		last->next = newNode;
		last = newNode;
	}

	int peek()
	{
		if (first == nullptr)
			return 0;
		return first->num;
	}

	void printStack()
	{
		if (totalNodes == 0)
		{
			std::cout << "  [empty]";
		}
		else
		{
			QNode* temp = first;
			std::cout << temp->num;
			temp = temp->next;

			while (temp != nullptr)
			{
				std::cout << " <- " << temp->num;
				temp = temp->next;
			}
		}
	}
};


void DTQueue()
{
	int option;
	int num;
	Queue myQueue;

	while (true)
	{
		system("cls");
		std::cout << "\n\n\tQueue:    ";
		myQueue.printStack();
		std::cout << "\n\n\tChoose an option:"
			<< "\n\t\t1 - .dequeue()"
			<< "\n\t\t2 - .enqueue()"
			<< "\n\t\t3 - .top()"
			<< "\n\t\t10 - Exit";
		std::cout << "\n\n\t\tOption: ";
		std::cin >> option;

		if (option == 1)
		{
			if (myQueue.getTotalNodes() == 0)
			{
				std::cout << "\n\t\tQueue is empty!";
				std::cout << "\n\n\t\t";
				system("pause");
			}
			myQueue.dequeue();
		}
		else if (option == 2)
		{
			std::cout << "\n\t\tEnter the number: ";
			std::cin >> num;
			myQueue.enqueue(num);
		}
		else if (option == 3)
		{
			if (myQueue.getTotalNodes() == 0)
				std::cout << "\n\t\tQueue is empty!";
			else
				std::cout << "\n\t\tFirst in queue: " << myQueue.peek();
			std::cout << "\n\n\t\t";
			system("pause");
		}
		else if (option == 10)
			break;
		else
		{
			std::cout << "\n\t\tInvalid option!\n\n";
			system("pause");
		}
	}
}