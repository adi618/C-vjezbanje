#include "pch.h"


class DFSNode
{
	friend class DepthFirstSearchClass;
private:
	int num;
	DFSNode* left;
	DFSNode* right;

public:
	DFSNode(int num) : num(num), left(nullptr), right(nullptr) {}

};


class DepthFirstSearchClass
{
private:
	DFSNode* root;

public:
	DepthFirstSearchClass() : root(nullptr) {}

	DFSNode* getRoot() { return root; }

	void insertNode(int num)
	{
		DFSNode* newNode = new DFSNode(num);

		if (root == nullptr)
		{
			root = newNode;
			return;
		}

		DFSNode* current = root;
		DFSNode* previous = nullptr;

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

	std::vector <int> DFSinorder()
	{

	}

	std::vector <int> DFSPostorder()
	{

	}

	std::vector <int> DFSPreorder()
	{

	}
};


void DepthFirstSearch()
{
	DepthFirstSearchClass myTree;

	myTree.insertNode(33);
	myTree.insertNode(21);
	myTree.insertNode(324);
	myTree.insertNode(123);
	myTree.insertNode(1233);
	myTree.insertNode(1);
	myTree.insertNode(55);/*

	std::vector <int> iterative = myTree.DepthFirstSearch();
	std::queue <DFSNode*> temp;
	temp.push(myTree.getRoot());
	std::vector <int> recursive = myTree.DepthFirstSearchRecursive(temp);*/

	//for (int num : iterative)
	//	std::cout << num << "  ";

	//std::cout << std::endl;

	//for (int num : recursive)
	//	std::cout << num << "  ";

	return;
}