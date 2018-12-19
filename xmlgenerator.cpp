
//Lab6
//Created by Evan Nguyen
//Purpose: To read a txt list of names and create and export an xml of email addresses
//Last Modified: March 4, 2018

#include<iostream>
#include<string>
#include<fstream>

void emailFunction(std::string);

//=============Variables=============
std::ifstream inText;
std::ofstream xmlEmail;
std::string fname;
std::string lname;
std::string sLname;
std::string userEmail;
//===================================

int main()
{
	inText.open("employeeNames.txt");
	xmlEmail.open("employeesXMLData.xml");
	inText >> fname >> lname;
	while(!inText.eof())
	{
		emailFunction(lname);
		userEmail[0] = tolower(userEmail[0]);
		xmlEmail << "<person>\n" << "<firstname>" << fname << "</firstname>\n" << "<lastname>" << lname << "</lastname>\n" << "<email>" << userEmail << "@company.com" << "</email>\n" << "</person>\n";
		inText >> fname >> lname;
	}
	inText.close();
	xmlEmail.close();
	return 0;
}

//Function Purpose: uses the first seven letters of a last name to create a username for an email
//Input: lastname
//Output: an email username composed of the initial of a firstname and the first seven letters of a lastname (all lowercase)
void emailFunction(std::string lname)
{
	if(lname.length() > 7)
	{
		sLname = "";
		for(int i=0; i<7; i++) //loop re-assigns the first seven letters of a lastname into a new varible called "sLname"
		{
			sLname = sLname + lname[i];
		}
	}
	else
	{
		sLname = lname;
	}
	sLname[0] = tolower(sLname[0]);
	userEmail = fname[0] + sLname;
}
