#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>


class hobby{
public:

std::vector<std::string>Hobbies;
std::fstream Fileboi;


void OpenFile(){
Fileboi.open("HobbiesData", std::ios::in | std::ios::out | std::ios::app);
}

void UI(){
int opt,chance=0;
while(chance==0)
{
std::cout<<"Please select your need:-\n1.See current data\n2.Get suggestion for what to do\n3.Add hours to a hobby\n4.Add Hobbies\n5.Clear Screen\n6.Exit\n";
std::cin>>opt;
switch(opt){
case 1:
fileDisplay();
break;

case 2:
//todo	
break;

case 3:
ReFile();
break;

case 4:
FileSave();
break;

case 5:
std::system("clear");
break;

case 6:
chance=1;
break;
}
}		
}


	
void Hobinput()  //Asks the user for hobbies and hours
{
int i,range;
std::string Inserter;

std::cout<<"Enter number of hobbies to add!"<<"\n";
std::cin>>i;
std::cout<<"Enter Name of hobbies and number of hours spent on it"<<"\n";
	for(range=1;range<=i+1;range++)
	{
	  std::getline(std::cin, Inserter);
	  Hobbies.push_back(Inserter);
	}
}


void FileSave()  //writes the users hobbies and hours to the file
{
Hobinput();
OpenFile();  //file perms for the program
if (Fileboi.is_open()) 
	{
for (const auto& hob : Hobbies)   //writting the values of the vector Hobbies as a const which changes its val to a standard char and prints as such, the variable hob is where the char is stored as
{
Fileboi<<hob<<" "<<"\n";  
}
	}
Fileboi.close();  //closes the opened file, techincally not needed by still

}

void fileDisplay() //read data from file when need to be printed
{
OpenFile();
std::string line;
while(getline(Fileboi,line))
{
std::cout<<line<<"\n";	
}
Fileboi.close();
}

int GetSize()  //get lines of the file
{
OpenFile();
std::string hob;
int size=0;
while(getline(Fileboi,hob))   //goes through each line and increaments the size variables, gives total lines of the file
size++;
Fileboi.close();
return size;
	
}

std::string GetHob()  //gets the hobby in which the user needs to change the hours in
{
std::string hob;
std::cout<<"Please enter the hobby in which you want to add the hours in\n";
std::cin>>hob;
return hob;	
}



int GetHours() //gets the hours from the files and throw it out
{
std::string hon,hob=GetHob();
int hours,i,range=GetSize();

OpenFile();

for(i=0;i<=range;i++)
{
Fileboi>>hob>>hours;
if(hon==hob)
break;
}
Fileboi.close();
return hours;	
}


int AddHours() //Get values from existing data in the file and then add the hours togather and then send it out to the Refile function to remake the file after adding everything
{
int ExHours,NewHours;
int hours=GetHours();
std::cout<<"Current hours:-"<<hours<<std::endl;
std::cout<<"Enter hours you want to add:-";
std::cin>>ExHours;
NewHours=ExHours+hours;
return NewHours;
}

void ReFile()
{
int Hours=AddHours();
std::string hoby=GetHob();
OpenFile();
std::string hob;
int hou;
std::fstream ReFileBoi;
ReFileBoi.open("ReHobbiesData",std::ios::in | std::ios::out | std::ios::app);

rename("ReHobbiesData", "HobbiesData");
while(Fileboi>>hob>>hou)
{
if(hoby==hob)
hou=Hours;	
ReFileBoi<<hob<<" "<<hou<<std::endl;	
}
}

};

int main()
{
	hobby h;
	h.UI();
	return 0;
}




//todo:-
//Make the suggestion algoritham
//check the UI functions for all major things i want
//Make a feature to update hours instead of just having add hours
//Make a feature to update the hobby name
