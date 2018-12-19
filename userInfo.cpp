#include<iostream>
#include<string>

int main()
{
	std::string firstName;
	std::string midName;
	std::string lastName;
	std::string stateCode;
	std::string zipCode;
	std::string numPhone;
	
	bool loop = false;
	
	do
	{
		loop = false;
		std::cout << "Enter first name: " << std::endl;
		std::cin >> firstName;
		
		if(firstName.size() < 2 || firstName.size() > 10)
		{
			std::cout << "INVALID: Must be between 2 and 10 characters." << std::endl;
			loop = true;
		}	
	} while(loop);
	do
	{
		loop = false;
		std::cout << "Enter middle name: " << std::endl;
		std::cout << "(Optional, enter 'none' to continue.)" << std::endl;
		std::cin >> midName;
		
		if(midName.size() < 2 || midName.size() > 10)
		{
			std::cout << "INVALID: Must be between 2 and 10 characters." << std::endl;
			loop = true;
		}	
	} while(loop);
	do
	{
		loop = false;
		std::cout << "Enter last name: " << std::endl;
		std::cin >> lastName;
		
		if(lastName.size() < 2 || lastName.size() > 10)
		{
			std::cout << "INVALID: Must be between 2 and 10 characters." << std::endl;
			loop = true;
		}
	} while(loop);
	do
	{
		loop = false;
		std::cout << "Enter state code: " << std::endl;
		std::cout << "(Characters must be uppercase)" << std::endl;
		std::cin >> stateCode;
		
		bool valid = true;
		int i = 0;
		char c;
		while(stateCode[i])
		{
			c = stateCode[i];
			if(islower(c) || !isalpha(c))
			valid = false;
			i++;
		}
		
		if(stateCode.size() != 2 || !valid)
		{
			std::cout << "INVALID: Must be uppercase letters." << std::endl;
			loop = true;
		}
	} while(loop);
	do
	{
		loop = false;
		std::cout << "Enter 5 digit zip code: " << std::endl;
		std::cin >> zipCode;
		
		bool valid = true;
		int i = 0;
		char z;
		while(zipCode[i])
		{
			z = zipCode[i];
			if(isalpha(z) || !isdigit(z))
			valid = false;
			i++;
		}
		
		if(zipCode.size() != 5 || !valid)
		{
			std::cout << "INVALID: Try again." << std::endl;
			loop = true;
		}
	} while(loop);
	do
	{
		loop = false;
		std::cout << "Enter phone number: " << std::endl;
		std::cout << "Example: (123)-456-7890 or 123-456-7890" << std::endl;
		std::cin >> numPhone;
		
		bool valid = true;
		int i = 0;
		char p;
		while(numPhone[i])
		{
			p = numPhone[i];
			if(p == '-')
			valid = false;
			i++;
		}
		
		if(numPhone.size() != 14 && numPhone.size() != 12)
		{
			std::cout << "INVALID: Incorrect number of characters." << std::endl;
			loop = true;
		}
		if(valid == true)
		{
			std::cout << "INVALID: Needs '-'" << std::endl;
			loop = true;
		}
	} while(loop);
	std::cout << "Results Ok!" << std::endl;
	return 0;
}
