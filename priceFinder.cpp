//Created by Evan Nguyen
//Purpose: Lab 7: Arrays & Functions
//Last Modified: March 11, 2018

#include<iostream>
#include<string>

int main()
{
  bool loop = true;
  while(loop)
  {
    //=============Variables================================
    const int arraySize = 10;
    float sumPrices = 0.0;
    std::string productName;
    float maxVal = 0;
    float minVal = 0;
    float y = 0;
    float prices[arraySize] = {0};
    int x = 0;
    int priceNo = 1;
    int total;
    //=======================================================

    std::cout << "Enter the product name: ";
    std::cin >> productName;

    if(productName == "DONE")
    {
      std::cout << "Thanks you for using this program!" << std::endl;
      loop = false;
    }
    else
    {
      std::cout << "(When finished type '-1')" << std::endl;
      while(y>=0 && x<10)
      {
        std::cout << "Enter a price: ";
        std::cin >> y;
        prices[x] = y;
        x++;
        total = x;
      }
      if(total<10)
      {
        for(int z=0; z<(x-1); z++)
        {
          sumPrices = sumPrices + prices[z];
          if(z==0)
          {
            maxVal = prices[z];
            minVal = prices[z];
          }
          else
          {
            if(prices[z]>maxVal)
            {
              maxVal = prices[z];
            }
            if(prices[z]<minVal)
            {
              minVal = prices[z];
            }
          }
        }
        std::cout << std::endl;
        std::cout << "Number of Valid Prices: " << total-1 << std::endl;
        std::cout << "Average: $" <<sumPrices/(total-1) << std::endl;
      }
      else
      {
        for(int z=0; z<x; z++)
        {
          sumPrices = sumPrices + prices[z];
          if(z==0)
          {
            maxVal = prices[z];
            minVal = prices[z];
          }
          else
          {
            if(prices[z]>maxVal)
            {
              maxVal = prices[z];
            }
            if(prices[z]<minVal)
            {
              minVal = prices[z];
            }
          }
        }
        std::cout << std::endl;
        std::cout << "Number of Valid Prices: " << total << std::endl;
        std::cout << "Average: $" << sumPrices/total << std::endl;
      }
//----------------Outputs---------------------------------
  std::cout << "Max: $" << maxVal << std::endl;
  std::cout << "Min: $" << minVal << std::endl;
  std::cout << "Range: $" << maxVal-minVal << "\n" << std::endl;
    }
  }
  return 0;
}
