#pragma once
#include<vector>
class PriorityQueue
{
private:
	std::vector<int> data;
	void readFromFile();
	void constructHeap();
	int getSize();
	bool isEmpty();

public:
	PriorityQueue();
	~PriorityQueue();
	void maxHeap(int index);
	void printVector();
	void increasePriority(int index);
	int extractMax();
	void printMax();
	void insert(int value);
};

