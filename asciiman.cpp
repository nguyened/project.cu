//Created by Evan Nguyen
//Purpose: Hangman Game Term Project
//Last Modified: May 4, 2018
#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cstdlib>

std::string user;
int rNumber;
int indexNum;
std::string SecretWord;
std::string playChoice;
bool error = false;

std::ifstream inputHandler;



struct Category {//struct to organize data
  std::string category;
  std::string WordArray[5];
  int indexStorage[5];
  std::string hints[5];
  std::string hints2[5];
};



int RandomIndices[5] = {0,1,2,3,4};//array for shuffling indices to pick words randomly
Category StoreArray[5];
//----------------------------Prototypes----------------------------------------
void readFile();
int shuffleNum();
bool triesLeft(std::string SecretWord, char);
void asciiman(int);
bool DisplayWordAndWin(std::string SecretWord, std::string guessed);
//==============================================================================
int main()
{

  for(int i=0;i<5;i++)
  {
	for(int j=0;j<5;j++)
	{
		StoreArray[i].indexStorage[j] = -1;
	}
  }

  std::string guessed;
  std::string placeHolder;
  char x;
  bool win = false;
  bool pickAnother = false;

  std::cout<<"\nWelcome To Hangman!"<<std::endl;

  restart://clears following for a new game
  guessed.clear();
  SecretWord.clear();
  int attempt = 1;
  int tries = 6;

  std::cout<<"\nPick a category..."<<"\n"<<"\nfruits"<<"\nstates"<<"\ncountries"<<"\ncolor"<<"\nschool"<<"\n"<<std::endl;
  std::cin>>user;
  int counter = 0;
  readFile();//read in data
  pickAnotherNumber:
  shuffleNum();//pick a random number
  bool pickSecretWord = false;
  for(int j=0;j<5;j++)
  {
    if(StoreArray[j].category == user)
    {
      for(int k=0;StoreArray[j].indexStorage[k]<5;k++)
      {
        if(StoreArray[j].indexStorage[k] == indexNum)
        {
          pickAnother = true;
          counter++;
          break;
        }
        else if(k==4 && StoreArray[j].indexStorage[k] != indexNum)
        {
          pickSecretWord = true;
        }
      }
      if(pickSecretWord)
      {
        SecretWord = StoreArray[j].WordArray[indexNum];
          if(StoreArray[j].indexStorage[0] == -1)//stores indices chosen per catergory
          {
            StoreArray[j].indexStorage[0] = indexNum;
          }
          else if(StoreArray[j].indexStorage[1] == -1 && StoreArray[j].indexStorage[0] != -1)
          {
            StoreArray[j].indexStorage[1] = indexNum;
          }
          else if(StoreArray[j].indexStorage[2] == -1 && StoreArray[j].indexStorage[1] != -1)
          {
            StoreArray[j].indexStorage[2] = indexNum;
          }
          else if(StoreArray[j].indexStorage[3] == -1 && StoreArray[j].indexStorage[2] != -1)
          {
            StoreArray[j].indexStorage[3] = indexNum;
          }
          else if(StoreArray[j].indexStorage[4] == -1 && StoreArray[j].indexStorage[3] != -1)
          {
            StoreArray[j].indexStorage[4] = indexNum;
          }
      }
      else if(pickAnother)
      {
        if(counter == 5)
        {
          std::cout<<"\n\nNo more words in this category."<<std::endl;
          goto restart;
        }
        else
        {
          goto pickAnotherNumber;
        }
      }
    }
  }
  while(1)//the game's core loop
  {
  asciiman(attempt);//drawing the asciiman
  if(attempt == 7)
  {
    break;
  }
  win = DisplayWordAndWin(SecretWord, guessed);//displays word and checks win condition
  if (win)
  {
    break;
  }
  std::cout<<"Tries Left: "<<tries<<"\nLetters Guessed: "<<guessed<<"\n\nEnter a letter: ";
  std::cin>>x;//user enters a character
  bool exist = false;
  if (guessed.find(x) == std::string::npos)
  {
    guessed += x;
  }
  if(triesLeft(SecretWord, x))
  {
    attempt++;
    tries--;
  }
  if(tries == 2)//first hint
  {
    for(int j=0;j<5;j++)
    {
      if(StoreArray[j].category == user)
      {
        std::cout<<"\n\nHINT:\n"<<StoreArray[j].hints[indexNum]<<std::endl;
      }
    }
  }
  if(tries == 1)//second hint
  {
    for(int j=0;j<5;j++)
    {
      if(StoreArray[j].category == user)
      {
        std::cout<<"\n\nHINT:\n"<<StoreArray[j].hints2[indexNum]<<std::endl;
      }
    }
  }
}
if(win)
{
  std::cout<<"Winner!!!"<<std::endl;
  std::cout<<"Play Again? (y/n)"<<std::endl;
}
else
{
  std::cout<<"Loser!!!"<<std::endl;
  std::cout<<"Play Again? (y/n)"<<std::endl;
}
std::cin>>playChoice;
if(playChoice == "y")
{
  goto restart;
}
else if(playChoice == "n")
{
  std::cout<<"See Ya Later!"<<std::endl;
  return 0;
}
return 0;
}
//==============================================================================
void readFile()//Input: none    Output:none  Purpose: Read in from file
{
  inputHandler.open("hangmanWords.txt");
  for(int i=0;i<5;i++)
  {
      for(int j=0;j<5;j++)
      {
        inputHandler>>StoreArray[i].category>>StoreArray[i].WordArray[j]>>StoreArray[i].hints[j]>>StoreArray[i].hints2[j];
      }
  }
  inputHandler.close();
}
//------------------------------------------------------------------------------
int shuffleNum() //Purpose: shuffles the random array
{
      srand(time(NULL));
      for(int i=4;i>=1;i--)
      {
        rNumber = rand()%i;
        //RandomIndices[rNumber] = a
        //RandomIndices[i] = b
        //a=a+b
        //b=a-b
        //a=a-b
        RandomIndices[rNumber]=RandomIndices[rNumber]+RandomIndices[i];
        RandomIndices[i]=RandomIndices[rNumber]-RandomIndices[i];
        RandomIndices[rNumber]=RandomIndices[rNumber]-RandomIndices[i];
      }
  indexNum = RandomIndices[0];
  return indexNum;
}
//------------------------------------------------------------------------------
void asciiman(int attempt) //Purpose: switch case for each part of the "Hangman" drawing
{
  std::cout<<" ______"<<"\n|     |"<<std::endl;
  switch(attempt)
  {
    case 1:
    std::cout<<"|"<<"\n|"<<"\n|"<<std::endl;
      break;
    case 2:
    std::cout<<"|     O"<<"\n|"<<"\n|"<<std::endl;
      break;
    case 3:
    std::cout<<"|     O"<<std::endl;
    std::cout<<"|     |"<<"\n|"<<std::endl;
      break;
    case 4:
    std::cout<<"|     O"<<std::endl;
    std::cout<<"|    /|"<<"\n|"<<std::endl;
      break;
    case 5:
    std::cout<<"|     O"<<std::endl;
    std::cout<<"|    /|\\"<<"\n|"<<std::endl;
      break;
    case 6:
    std::cout<<"|     O"<<std::endl;
    std::cout<<"|    /|\\"<<std::endl;
    std::cout<<"|    /"<<std::endl;
      break;
    case 7:
    std::cout<<"|     O"<<std::endl;
    std::cout<<"|    /|\\"<<std::endl;
    std::cout<<"|    / \\"<<std::endl;
      break;
  }
  std::cout<<"|"<<"\n|__________"<<std::endl;
}
//------------------------------------------------------------------------------
bool triesLeft(std::string SecretWord, char x) //Purpose: error checks the user inputs
{
  bool error = false;
  for(int i=0; i<SecretWord.length(); i++)
  {
    if(SecretWord.find(x)==std::string::npos)
    {
      error = true;
    }
  }
  return error;
}
//------------------------------------------------------------------------------
bool DisplayWordAndWin(std::string SecretWord, std::string guessed) //Inputs: Secretword and guessed string Outputs: display word and bool win condition
{
  bool won = true;
  std::string placeHolder;
  for (int i = 0; i < SecretWord.length(); i++)
  {
      if (guessed.find(SecretWord[i]) == std::string::npos)
      {
          won = false;
          placeHolder += "- ";
      }
      else
      {
          placeHolder += SecretWord[i];
          placeHolder += " ";
      }
  }
  std::cout<<placeHolder<<std::endl;
  return won;
}
