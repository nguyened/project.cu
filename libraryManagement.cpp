//Created by Evan Nguyen
//CS141 Lab Final Spring 2018
//Last Modified: April 28, 2018
#include<iostream>
#include<string>
#include<fstream>
#include<cmath>

std::ifstream input;

std::string user;
std::string A;
std::string B;

struct Library {//struct Libary that stores Book name, Loan availability, First name, Last name and Days overdue
  std::string bname;
  std::string loanAval;
  std::string Fname;
  std::string Lname;
  int Days;
};

Library LibraryData[20];//20 element array of type Library called LibraryData
//Prototypes---------------------------------------------------------------------
void ShowMenu();
void ShowByPatron(std::string, std::string);
void CalculatePenalty();
//------------------------------------------------------------------------------
int main()
{
  input.open("library.txt");
  int i = 0;
    while(!input.eof())
    {
      input>>LibraryData[i].bname >> LibraryData[i].loanAval >> LibraryData[i].Fname >> LibraryData[i].Lname >> LibraryData[i].Days;
      i++;
    }
  ShowMenu();//runs once, no loop
  std::cout << "Enter your choice by number: ";
  std::cin >> user;
  if(user == "1")
  {
    std::cout << "Enter the first and last name of the person: ";
    std::cin >> A >> B;
    ShowByPatron(A,B);
  }
  else if(user == "2")
  {
    CalculatePenalty();
  }
  else if(user == "3")
  {
    std::cout << "Thanks, goodbye!" << std::endl;
  }
  input.close();
  return 0;
}
//------------------------------------------------------------------------------
void ShowMenu()//Shows the menu options
{
  std::cout << "Option 1: Show all books loaned out by a patron" << std::endl;
  std::cout << "Option 2: List all overdue books and their penalty" << std::endl;
  std::cout << "Option 3: Quit the program\n" << std::endl;
}
//------------------------------------------------------------------------------
void ShowByPatron(std::string A, std::string B)//Function to find a patron and list the books loaned and total books loaned
{
  bool exist = false;
  int bookCount=0;
  for(int j =0;j<20;j++)
  {
    if(LibraryData[j].Fname == A)
    {
      if(LibraryData[j].Lname == B)
      {

        std::cout << LibraryData[j].bname << " - overdue: " << LibraryData[j].Days << " days" << std::endl;
        bookCount++;
        exist = true;
      }
    }
  }
  if(exist==true)
  {
    std::cout << "\nTotal Books Checked Out: " <<bookCount << std::endl;
  }
  if(exist==false)
  {
    std::cout << "No Matches Found" << std::endl;
  }
}
//------------------------------------------------------------------------------
void CalculatePenalty()//function to calculate the penalty for each overdue book
{
  float charge = 0;
  for(int j=0;j<20;j++)
  {
    if(LibraryData[j].Days != -1)
    {
      if(LibraryData[j].Days>=9)
      {
        charge = 5*0.1+4*0.2+(LibraryData[j].Days-9)*0.25;
      }
      if(LibraryData[j].Days<9 && LibraryData[j].Days>=5)
      {
        charge = 5*0.1+(LibraryData[j].Days-5)*0.2;
      }
      if(LibraryData[j].Days<5)
      {
        charge = LibraryData[j].Days*0.1;
      }
      std::cout << LibraryData[j].Fname <<" "<< LibraryData[j].Lname <<" "<< LibraryData[j].bname << " $" << charge << std::endl;
    }
  }
}
//------------------------------------------------------------------------------
