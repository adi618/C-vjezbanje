#include "pch.h"


class Node
{
	friend class DoublyLinkedList;
private:
	int number;
	Node* nextNode;
	Node* prevNode;

public:
	Node(int number) : number(number), nextNode(nullptr), prevNode(nullptr) {}
};

class DoublyLinkedList
{
private:
	Node* head;
	Node* tail;
	int totalNodes;

public:
	DoublyLinkedList() : head(nullptr), tail(nullptr), totalNodes(0) {}

	int getLength() { return totalNodes; }

	void appendNode(int num)		// O(1)
	{
		Node* newNode = new Node(num);
		totalNodes++;

		if (head == nullptr)
		{
			newNode->prevNode = nullptr;
			head = newNode;
			tail = head;
		}
		else
		{
			newNode->prevNode = tail;
			tail->nextNode = newNode;
			tail = newNode;
		}
	}

	void prependNode(int num)		// O(1)
	{
		Node* newNode = new Node(num);
		totalNodes++;

		if (head == nullptr)
		{
			newNode->prevNode = nullptr;
			head = newNode;
			tail = head;
		}
		else
		{
			newNode->nextNode = head;
			head->prevNode = newNode;
			head = newNode;
		}
	}

	void traverseNodeToIndex(Node*& current, Node*& previous, int index)		// O(n)
	{
		while (current != nullptr)
		{
			if (index == 1)
				break;

			index--;
			previous = current;
			current = current->nextNode;
		}
	}

	void traverseNodeToIndex(Node*& current, int index)		// O(n)
	{
		while (current != nullptr)
		{
			if (index == 1)
				break;

			index--;
			current = current->nextNode;
		}
	}

	void insertNodeAtIndex(int num, int index)		// O(n)
	{
		if (invalidIndex(index))
		{
			return;
		}

		if (index == totalNodes)
		{
			appendNode(num);
			return;
		}

		if (index == 0)
		{
			prependNode(num);
			return;
		}

		Node* newNode = new Node(num);

		Node* current = head->nextNode;
		Node* previous = head;

		traverseNodeToIndex(current, previous, index);

		newNode->nextNode = current;
		newNode->prevNode = previous;
		current->prevNode = newNode;
		previous->nextNode = newNode;
		totalNodes++;
	}

	void removeFirstNode()		// O(1)
	{
		Node* temp = head;

		head = head->nextNode;
		head->prevNode = nullptr;
		free(temp);
		totalNodes--;
	}

	void popNode()		// O(1)
	{
		Node* temp = tail;

		tail = tail->prevNode;
		tail->nextNode = nullptr;
		free(temp);
		totalNodes--;
	}

	void removeNodeAtIndex(int index)		// O(n)
	{
		if (invalidIndex(index))
			return;

		if (index == 0)
		{
			removeFirstNode();
			return;
		}

		if (index == totalNodes - 1)
		{
			popNode();
			return;
		}

		Node* current = head;

		traverseNodeToIndex(current, index);

		Node* temp = current->nextNode->nextNode;
		free(current->nextNode);
		temp->prevNode = current;
		current->nextNode = temp;
		totalNodes--;

		if (index == totalNodes)
			tail = current;
	}

	void printNodes()		// O(n)
	{
		Node* current = head;

		if (head != nullptr)
		{
			std::cout << "nullptr <--> ";
			while (current != nullptr)
			{
				std::cout << current->number << " <--> ";
				current = current->nextNode;
			}
			std::cout << "nullptr";
			std::cout << "\n\n\tFirst number in the list: " << head->number;
			std::cout << "\n\tLast number in the list: " << tail->number;
		}
		else
		{
			std::cout << "[empty]";
			std::cout << "\n\n\tFirst number in the list: [none]";
			std::cout << "\n\tLast number in the list: [none]";
		}
	}

	bool invalidIndex(int index)		// O(1)
	{
		if (index < 0 || index >= totalNodes)
		{
			std::cout << "\n\t\tInvalid index!\n\n";
			system("pause");
			return true;
		}
		return false;
	}

	bool listIsEmpty()		// O(1)
	{
		if (totalNodes == 0)
		{
			std::cout << "\n\t\tNothing to remove!\n\n";
			system("pause");
			return true;
		}
		return false;
	}
};


void doublyLinkedList()
{
	int option;
	int index;
	int num;
	DoublyLinkedList myDoublyLinkedList;

	while (true)
	{
		system("cls");
		std::cout << "\n\n\tDoubly Linked List:      ";
		myDoublyLinkedList.printNodes();

		std::cout << "\n\n\tChoose an option:"
			<< "\n\t\t1 - Add a number to the end of the list (append / push)"
			<< "\n\t\t2 - Add a number to the beginning of the list (prepend)"
			<< "\n\t\t3 - Add a number at a specific index of the list (insert)"
			<< "\n\t\t4 - Remove the last number of the list (pop)"
			<< "\n\t\t5 - Remove the first number of the list"
			<< "\n\t\t6 - Remove the number at a specific index of the list (remove)"
			<< "\n\t\t10 - Exit"
			<< "\n\n\t\tOption: ";

		std::cin >> option;

		if (option == 1)
		{
			std::cout << "\n\t\tEnter the number: ";
			std::cin >> num;
			myDoublyLinkedList.appendNode(num);
		}
		else if (option == 2)
		{
			std::cout << "\n\t\tEnter the number: ";
			std::cin >> num;
			myDoublyLinkedList.prependNode(num);
		}
		else if (option == 3)
		{
			std::cout << "\n\t\tEnter the number: ";
			std::cin >> num;
			std::cout << "\n\t\tEnter the index: ";
			std::cin >> index;
			myDoublyLinkedList.insertNodeAtIndex(num, index);
		}
		else if (option == 4)
		{
			if (myDoublyLinkedList.listIsEmpty())
				continue;
			myDoublyLinkedList.removeNodeAtIndex(myDoublyLinkedList.getLength() - 1);
		}
		else if (option == 5)
		{
			if (myDoublyLinkedList.listIsEmpty())
				continue;
			myDoublyLinkedList.removeFirstNode();
		}
		else if (option == 6)
		{
			if (myDoublyLinkedList.listIsEmpty())
				continue;
			std::cout << "\n\t\tEnter the index: ";
			std::cin >> index;
			myDoublyLinkedList.removeNodeAtIndex(index);
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