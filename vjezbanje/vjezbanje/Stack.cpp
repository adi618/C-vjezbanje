#include "pch.h"


class SNode
{
	friend class Stack;
private:
	int num;
	SNode* next;

public:
	SNode(int num) :num(num), next(nullptr) {}
};


class Stack
{
private:
	SNode* top;
	int totalNodes;

public:
	Stack() : top(nullptr), totalNodes(0) {}

	int getTotalNodes() { return totalNodes; }

	int pop()
	{
		if (top == nullptr)
			return 0;

		SNode* temp = top;

		top = top->next;
		totalNodes--;

		return temp->num;
	}

	void push(int num)
	{
		SNode* newNode = new SNode(num);
		totalNodes++;

		if (top == nullptr)
		{
			top = newNode;
			return;
		}
		SNode* temp = top;

		top = newNode;
		top->next = temp;
	}

	int peek()
	{
		return top->num;
	}

	void printStack()
	{
		SNode* temp = top;

		if (totalNodes == 0)
		{
			std::cout << "  [empty]";
		}
		else
		{
			std::cout << "  -----\n";
			while (temp != nullptr)
			{
				std::cout << "\t\t| " << temp->num << " |\n";
				temp = temp->next;
			}
			std::cout << "\t\t-----";
		}
	}
};


void ZTMstack()
{
	int option;
	int num;
	Stack myStack;

	while (true)
	{
		system("cls");
		std::cout << "\n\n\tChoose an option:"
			<< "\n\t\t1 - .pop()"
			<< "\n\t\t2 - .push()"
			<< "\n\t\t3 - .top()"
			<< "\n\t\t10 - Exit";
		std::cout << "\n\n\tStack:";
		myStack.printStack();
		for (int i = 10; i > myStack.getTotalNodes(); i--)
			std::cout << "\n";
		std::cout << "\n\n\t\tOption: ";
		std::cin >> option;

		if (option == 1)
		{
			if (myStack.getTotalNodes() == 0)
			{
				std::cout << "\n\t\tStack is empty!";
				std::cout << "\n\n\t\t";
				system("pause");
			}
			myStack.pop();
		}
		else if (option == 2)
		{
			std::cout << "\n\t\tEnter the number: ";
			std::cin >> num;
			myStack.push(num);
		}
		else if (option == 3)
		{
			if (myStack.getTotalNodes() == 0)
				std::cout << "\n\t\tStack is empty!";
			else
				std::cout << "\n\t\tNumber at the top of the stack: " << myStack.peek();
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