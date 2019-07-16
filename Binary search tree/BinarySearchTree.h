#pragma once
#include<vector>
//abc
struct Node
{
	int info;
	Node* left;
	Node* right;
	Node* parent;

	Node(int valoare)
	{
		this->info = valoare;
		this->left = nullptr;
		this->right = nullptr;
		this->parent = nullptr;
	}
};

class BinarySearchTree
{
private:
	Node* root;
	Node* getMinim(Node* root);
	Node* getMaxim(Node* root);
	void transplant(Node* u, Node* v);
	void postOrder(Node* root);
	void inOrder(Node* root);
	void preOrder(Node* root);
	void levelTraversal(Node* root);

public:
	BinarySearchTree();
	~BinarySearchTree();
	Node* getRoot();
	bool isEmpty();
	Node* search(int value);
	Node* getSuccessor(Node* nodCurent);
	Node* getPredecessor(Node* nodCurent);
	void insertNode(Node* insertedNode);
	void insertValue(int value);
	void deleteNode(Node* target);
	void emptyTree();
	void printTree(int option);
	void constructFromVector(std::vector<int> vector);
};

