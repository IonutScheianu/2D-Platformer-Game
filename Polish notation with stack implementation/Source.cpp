#include<iostream>
#include"myStack.h"

void readExpression(char*& initialExpression, int& initialExpressionSize)
{
	int index;
	int openParenthesisContor = 0, closeParenthesisContor = 0;
	initialExpression = new char[256];
	gets_s(initialExpression, 256);

	initialExpressionSize = strlen(initialExpression);
	for (index = 0; index < initialExpressionSize; index++)
	{
		if (isalpha(initialExpression[index]) || strchr("`~=:<>:;\!@#$%^&", initialExpression[index]))
		{
			std::cout << "\nLiterele si caracterele speciale nu sunt permise!\n";
			delete[]initialExpression;
			system("pause");
			exit(400);
		}
		if (index > 0)
		{
			if (strchr("+-*/", initialExpression[index - 1]) && strchr("+-*/", initialExpression[index]))
			{
				std::cout << "Expresie nepermisa!\n";
				delete[]initialExpression;
				system("pause");
				exit(400);
			}
		}
		if (initialExpression[index] == '(')
		{
			openParenthesisContor++;
		}
		if (initialExpression[index] == ')')
		{
			closeParenthesisContor++;
		}
	}
	if (openParenthesisContor != closeParenthesisContor)
	{
		std::cout << "Expresie nepermisa!\n";
		delete[]initialExpression;
		system("pause");
		exit(400);
	}
	if (strchr("+-*/", initialExpression[--index]))
	{
		std::cout << "Expresie nepermisa!\n";
		delete[]initialExpression;
		system("pause");
		exit(400);
	}
}

void printExpression(char* expression, int expressionSize)
{
	std::cout << "Vectorul este:\n";
	for (int index = 0; index < expressionSize; index++)
	{
		std::cout << expression[index] << " ";
	}
	std::cout << "\n";
}

int priority(int operators)
{
	if (operators == '(')
	{
		return 0;
	}
	if (operators == '+' || operators == '-')
	{
		return 1;
	}
	else if (operators == '*' || operators == '/')
	{
		return 2;
	}
	return 3;
}

void polishNotation(char* initialExpression, int size)
{
	int finalExpressionIndex = 0;
	char* finalExpression = new char[size];
	myStack operators;
	for (int initialExpressionIndex = 0; initialExpressionIndex < size; initialExpressionIndex++)
	{

		if (initialExpression[initialExpressionIndex] >= '0' && initialExpression[initialExpressionIndex] <= '9')
		{
			finalExpression[finalExpressionIndex++] = initialExpression[initialExpressionIndex];
		}
		else if (initialExpression[initialExpressionIndex] == '(')
		{
			operators.push(initialExpression[initialExpressionIndex]);
		}
		else if (initialExpression[initialExpressionIndex] == ')')
		{
			while (!operators.isEmpty() && operators.getTop() != '(')
			{
				finalExpression[finalExpressionIndex++] = operators.pop();
			}
			operators.pop();
			if (operators.isEmpty())
			{
				std::cout << "Eroare";
			}
		}
		else // este operator  + - * /
		{
			while (!operators.isEmpty() && priority(initialExpression[initialExpressionIndex]) <= priority(operators.getTop()))
			{
				finalExpression[finalExpressionIndex++] = operators.pop();
			}
			operators.push(initialExpression[initialExpressionIndex]);
		}
	}
	while (!operators.isEmpty())
	{
		finalExpression[finalExpressionIndex++] = operators.pop();
	}

	std::cout << "\nForma poloneza postfixata este: \n";
	for (int index = 0; index < finalExpressionIndex; index++)
	{
		std::cout << finalExpression[index] << " ";
	}

	int finalExpressionSize = finalExpressionIndex;
	myStack numbers;

	for (int finalExpressionIndex = 0; finalExpressionIndex < finalExpressionSize; finalExpressionIndex++)
	{
		if (finalExpression[finalExpressionIndex] >= '0' && finalExpression[finalExpressionIndex] <= '9')
		{
			int numar = finalExpression[finalExpressionIndex] - 48;
			numbers.push(numar);
		}
		else
		{
			int number2, number1;
			number2 = numbers.pop();
			number1 = numbers.pop();
			switch (finalExpression[finalExpressionIndex])
			{
			case '+':
			{
				numbers.push(number1 + number2);
				break;
			}
			case '-':
			{
				numbers.push(number1 - number2);
				break;
			}
			case'*':
			{
				numbers.push(number1 * number2);
				break;
			}
			case '/':
			{
				numbers.push(number1 / number2);
				break;
			}
			}
		}
	}
	std::cout << "\nRezultatul expresiei este: " << numbers.pop() << std::endl;
	delete[]finalExpression;
	delete[]initialExpression;
}


int main()
{
	int initialExpressionSize;
	char* initialExpression;
	std::cout << "Introduceti expresia:\n";
	readExpression(initialExpression, initialExpressionSize);
	printExpression(initialExpression, initialExpressionSize);
	polishNotation(initialExpression, initialExpressionSize);
	system("pause");
	return 0;
}