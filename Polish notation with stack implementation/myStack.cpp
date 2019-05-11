#include "myStack.h"
#include<iostream>


	myStack::myStack()
	{
		this->top = nullptr;
	}

	bool myStack::isEmpty()
	{
		if (top == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void myStack::push(int value)
	{
		Node* nodNou = new (Node);
		nodNou->info = value;
		nodNou->next = this->top;
		this->top = nodNou;
	}

	int myStack::pop()
	{
		if (isEmpty())
		{
			std::cout << "Stiva este vida!\n";
		}
		else
		{
			//std::cout << "Elementul eliminat este: " << varf->info << std::endl;
			int aux = this->top->info;
			Node* old = this->top;
			this->top = this->top->next;
			delete (old);
			return aux;
		}
	}

	int myStack::getTop()
	{
		if (isEmpty())
		{
			std::cout << "Stiva este vida!\n";
			return -1;
		}
		else
		{
			//std::cout << "Elementul din varful stivei este: " << varf->info << std::endl;
			return this->top->info;
		}
	}

#ifdef DEBUG
	void myStack::print()  // incalca principiul stivei, facut pt verificare
	{
		Node* currentNode;
		if (isEmpty())
		{
			std::cout << "Stiva este vida!\n";
		}
		else
		{
			currentNode = this->top;
			std::cout << "Elementele stivei sunt:\n";
			while (currentNode)
			{
				std::cout << currentNode->info << std::endl;
				currentNode = currentNode->next;
			}
		}
		std::cout << "\n";
	}
#endif // DEBUG

myStack::~myStack()
{
}
