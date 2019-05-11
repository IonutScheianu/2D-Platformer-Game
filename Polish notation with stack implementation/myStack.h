#pragma once

struct Node
{
	int info;
	Node* next;
};

class myStack
{
private:
	Node *top;

public:
	myStack();
	~myStack();
	bool isEmpty();
	void push(int value);
	int pop();
	int getTop();
#ifdef DEBUG
	void print();
#endif
};

