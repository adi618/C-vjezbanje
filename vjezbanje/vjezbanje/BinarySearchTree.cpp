#include "pch.h"


class BSTNode
{
	friend class BinarySearchTree;
private:
	int num;
	BSTNode* right;
	BSTNode* left;

public:
	BSTNode(int num) :num(num), right(nullptr), left(nullptr) {}
};

class BinarySearchTree
{
private:
	BSTNode* root;

public:
	BinarySearchTree() :root(nullptr) {}

	BSTNode* getRoot() { return root; }

	void insert(int num)
	{
		BSTNode* newNode = new BSTNode(num);

		if (root == nullptr)
		{
			root = newNode;
			return;
		}

		BSTNode* current = root;
		BSTNode* previous = root;

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

	void remove(int num)
	{
		if (root == nullptr)
			return;

		BSTNode* current = root;
		BSTNode* previous = nullptr;

		while (current != nullptr)
		{
			if (num < current->num)
			{
				previous = current;			// traverse the tree to find the node
				current = current->left;
			}
			else if (num > current->num)
			{
				previous = current;
				current = current->right;
			}
			else	// if found, current is the node we want to delete, and previous is its parent node
			{
				if (current->left == nullptr and current->right == nullptr)
				{										// check if the current node is a leaf
					if (previous->left == current)		// if so, check if it is left of its parent node
						previous->left = nullptr;		// if so delete it, otherwise delete the other side
					else
						previous->right = nullptr;

					return;
				}
				
				if (current->left == nullptr or current->right == nullptr)	// check if the current node is a parent to only one node
				{
					if (previous->left == current)		// check if the current node had a left child
						previous->left = current->left;
					else
						previous->right = current->right;

					return;
				}

				// the current node has two children:
				BSTNode* temp = current->right;		// temp is the current's right child. we only check the right child of current
													// because the left child cannot be a successor
				if (temp->left == nullptr and temp->right == nullptr)	// check if temp doesn't have children
				{
					current->num = temp->num;		// if the currents' right child (temp) doesn't have any children,
					current->right = nullptr;		// we can just set the current's number to temp's number
					return;
				}

				if (temp->left == nullptr and temp->right != nullptr)	// if temp has a right child
				{
					current->num = temp->num;
					current->right = temp->right;
					return;
				}

				while (temp->left != nullptr)
				{
					previous = temp;
					temp = temp->left;
				}

				current->num = temp->num;
				previous->left = nullptr;
			}
		}
	}

	bool lookup(int num)
	{
		if (root == nullptr)
			return false;

		BSTNode* current = root;

		while (current != nullptr)
		{
			if (num < current->num)
				current = current->left;
			else if (num > current->num)
				current = current->right;
			else
				return true;
		}
		return false;
	}

	std::vector <int> BreadthFirstSearch()
	{
		BSTNode* current = root;

		std::vector <int> result;
		std::queue <BSTNode*> queue;

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

	std::vector <int> BreadthFirstSearchRecursive(std::queue <BSTNode*> queue, std::vector <int> result = {})
	{
		if (queue.empty())
			return result;

		BSTNode* current = queue.front();
		queue.pop();
		result.push_back(current->num);

		if (current->left)
			queue.push(current->left);

		if (current->right)
			queue.push(current->right);

		return BreadthFirstSearchRecursive(queue, result);
	}
};


void DTBinarySearchTree()
{
	BinarySearchTree myTree;

	myTree.insert(6);
	myTree.insert(63);
	myTree.insert(240);
	myTree.insert(7);
	myTree.insert(6);
	myTree.insert(1);
	myTree.insert(234);
	myTree.remove(234);
	myTree.remove(63);

	std::vector <int> iterative = myTree.BreadthFirstSearch();
	std::queue <BSTNode*> temp;
	temp.push(myTree.getRoot());
	std::vector <int> recursive = myTree.BreadthFirstSearchRecursive(temp);

	for (int num : iterative)
		std::cout << num << "  ";

	std::cout << std::endl;

	for (int num : recursive)
		std::cout << num << "  ";

	return;
}