//Created by Evan Nguyen
//Purpose: Banking Program
//Last Modified: April 12, 2018
#include<iostream>
#include<string>
#include<fstream>

//==========================================================================
float acctBal;             //Account balance
float tempAmt;		         //Temporary amount
std::string accountNum;		 //Account Number
std::string firstName;     //First name
std::string lastName;      //Last name
std::string accountNumF;		 //Account Number Found
std::string firstNameF;     //First name Found
std::string lastNameF;      //Last name Found
std::string find;						//Find
char usrCmd;               //User command
//=========================================================================
bool firstnameValid = false;
bool lastnameValid = false;
bool nameValid = false;
bool loop;
bool leave = false;
bool works;

std::string line;

std::fstream acc;
std::fstream accLog;

int section1 = line.find(" ");
int section2 = line.find(" ",section1+1);
int section3 = line.find(" ",section2+1);
int section4 = line.find(" ",section3+1);
std::string action;
std::string startingBalance;
std::string transAmt;
std::string endingBalance;
//=============================================================================
void nameValidation(std::string);
void numValidation(std::string);
void menu();
//=============================================================================

int main()
{
		//Below is the beginning and Welcome screen for the program.
	do {
		repeat1:
		loop = false;
		std::cout << "Enter your full name: " << std::endl;
		std::cin >> firstName >> lastName;
		nameValidation(firstName);
		nameValidation(lastName);
		if (loop)
			goto repeat1;
		repeat2:
		loop = false;
		std::cout << "Enter your account number: " << std::endl;
		std::cin >> accountNum;
		numValidation(accountNum);
		 if (loop)
		 	goto repeat2;
		std::cout << std::endl;
		std::cout << "Welcome, " << firstName << " " << lastName << ", to Secure Banking!" << std::endl;
	} while (loop);

	std::ifstream acc;
	acc.open("accounts.txt",std::ios::app);
	bool exists = true;

	while (!acc.eof()) {
		acc >> find;
		if(find == firstName)
		{
			firstNameF = find;
		}
	  if(find == lastName)
			{
				lastNameF = find;
			}
		if(find == accountNum)
				{
					accountNumF = find;
				}
		if(firstName != firstNameF || lastName != lastNameF || accountNum != accountNumF)
		{
			exists = false;
		}
		else
		{
			exists = true;
			leave = true;
		}
	}

	if (!exists) {
		std::cout << "Can not find your account. Would you like to create one? Y/N" << std::endl;
		do {
			getline(std::cin,line);
			if (line == "Y" || line == "y" || line == "Yes") {
				do {
					std::cout << "Enter your account balance: " << std::endl;
					std::cin >> acctBal;
				} while (acctBal < 0);
				std::ofstream acc("accounts.txt",std::ios::app);
				acc << accountNum << " " << firstName << " " <<lastName << " " << acctBal << std::endl;
			} else if (line == "N" || line == "n" || line == "No") {
				return 0;
			} else {
				std::cout << "Only enter Y/N" << std::endl; //always runs this first time for some reason
			}
		} while (line != "Y" && line != "y" && line != "Yes" && line != "N" && line != "n" && line != "No");
	}
	acc.close();
	accLog.open("accountLogs.txt",std::ios::app);
	leave=true;
	while (leave)
	{
		menu();
	}
	return 0;
}
//==================================================================================================================
void nameValidation(std::string input)
{
	if (input.length() < 2 || input.length() > 10){
				loop = true;
				std::cout<<"ERROR: Both names must be 2-10 characters"<<std::endl;
				return;
	}
	if (!isupper(input[0])) {
		loop = true;
		std::cout<<"ERROR: First letter must be capital"<<std::endl;
	}
	for (int i=0;i<firstName.length();i++) {
		if (!isalpha(input[i])) {
			if (input[i] == '-') {
				if (isupper(input[i+1])) {
					loop = true;
					std::cout<<"ERROR: Capitalize after your hyphen"<<std::endl;
					return;
				} else {
				loop = true;
				std::cout<<"ERROR: Use only letters and hyphens in both names"<<std::endl;
				return;
			}
		}
	}
}
}

void numValidation(std::string input) {
	if (input.length() == 8) {
		for (int i=0;i<input.length();i++) {
			if (!isdigit(input[i])) {
				loop = true;
				std::cout<<"ERROR: Use only digits and hyphens"<<std::endl;
				return;
				}
			}
		}
	 else {
		if (input.length() == 10 && input.find("-") == 3 && input.find("-",4) == 7 && input.find("-",8) == std::string::npos) {
			accountNum = input.substr(0,3) + input.substr(4,3) + input.substr(8,2);
		} else {
			loop = true;
			std::cout<<"ERROR: Check that account number is 8 digits and 0 or 2 hyphens"<<std::endl;
			return;
		}
	}
}
//=============================================================================================================================
void menu()  {
	std::cout << std::endl;
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "Type D to deposit." << std::endl;
	std::cout << "Type W to withdraw." << std::endl;
	std::cout << "Type S to show balance." << std::endl;
	std::cout << "Type Q to leave." << std::endl;
	std::cin >> usrCmd;
	usrCmd = toupper(usrCmd);

	switch(usrCmd)     //switch states each case for if the user enters in uppercase or lowercase
	{
		case 'D':  //Case D and d are for depositing.

		do {
			std::cout << "Enter deposit amount: " << std::endl;
			std::cin >> tempAmt;
		} while (tempAmt <= 0);
			accLog << accountNum <<" "<<"Deposit"<<" "<<acctBal<<" "<<tempAmt<<" "<<acctBal+tempAmt<<std::endl;
			acctBal =  tempAmt + acctBal;
			std::cout << std::endl;
			std::cout << "Your new balance is $" << acctBal << std::endl;
			break;

		case 'W':  //Case W and w are for withdrawals.
		do {
			std::cout << "Enter withdrawal amount: " << std::endl;
			std::cin >> tempAmt;
		} while (tempAmt <= 0 || tempAmt > acctBal);
			accLog << accountNum <<" "<<"Withdraw"<<" "<<acctBal<<" "<<tempAmt<<" "<<acctBal-tempAmt<<std::endl;
			acctBal = acctBal-tempAmt;
			std::cout << std::endl;
			std::cout << "Your new balance is $" << acctBal << std::endl;
			break;

		case 'S':  //Case S and s are for showing the user's balance.
			std::cout << std::endl;
			accLog.close();
			accLog.open("accountLogs.txt");
			//accLog.seekg(0);
			while (getline(accLog,line)) {
				works = true;
				for (int i=0;i<accountNum.length();i++) {
					if (line[i] != accountNum[i]) {
						works = false;
					}
				}
				if (works) {
					section1 = line.find(" ");
					section2 = line.find(" ",section1+1);
					section3 = line.find(" ",section2+1);
					section4 = line.find(" ",section3+1);
					action = line.substr(section1,section2-section1);
					startingBalance = line.substr(section2,section3-section2);
					transAmt = line.substr(section3,section4-section3);
					endingBalance = line.substr(section4,std::string::npos);
					// getline(line,action,"|");
					// getline(line,startingBalance,"|");
					// getline(line,transAmt,"|");
					// getline(line,endingBalance);

					std::cout<<"Action: "<<action<<std::endl;
					std::cout<<"Starting Balance: $"<<startingBalance<<std::endl;
					std::cout<<action<<" Amount: $"<<transAmt<<std::endl;
					std::cout<<"Ending Balance: $"<<endingBalance<<std::endl;
					std::cout<<std::endl;
				}
			}
			accLog.close();
			accLog.open("accountLogs.txt",std::ios::app);
			break;

		case 'Q':  //Case Q and q are for the user leaveing the program.
			std::cout << "Thank you! Goodbye!" << std::endl;
			leave = false;
			break;
	}
}
