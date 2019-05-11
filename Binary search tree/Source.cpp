#include<iostream>
#include"BinarySearchTree.h"

int main()
{
	BinarySearchTree tree;

	int optiune;
	std::cout << "Alegere optiune:\n1)Insertie\n2)Cautare\n3)Stergere\n4)Succesor\n5)Predecesor\n6)Afisare\n7)Stergere completa\n9)Exit\n";
	std::cin >> optiune;
	while (optiune != 9)
	{
		switch (optiune)
		{
		case 1:
			int valoare;
			std::cout << "Valoare:";
			std::cin >> valoare;
			tree.insertValue(valoare);
			break;
		case 2:
			if (tree.isEmpty())
			{
				std::cout << "Arborele este gol\n";
				break;
			}
			std::cout << "Valoare:";
			std::cin >> valoare;
			if (tree.getRoot() != nullptr)
			{
				try
				{
					if (tree.search(valoare)->info)
					{
						std::cout << "Gasit\n";
					}
				}
				catch (int error)
				{
					if (error == 404)
					{
						std::cout << "Nodul nu a fost gasit!\n";
					}
				}
				break;
			}
		case 3:
			if (tree.isEmpty())
			{
				std::cout << "Arborele este gol\n";
				break;
			}
			std::cout << "Valoare:";
			std::cin >> valoare;
			try
			{
				tree.deleteNode(tree.search(valoare));
			}
			catch (int error)
			{
				if (error == 404)
				{
					std::cout << "Nodul nu a fost gasit!\n";
				}
			}
			break;
		case 4:
			if (tree.isEmpty())
			{
				std::cout << "Arborele este gol\n";
				break;
			}
			try
			{
				std::cout << "Valoare:";
				std::cin >> valoare;
				tree.getSuccessor(tree.search(valoare));
			}
			catch (int error)
			{
				if (error == 404)
				{
					std::cout << "Nodul nu a fost gasit!\n";
				}
			}
			break;
		case 5:
			if (tree.isEmpty())
			{
				std::cout << "Arborele este gol\n";
				break;
			}
			try
			{
				std::cout << "Valoare:";
				std::cin >> valoare;
				tree.getPredecessor(tree.search(valoare));
			}
			catch (int error)
			{
				if (error == 404)
				{
					std::cout << "Nodul nu a fost gasit!\n";
				}
			}
			break;
		case 6:
			if (tree.isEmpty())
			{
				std::cout << "Arborele este gol\n";
				break;
			}
			else
			{
				int optiuneAfisare;
				std::cout << "Tipuri de parcurgeri:\n1)Preordine\n2)Inordine\n3)Postordine\n4)Pe nivele\n";
				std::cin >> optiuneAfisare;
				tree.printTree(optiuneAfisare);
				std::cout << "\n";
				break;
			}
		case 7:
			tree.emptyTree();
			break;
		}
		std::cin >> optiune;
	}
	std::cout << "Exit!\n";
	system("pause");
	return 0;
}