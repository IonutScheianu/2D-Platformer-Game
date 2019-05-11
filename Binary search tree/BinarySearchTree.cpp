#include "BinarySearchTree.h"
#include<iostream>
#include<queue>


BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	delete(root);
}

Node* BinarySearchTree::getRoot()
{
	return this->root;
}

bool BinarySearchTree::isEmpty()
{
	if (root == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Node* BinarySearchTree::search(int value)
{
	Node* currentNode = this->root;
	while (currentNode != nullptr && currentNode->info != value)
	{
		if (value < currentNode->info)
		{
			currentNode = currentNode->left;
		}
		else
		{
			currentNode = currentNode->right;
		}
	}

	if (currentNode == nullptr)
	{
		throw 404;
	}
	return currentNode;
}

Node* BinarySearchTree::getMinim(Node* root)
{
	Node* nodCurent = root;
	while (nodCurent->left != nullptr)
	{
		nodCurent = nodCurent->left;
	}
	return nodCurent;
}

Node* BinarySearchTree::getMaxim(Node* root)
{
	Node* nodCurent = root;
	while (nodCurent->right != nullptr)
	{
		nodCurent = nodCurent->right;
	}
	return nodCurent;
}

Node* BinarySearchTree::getSuccessor(Node* currentNode)
{
	if (currentNode->right != nullptr)
	{
		return getMinim(currentNode->right);
	}
	Node* parent = currentNode->parent;
	while (parent != nullptr && currentNode == parent->right)
	{
		currentNode = parent;
		parent = parent->parent;
	}

	if (currentNode == nullptr)
	{
		throw 404;
	}

	return parent;
}

Node* BinarySearchTree::getPredecessor(Node* currentNode)
{
	if (currentNode->left != nullptr)
	{
		return getMaxim(currentNode->left);
	}
	Node* parent = currentNode->parent;
	while (parent != nullptr && currentNode == parent->left)
	{
		currentNode = parent;
		parent = parent->parent;
	}

	if (currentNode == nullptr)
	{
		throw 404;
	}

	return parent;
}

void BinarySearchTree::insertNode(Node* insertedNode)
{
	Node* currentNode = this->root;
	Node* parentStorage = nullptr;
	while (currentNode != nullptr)
	{
		parentStorage = currentNode;

		if (insertedNode->info < currentNode->info)
		{
			currentNode = currentNode->left;
		}
		else
		{
			currentNode = currentNode->right;
		}
	}
	insertedNode->parent = parentStorage;
	if (parentStorage == nullptr)
	{
		this->root = insertedNode;
	}
	else
	{
		if (insertedNode->info < parentStorage->info)
		{
			parentStorage->left = insertedNode;
		}
		else
		{
			parentStorage->right = insertedNode;
		}
	}
}

void BinarySearchTree::insertValue(int value)
{
	Node* insertedNode = new Node(value);
	Node* currentNode = this->root;
	Node* parentStorage = nullptr;
	while (currentNode != nullptr)
	{
		parentStorage = currentNode;

		if (insertedNode->info < currentNode->info)
		{
			currentNode = currentNode->left;
		}
		else
		{
			currentNode = currentNode->right;
		}
	}
	insertedNode->parent = parentStorage;
	if (parentStorage == nullptr)
	{
		this->root = insertedNode;
	}
	else
	{
		if (insertedNode->info < parentStorage->info)
		{
			parentStorage->left = insertedNode;
		}
		else
		{
			parentStorage->right = insertedNode;
		}
	}
}

void BinarySearchTree::transplant(Node* u, Node* v)
{
	if (u->parent == nullptr)
	{
		this->root = v;
	}
	else
	{
		if (u == u->parent->left)
		{
			u->parent->left = v;
		}
		else
		{
			u->parent->right = v;
		}
	}
	if (v != nullptr)
	{
		v->parent = u->parent;
	}
}

void BinarySearchTree::deleteNode(Node* target)
{
	if (target->left == nullptr)
	{
		transplant(target, target->right);
	}
	else
	{
		if (target->right == nullptr)
		{
			transplant(target, target->left);
		}
		else
		{
			Node* successor = getSuccessor(target);
			if (successor != target->right)
			{
				transplant(successor, successor->right);
				successor->right = target->right; //descendentul drept al lui z
				target->right->parent = successor; //devine descendent drept al lui y
			}
			transplant(target, successor);
			successor->left = target->left;//descendentul stang al lui z
			target->left->parent = successor;//devine descendent stang al lui y
		}
	}
}

void BinarySearchTree::emptyTree()
{
	while (root != nullptr)
	{
		deleteNode(root);
	}
	std::cout << "Arborele a fost sters!\n";
}

void BinarySearchTree::postOrder(Node* root)
{
	if (root)
	{
		postOrder(root->left);
		postOrder(root->right);
		std::cout <<root->info << " ";
	}
}

void BinarySearchTree::inOrder(Node* root)
{
	if (root)
	{
		inOrder(root->left);
		std::cout << root->info << " ";
		inOrder(root->right);
	}
}

void BinarySearchTree::preOrder(Node* root)
{
	if (root)
	{
		std::cout << root->info << " ";
		postOrder(root->left);
		postOrder(root->right);
	}
}

void BinarySearchTree::levelTraversal(Node* root)
{
	if (root)
	{
		std::queue<Node*> queue;
		queue.push(root);

		while (queue.empty() == false)
		{
			Node* node = queue.front();
			std::cout << node->info << " ";
			queue.pop();

			if (node->left != nullptr)
			{
				queue.push(node->left);
			}

			if (node->right != nullptr)
			{
				queue.push(node->right);
			}
		}
	}
}

void BinarySearchTree::printTree(int option)
{
	if (option == 1)
	{
		preOrder(root);
	}
	if (option == 2)
	{
		inOrder(root);
	}
	if (option == 3)
	{
		postOrder(root);
	}
	if (option == 4)
	{
		levelTraversal(root);
	}
}

void BinarySearchTree::constructFromVector(std::vector<int> vector)
{
	while (vector.size())
	{
		int valoare = *vector.begin();
		Node* nodDeInserat = new Node(valoare);
		this->insertNode(nodDeInserat);
		vector.erase(vector.begin());
	}
}

