#include "pch.h"


class SNodev2
{
	friend class Stackv2;
private:
	std::string value;
	SNodev2* next;

public:
	SNodev2(std::string value) :value(value), next(nullptr) {}
};


class Stackv2
{
private:
	SNodev2* top;
	int totalNodes;

public:
	Stackv2() : top(nullptr), totalNodes(0) {}

	int getTotalNodes() { return totalNodes; }

	std::string pop()
	{
		if (top == nullptr)
			return 0;

		SNodev2* temp = top;

		top = top->next;
		totalNodes--;

		return temp->value;
	}

	void push(std::string num)
	{
		SNodev2* newNode = new SNodev2(num);
		totalNodes++;

		if (top == nullptr)
		{
			top = newNode;
			return;
		}
		SNodev2* temp = top;

		top = newNode;
		top->next = temp;
	}

	std::string peek()
	{
		if (top == nullptr)
			return 0;
		return top->value;
	}

	void printStack()
	{
		if (totalNodes > 10)
			overflow();

		std::vector <std::string> values(10);

		SNodev2* temp = top;

		std::cout << "  ----------------------\n";

		int i = totalNodes - 1;
		while (temp != nullptr)
		{
			values[i] = temp->value;
			temp = temp->next;
			i--;
		}

		for (int i = 9; i >= 0; i--)
		{
			spaces(values[i]);
		}

		return;
	}

	void spaces(const std::string& value)
	{
		int left = value.size() / 2;
		int right = value.size() - left;

		left = 10 - left;
		right = 10 - right;

		std::cout << "\t\t|";
		for (int i = 0; i < left; i++)
			std::cout << " ";

		std::cout << value;

		for (int i = 0; i < right; i++)
			std::cout << " ";
		std::cout << "|\n";
		std::cout << "\t\t----------------------\n";
	}
	
	void overflow()
	{
		overflow();
	}
};


void DTSStackv2()
{
	int option;
	std::string value;
	Stackv2 myStack;

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
			std::cout << "\n\t\tEnter the value: ";
			std::cin.ignore();
			getline(std::cin, value);
			myStack.push(value);
		}
		else if (option == 3)
		{
			if (myStack.getTotalNodes() == 0)
				std::cout << "\n\t\tStack is empty!";
			else
				std::cout << "\n\t\tValue at the top of the stack: " << myStack.peek();
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