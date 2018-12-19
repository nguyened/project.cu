#include<iostream>
#include<string>
#include<cmath>

int main()
{
	float num1;
	float num2;
	std::string op;

	std::cout << "The CS141 Calculator Deluxe (Created by: Evan Nguyen)" << std::endl;
	std::cout << "Type + to add two numbers" << std::endl;
	std::cout << "Type - to subtract two numbers" << std::endl;
	std::cout << "Type * to multiply two numbers" << std::endl;
	std::cout << "Type / to divide two numbers" << std::endl;
	std::cout << "Type ^ to raise a number to a number" << std::endl;
	std::cout << "Type % to find the modulus of two numbers" << std::endl;
	std::cin >> num1 >> op >> num2;

	if(op == "+")
	{
		std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
	}

	else if(op == "-")
	{
		std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
	}

	else if(op == "*")
	{
		std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
	}

	else if(op == "/")
	{
		if(num2 == 0)
		{
			std::cout << "I Do Not Understand, divide by zero error" << std::endl;
		} else
		{
			std::cout << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
		}
	}
	
	else if(op == "^")
	{
		std::cout << num1 << " power of " << num2 << " = " << pow(num1,num2) << std::endl;
	}

	else if(op == "%")
	{
		std::cout << num1 << " mod " << num2 << " = " << fmod(num1,num2) << std::endl;
	}

	else
	{
		std::cout << "Did not recognize command: " << num1 << op << num2 << std::endl;
	}

	return 0;
}
