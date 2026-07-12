#include <iostream>
#include <vector>
#include <fstream>
#include <string>
//#include <iterator>

class hobby{
public:

std::vector<std::string>Hobbies;
	
int input()
{
int i,range;
std::string Inserter;

std::cout<<"Enter number of hobbies to add!"<<"\n";
std::cin>>i;	
std::cout<<"Enter Name of hobbies"<<"\n";
	for(range=1;range<=i;range++)
	{
	std::cin>>Inserter;
	Hobbies.push_back(Inserter);
	//std::cout<<"Val added";
	}
return i;
}



void filesave()
{
int range=0;	
int is=input();
int i=is;

//auto check =Hobbies.end();

std::fstream Fileboi("HobbiesTest", std::ios::in | std::ios::out | std::ios::trunc);
if(Fileboi.is_open())
std::cout<<"1";


//everything above this works 

//this loop has to add the contents of the vector into the file but its being a bitch 
for(i=is;range<i;range++)
		{
if (Fileboi.is_open()) 
	{
for (const auto& hob : Hobbies) 
{
Fileboi<<hob<<"\n";   //check if the file writes anything regardless of the vector based loop
}
	}
		}
Fileboi.close();
//std::cout<<"Val added";
}
};

int main()
{
	hobby h;
	//h.input();
	h.filesave();
	return 0;
}

//todo:-
//make sure this works out right when you are doing consectutive starts of this program
