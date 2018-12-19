#include<iostream>
#include<string>

int main()
{
    std::string myStr = "the quick brown fox jumped right over the lazy dog.";
    std::string usrInput;

    std::cout << "Enter character or phrase: ";
    std::cin >> usrInput;

    int x = myStr.find(usrInput,0);

    if(x>=0 && x<=myStr.length())
    {
      std::cout << x << ",";
    }
    else
    {
      std::cout << "Not Found";
    }
    	bool loop = true;
    	while(loop)
    	{
		loop = false;
        	x = myStr.find(usrInput,x+1);
        	if(x>=0 && x<=myStr.length())
        	{
          		std::cout << x << ",";
          		loop = true;
        	}
		else
		{
			std::cout << std::endl;
		}
   	}
  return 0;
}
