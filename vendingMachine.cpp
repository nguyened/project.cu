//Created by Evan Nguyen
//Vending Machine Program
//Purpose: To allow the user to buy and check the inventory of various vending machines across campus.
//Last Modified: April 8, 2018
#include<iostream>
#include<string>
#include<fstream>
#include<cstring>

std::fstream FileHandler;

struct Location {
  std::string buildName;
  std::string floorLevel;
};

struct Drink {
  std::string drinkName;
  float drinkSize;
  float drinkPrice;
};

struct VendingMachine {
  Location locat;
  int drinks[4];
};

VendingMachine AllVendingMachines[5];
std::string line;
std::string trash;
std::string building;
std::string floorStr;
int floorNum;
int vend;
int drinkChoice;
std::string location;
std::string choice;
//------------------------------------------------------------------------------
void menu();
//==============================================================================
//==============================================================================
int main(){
  FileHandler.open("vendingmachinedata.txt");
  if(!FileHandler){
    std::cout << "File could not be opened." << std::endl;
    return -1;
  }
  for (int i=0;i<5;i++) {
    for (int j=0;j<10;j++) {
        getline(FileHandler,building,' ');
        getline(FileHandler,floorStr,' ');
        getline(FileHandler,line,' ');
        getline(FileHandler,trash);
      if (line == "Coke") {
        AllVendingMachines[i].drinks[0]++;
      } else if (line == "Sprite") {
        AllVendingMachines[i].drinks[1]++;
      } else if (line == "DietCoke") {
        AllVendingMachines[i].drinks[2]++;
      } else if (line == "DrPepper") {
        AllVendingMachines[i].drinks[3]++;
      }
    }
    AllVendingMachines[i].locat.buildName = building;
    AllVendingMachines[i].locat.floorLevel = floorStr;
  }
  std::cout << "Clarkson Univeristy's Vending Machines!" << std::endl;
  while (2*2-1==3) {//quickmaths
    menu();
  }
  FileHandler.close();
  return 0;
}

//==============================================================================
//==============================================================================
void menu(){
  start:
  std::cout<<"Buy or Show?"<<std::endl;
  getline(std::cin,line);
  for (int i=0;i<line.length();i++) {
    line[i]=toupper(line[i]);
  }
  if (line == "SHOW") {
    for (int i=0;i<5;i++) {
      std::cout<<AllVendingMachines[i].locat.buildName<<" "<<AllVendingMachines[i].locat.floorLevel<<std::endl<<"\tCoke: "<<AllVendingMachines[i].drinks[0]<<"\n\tSprite: "<<AllVendingMachines[i].drinks[1]<<"\n\tDiet Coke: "<<AllVendingMachines[i].drinks[2]<<"\n\tDr. Pepper: "<<AllVendingMachines[i].drinks[3]<<std::endl;
    }
  } else if (line == "BUY") {
    buy:
    std::cout<<"Choose your location. Choices: Snell 1, Snell 3, ScienceCenter 3, CAMP 1, TAC 2"<<std::endl;
    getline(std::cin,line);
    for (int i=0;i<line.length();i++) {
      line[i]=toupper(line[i]);
    }
    if (line == "SCIENCE CENTER 3") {
      line = "SCIENCECENTER 3";
    }
    if (line == "SNELL 1") {
      vend = 2;
    } else if (line == "SNELL 3") {
      vend = 0;
    } else if (line == "SCIENCECENTER 3") {
      vend = 1;
    } else if (line == "CAMP 1") {
      vend = 3;
    } else if (line == "TAC 2") {
      vend = 4;
    } else {
      std::cout<<"Enter a correct name please."<<std::endl;
      goto buy;
    }
    drink:
    std::cout<<"Choose a drink. Choices: Coke, DietCoke, DrPepper, Sprite"<<std::endl;
    getline(std::cin,line);
    for (int i=0;i<line.length();i++) {
      line[i]=toupper(line[i]);
    }
    if (line == "COKE" || line == "DIETCOKE" || line == "DRPEPPER" || line == "SPRITE") {
      choice = line;
    } else {
      std::cout<<"try again"<<std::endl;
      goto drink;
    }
    size:
    std::cout<<"Choose a size. Choices in stock: ";
    if (choice == "COKE" || choice == "SPRITE") {
      if (choice == "COKE") {
        drinkChoice = 0;
      } else {
        drinkChoice = 1;
      }
      std::cout<<"1"<<std::endl;
    } else {
      if (choice == "DIETCOKE") {
        drinkChoice = 2;
      } else {
        drinkChoice = 3;
      }
      std::cout<<"1.5"<<std::endl;
    }
    getline(std::cin,line);
    if ((line != "1" && (choice == "COKE" || choice == "SPRITE")) || line != "1.5" && (choice == "DIETCOKE" || choice == "DRPEPPER")) {
      std::cout<<"Invalid size choice. try again"<<std::endl;
      goto size;
    } else {
      if (AllVendingMachines[vend].drinks[drinkChoice] >= 1) {//successful buy
        std::cout<<"Here's your drink."<<std::endl;
        AllVendingMachines[vend].drinks[drinkChoice]--;
      } else {
        std::cout<<"Out of stock. Try again from the top."<<std::endl;
        return;
      }
    }
  }
  else {
    std::cout<<"try again"<<std::endl;
    goto start;
  }
}
