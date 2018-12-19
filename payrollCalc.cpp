//Created by Evan Nguyen
//Purpose: To Calculate Payroll
//Last Modified: April 22, 2018
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<cmath>

using namespace std;

enum days {MON,TUE,WED,THU,FRI};

struct Person {
  string fn;
  string mn;
  string ln;
};
struct Wage {
  float hourlyWage;
  float overRate;
  char overEli;
};
struct timeCard {
  float hoursWorked;
  float lunchBreakLength;
  float overTimeHours;
  float totalPay;
};
struct employee {
  Person empName;
  Person empManager;
  Wage empWage;
  timeCard timecard[5];
  timeCard weekly;
  string department;
};
employee Employees[20];
//------------------------------------------------------------------------------
float timeToInt(std::string);
void readData(string);
float hoursWorked(string,string,string,string);
float breakLength(string,string,string,string);
float overtime(string,string,string,string);
float totalPay(float,float,float,float,char);
void writeData(string);
//------------------------------------------------------------------------------
//==============================================================================
int main(){
  string userNamefile;
  cout<<"CS141 Payroll Calculator"<<endl;
  cout<<"Enter a file name to read: "<<endl;
  cin>>userNamefile;
  readData(userNamefile);
  cout<<"Enter a file name to write(must be an xml file): "<<endl;
  cin>>userNamefile;
  writeData(userNamefile);
  cout<<"Done!"<<endl;
  return 0;
}
//==============================================================================
float timeToInt(std::string timeInString){
  //Find the location of the :
  int locOfDivider=timeInString.find(':');
  string timeHours=timeInString.substr(0, locOfDivider);
  string timeMins=timeInString.substr(locOfDivider+1, timeInString.length());
  float timeHoursInt;
  std::istringstream(timeHours) >> timeHoursInt;
  float timeMinsInt;
  std::istringstream(timeMins) >> timeMinsInt;
  return timeHoursInt+(timeMinsInt/60);
}
//------------------------------------------------------------------------------
float hoursWorked(string clockIN, string lunchStart, string lunchEnd, string clockOUT){
  return (timeToInt(clockOUT)-timeToInt(clockIN))-(timeToInt(lunchEnd)-timeToInt(lunchStart));
}
//------------------------------------------------------------------------------
float breakLength(string clockIN,string lunchStart, string lunchEnd, string clockOUT){
  return timeToInt(lunchEnd)-timeToInt(lunchStart);
}
//------------------------------------------------------------------------------
float overtime(string clockIN,string lunchStart, string lunchEnd, string clockOUT){
  float hoursPerDay = (timeToInt(clockOUT)-timeToInt(clockIN))-(timeToInt(lunchEnd)-timeToInt(lunchStart));
  if (hoursPerDay>=7.5){
    return hoursPerDay-7.5;
  }
  else{
    return 0;
  }
}
//------------------------------------------------------------------------------
float totalPay(float hoursWorked,float overTimeHours,float hourlyWage, float overRate, char overEli){
  if(overEli == 'Y')
    return (7.5*hourlyWage)+(overTimeHours*hourlyWage*overRate);
  else if (overEli == 'N')
    return hoursWorked*hourlyWage;
  else {
    cout<<"error"<<endl;
    return -1;
  }
}
//------------------------------------------------------------------------------
void readData(string userFile){
  ifstream inputhandler;
  inputhandler.open(userFile.c_str());
  int x=0;
  string endtime;
  while(x<20){
    string starttime;
    string lunchstart;
    string lunchend;
    Employees[x].weekly.totalPay=0;
    Employees[x].weekly.overTimeHours=0;
    Employees[x].weekly.lunchBreakLength=0;
    Employees[x].weekly.hoursWorked=0;
    for(int i=0;i<5;i++){
      inputhandler>>Employees[x].empWage.hourlyWage>>Employees[x].empWage.overEli>>Employees[x].empWage.overRate>>Employees[x].empName.fn>>Employees[x].empName.mn>>Employees[x].empName.ln>>Employees[x].department>>Employees[x].empManager.fn>>Employees[x].empManager.mn>>Employees[x].empManager.ln>>starttime>>lunchstart>>lunchend>>endtime;
      //value per day
      Employees[x].timecard[i].hoursWorked=hoursWorked(starttime,lunchstart,lunchend,endtime);
      Employees[x].timecard[i].lunchBreakLength=breakLength(starttime,lunchstart,lunchend,endtime);
      Employees[x].timecard[i].overTimeHours=overtime(starttime,lunchstart,lunchend,endtime);
      Employees[x].timecard[i].totalPay=totalPay(Employees[x].timecard[i].hoursWorked,Employees[x].timecard[i].overTimeHours,Employees[x].empWage.hourlyWage,Employees[x].empWage.overRate,Employees[x].empWage.overEli);
      //sum of values for totals per week
      Employees[x].weekly.totalPay+=Employees[x].timecard[i].totalPay;
      Employees[x].weekly.hoursWorked+=Employees[x].timecard[i].hoursWorked;
      Employees[x].weekly.overTimeHours+=Employees[x].timecard[i].overTimeHours;
      Employees[x].weekly.lunchBreakLength+=Employees[x].timecard[i].lunchBreakLength;
      }
    x++;
  }
  inputhandler.close();
}
//------------------------------------------------------------------------------
void writeData(string userFile) {
  if (userFile.substr( userFile.size()-4) != string(".xml")) {
    cout<<"filenames is incorrect, try again"<<endl;
    return;
  }
  ofstream outputhandler;
  outputhandler.open(userFile.c_str());
  int x=0;
  outputhandler<<"<payroll>\n";
  while(x<20) {
  outputhandler<<"   <employee>\n      <name>"<< Employees[x].empName.fn<<" "<<Employees[x].empName.mn<<" "<<Employees[x].empName.ln<<"</name>\n";
  outputhandler<<"      <manager>"<< Employees[x].empManager.fn<<" "<<Employees[x].empManager.mn<<" "<<Employees[x].empManager.ln<<"</manager>\n";
  outputhandler<<"      <department>"<<Employees[x].department<<"</department>\n      <payrate>";
  outputhandler<<Employees[x].empWage.hourlyWage<<"</payrate>\n      <overtime>";
  if(Employees[x].empWage.overEli=='Y') {
    outputhandler<<"Yes";
  }
  else {
    if(Employees[x].empWage.overEli=='N') {
    outputhandler<<"No";
    }
    else {
      outputhandler<<"error";
    }
  }
 outputhandler<<"</overtime>\n      <multiplier>"<< Employees[x].empWage.overRate << "</multiplier>\n      <hours>"<<((floor((Employees[x].weekly.hoursWorked)*100))/100) <<"</hours>\n      <overhours>";
 outputhandler<<((floor((Employees[x].weekly.hoursWorked-37.5)*100))/100) <<"</overhours>\n      <lunch>"<<Employees[x].weekly.lunchBreakLength<<"</lunch>\n      <pay>"<< ((floor((Employees[x].weekly.totalPay)*100))/100) <<"</pay>\n   </employee>\n";
x++;
}
outputhandler<<"</payroll>";
  outputhandler.close();
}
