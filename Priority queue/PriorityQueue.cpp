#include "PriorityQueue.h"
#include<fstream>
#include<iostream>

void PriorityQueue::readFromFile()
{
	int cheie;
	std::ifstream in("file3.txt");
	if (in >> cheie)
	{
		while (!in.eof())
		{
			in >> cheie;
			data.push_back(cheie);
		}
		in.close();
	}
	else
	{
		std::cout << "Fisierul nu a putut fi deschis!\n";
	}
}

void PriorityQueue::constructHeap()
{
	readFromFile();
	for (int index = data.size() / 2 - 1; index >= 0; --index)
	{
		maxHeap(index);
	}
}

int PriorityQueue::getSize()
{
	return data.size();
}

bool PriorityQueue::isEmpty()
{
	if (data.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PriorityQueue::maxHeap(int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int index_aux = index;

	if (left<data.size() && data[left]>data[index])
	{
		index_aux = left;
	}
	if (right<data.size() && data[right]>data[index_aux])
	{
		index_aux = right;
	}
	if (index_aux != index)
	{
		std::swap(data[index_aux], data[index]);
		maxHeap(index_aux);
	}
}

void PriorityQueue::printVector()
{
	if (isEmpty())
	{
		std::cout << "Vectorul este gol\n";
		return;
	}
	std::cout << "Vectorul este:\n";
	for (int index = 0; index < data.size(); ++index)
	{
		std::cout << data[index] << " ";
	}
	std::cout << std::endl;
}

void PriorityQueue::increasePriority(int index)
{
	int index_aux = index;
	int parent = (index - 1) / 2;
	if (index > 0 && data[index] > data[parent])
	{
		index_aux = parent;
	}
	if (index != index_aux)
	{
		std::swap(data[index], data[index_aux]);
		increasePriority(index_aux);
	}
}

int PriorityQueue::extractMax()
{
	if (isEmpty())
	{
		std::cout << "Coada este vida\n";
		return false;
	}
	else
	{
		int max = data[0];
		data[0] = data[data.size() - 1];
		data.resize(data.size() - 1);
		maxHeap(0);
		return max;
	}
}

void PriorityQueue::printMax()
{
	if (isEmpty())
	{
		std::cout << "Coada este vida\n";
	}
	else
	{
		std::cout << "Elementul maxim este: " << data[0] << "\n";
	}
}

void PriorityQueue::insert(int value)
{
	data.push_back(value);
	increasePriority(data.size() - 1);
}

PriorityQueue::PriorityQueue()
{
	constructHeap();
}


PriorityQueue::~PriorityQueue()
{
}