#include <iostream>
#include <vector>
#include <fstream>
#include <string>


class hobby{
public:

std::vector<std::string>Hobbies;
std::fstream Fileboi;

void OpenFile(){
Fileboi.open("HobbiesTest", std::ios::in | std::ios::out | std::ios::app);
}

void UI(){
int opt;
std::cout<<"Please select your need:-\n1.See current data\n2.Get suggestion for what to do\n3.Add hours to a hobby\n4.Add Hobbies\n";
std::cin>>opt;
switch(opt){
case 1:
fileDisplay();
break;

case 2:
//todo	
break;

case 3:
//todo
break;

case 4:
FileSave();
break;
}
		
}


	
void Hobinput()
{
int i,range;
std::string Inserter;

std::cout<<"Enter number of hobbies to add!"<<"\n";
std::cin>>i;
std::cout<<"Enter Name of hobbies and number of hours spent on it"<<"\n";
	for(range=1;range<=i;range++)
	{
	std::cin>>Inserter;
	Hobbies.push_back(Inserter);
	}
}


void FileSave()
{
Hobinput();
OpenFile();  //file perms for the program
if (Fileboi.is_open()) 
	{
for (const auto& hob : Hobbies)   //writting the values of the vector Hobbies as a const which changes its val to a standard char and prints as such, the variable hob is where the char is stored as
{
Fileboi<<hob<<std::endl;  
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
}

int GetSize()  //get lines of the file
{
OpenFile();
std::string hob;
int size=0;
while(getline(Fileboi,hob))
size++;
Fileboi.close();
return size;
	
}


int GetHours() //get the hours from the files and throw it out
{
std::string hob,hon;
int hours,i,range=GetSize();

OpenFile();
std::cin>>hon;
for(i=0;i<=range;i++)
{
Fileboi>>hob>>hours;
if(hob==hon)
break;
}
return hours;	
}


void AddHours() //Get values from existing data in the file and then add the hours back in
{
std::cout<<"Please enter the hobby in which you want to add the hours in\n";
int hours=GetHours();
std::cout<<"Current hours:-"<<hours;
}

};

int main()
{
	hobby h;
	//h.UI();
	//h.filesave();
	//h.fileDisplay();
	//h.GetSize();
	//h.GetHours();
	h.AddHours();
	return 0;
}




//todo:-
//make sure this works out right when you are doing consectutive starts of this program
//check the UI function for all major things i want
