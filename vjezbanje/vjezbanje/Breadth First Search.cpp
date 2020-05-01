#include "pch.h"


class BFSNode
{
	friend class BreadthFirstSearchClass;
private:
	int num;
	BFSNode* left;
	BFSNode* right;

public:
	BFSNode(int num) : num(num), left(nullptr), right(nullptr) {}

};


class BreadthFirstSearchClass
{
private:
	BFSNode* root;

public:
	BreadthFirstSearchClass() : root(nullptr) {}

	BFSNode* getRoot() { return root; }

	void insertNode(int num)
	{
		BFSNode* newNode = new BFSNode(num);

		if (root == nullptr)
		{
			root = newNode;
			return;
		}

		BFSNode* current = root;
		BFSNode* previous = nullptr;

		while (current != nullptr)
		{
			previous = current;

			if (num < current->num)
				current = current->left;
			else
				current = current->right;
		}

		if (num < previous->num)
			previous->left = newNode;
		else
			previous->right = newNode;
	}

	std::vector <int> BreadthFirstSearch()
	{
		BFSNode* current = root;

		std::vector <int> result;
		std::queue <BFSNode*> queue;

		queue.push(current);

		while (queue.size() > 0)
		{
			current = queue.front();
			queue.pop();

			result.push_back(current->num);

			if (current->left)
				queue.push(current->left);

			if (current->right)
				queue.push(current->right);
		}

		return result;
	}

	std::vector <int> BreadthFirstSearchRecursive(std::queue <BFSNode*> queue, std::vector <int> result = {})
	{
		if (queue.empty())
			return result;

		BFSNode* current = queue.front();
		queue.pop();
		result.push_back(current->num);

		if (current->left)
			queue.push(current->left);

		if (current->right)
			queue.push(current->right);

		return BreadthFirstSearchRecursive(queue, result);
	}
};


void BreadthFirstSearch()
{
	BreadthFirstSearchClass myTree;

	myTree.insertNode(1);
	myTree.insertNode(2);
	myTree.insertNode(3);
	myTree.insertNode(4);
	myTree.insertNode(5);

	std::vector <int> iterative = myTree.BreadthFirstSearch();
	std::queue <BFSNode*> temp;
	temp.push(myTree.getRoot());
	std::vector <int> recursive = myTree.BreadthFirstSearchRecursive(temp);

	for (int num : iterative)
		std::cout << num << "  ";

	std::cout << std::endl;

	for (int num : recursive)
		std::cout << num << "  ";

	return;
}