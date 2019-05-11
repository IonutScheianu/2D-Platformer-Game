#include"PriorityQueue.h"
#include<iostream>

int main()
{
	PriorityQueue p;
	int option;
	std::cout << "1)Insert\n2)Extragere max\n3)Afisare max\n4)Afisare elemente\n9)Exit\n";
	std::cin >> option;
	while (option != 9)
	{
		switch (option)
		{
		case 1:
		{
			int valoare;
			std::cout << "Valoare:";
			std::cin >> valoare;
			p.insert(valoare);
			break;
		}
		case 2:
		{
			p.extractMax();
			std::cout << "Elementul maxim a fost extras\n";
			break;
		}
		case 3:
		{
			p.printMax();
			break;
		}
		case 4:
		{
			p.printVector();
		}
		}
		std::cin >> option;
	}
	system("pause");
	return 0;
}