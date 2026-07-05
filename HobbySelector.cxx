#include <iostream>
#include <vector>
#include <fstream>
#include <string>

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
	}
return i;
}



void filesave()
{
int range=1;	
int is=input();
int stuff=Hobbies.size()-1;

std::fstream Fileboi("/home/chirag/Code/Personal/HobbySelector/HobbiesTest");
Fileboi.open("/home/chirag/Code/Personal/HobbySelector/HobbiesTest");


//everything above this works 

//this loop has to add the contents of the vector into the file but its being a bitch 
for(int i=is;range<=i;range++)
{
Fileboi<<Hobbies[stuff];				
stuff++;
}
//this loop is a bitch 
Fileboi.close();
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
