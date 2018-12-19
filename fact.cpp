#include<iostream>

//Created by Evan Nguyen

int main()
{
	int num;
	int fact = 1;
	int fact2 = 1;
	bool loop = false;
	
	do
	{
		std::cout << "Enter a number: ";
		std::cin >> num;
	
		loop = false;
		
		if(num == 0)
		{
			std::cout << "Cannot compute factorial for 0." << std::endl;
			loop = true;
		} 
		else
		{
			if(num < 0)
			{
				std::cout << "Cannot compute factorial for negative numbers." << std::endl;
				loop = true;
			}
			else
			{
				for (int i = 0; i<num; i++)
				{
					fact = fact * (num-i);
					fact2 = 1;
					for(int j = 0; j<i; j++)
					{
						fact2 = fact2 * (i-j);
					}
					if(i>0)
					std::cout << i << "! = " << fact2 << std::endl;
				}
				std::cout << num << "! = " << fact << std::endl;
			}
		}
	} while(loop);
	
return 0;
}
