//Created by Evan Nguyen
//Purpose: Lab 8: Functions, Structs, Arrays
//Last Modified: March 31, 2018
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<time.h>
//======================Variables===============================================
struct employData {
  std::string firstName;
  std::string lastName;
};
struct pass {
  std::string password;
};

std::ifstream emp;
std::ifstream pas;
std::ofstream outputHandler;

employData emplData[50]; //stores peoples names
pass passData[50]; //stores passwords read
int randm[50]; //array for random numbers
//========================Function==============================================
void readEmployees();
void readPasswords();
void shufflePass();
void assignPass();
//==============================================================================
//==============================================================================
int main(){
  srand(time(NULL));
  readEmployees();
  readPasswords();
  shufflePass();
  assignPass();
    outputHandler.close();
    emp.close();
    pas.close();
  std::cout << "Done" << std::endl;
  return 0;
}
//==============================================================================
//==============================================================================
void readEmployees()
{
  emp.open("employees.txt");
    for(int x = 0;x<50;x++)
    {
      emp >> emplData[x].firstName >> emplData[x].lastName;
    }
}
//------------------------------------------------------------------------------
void readPasswords()
{
  pas.open("passwords.txt");
    for(int x=0;x<50;x++)
    {
      pas >> passData[x].password;
    }
}
//------------------------------------------------------------------------------
void shufflePass()
{
  int n;
    for(int i = 0; i<50; i++) {
      bool check;
      do
      {
        n = rand()%50;
        check = true;
        for(int k = 0; k<i; k++)
        {
          if(n == randm[k])
          {
            check = false;
            break;
          }
        }
      } while(!check);
      randm[i] = n;
    }
}
//------------------------------------------------------------------------------
void assignPass()
{
  outputHandler.open("empPasswords.txt");
  for(int x = 0; x<50; x++)
  {
    outputHandler << emplData[x].firstName << " " << emplData[x].lastName << " " <<  passData[randm[x]].password << std::endl;
  }
}
