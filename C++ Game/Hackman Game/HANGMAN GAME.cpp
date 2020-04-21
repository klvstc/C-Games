#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

string unknown;
int display(string str, int choice)
{unknown="";
int i=0,i1;
for(i=0;i<str.size();i++)
 {if(str[i]!=32)
	{unknown+=str[i];}
 else
 	{unknown+=" ";
 	 break;}}
if(choice==3||choice==1)
	{unknown+=str[1];
	 i++;}
i1=i;	 
for(;i<str.size()-1;i++)
 {unknown+="*";}
 return i1;
}

int letterFill (char guess, string secretword, string &guessword,int i)
{
	int matches=0;
	int len=secretword.length();
	for (; i< len; i++)
	{	if (guess==guessword[i])
			return 0;
		if (guess==secretword[i])
		   {guessword[i] = guess;
			matches++;}	
		if (guess==secretword[i]+32)
		   {guessword[i] = guess-32;
			matches++;}			
	}
	return matches;
}

void game(string name,int choice)
{ifstream file;
if(choice==1)
	{file.open ("Country.txt");}
else if(choice==2)
	{file.open ("cars.txt");}
else if(choice==3)
	{file.open ("Brands.txt");}
system("CLS");	

cout<<"Loading Game........"<<endl;
cout<<"Let us take you through the Instructions till then:"<<endl;
cout<<"1. The Game will have 5 Questions of 2 Pt each."<<endl;
cout<<"2. You will have 5 Chances to enter the correct Letter, or the Question will be Skipped with 0 Pt"<<endl;
cout<<"3. Enter all input in lower case only"<<endl;
cout<<endl;
for(int j=0;j<100;j++)
{cout<<"|";
_sleep(10);}

string no;
int nu;
getline(file,no);
stringstream a(no);
a>>nu;
string s[nu];
for(int i=0;i<nu;i++)
	{getline(file,s[i]);}
file.close();	
system("CLS");
char c;
int marks=0;		

srand(time(NULL));
for(int i=0;i<5;i++)
{int turn=0;
int random=rand()%nu;
int index=display(s[random],choice);
char letter;
cout<<"Question No:"<<i+1<<endl;

	while (turn<5)
		{	cout<<unknown;
		    cout << "\nGuess a letter: ";
			cin >> letter;
	
			if (letterFill(letter, s[random], unknown, index)==0)
			{cout << endl << "Whoops! That letter isn't in there!" << endl;
			 turn++;}
			else
			{cout << endl << "You found a letter! Isn't that exciting!" << endl;}
			cout << "You have " << 5-turn<< " guesses left." << endl;
			cout<<endl;
			if (s[random]==unknown)
			{
				cout << s[random] << endl;
				cout << "Yeah! You got it!";
				cout<<endl;
				marks=marks+2;
				break;
			}
		}
	if(turn==5)
	{
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was : " << s[random] << endl;
		cout<<endl;
	}
	cout<<name<<", Your Total Score is "<<marks<<endl;
	_sleep(2000);
	system("CLS");
}
cout<<name<<", you were Awesome in the Game!!"<<endl;
cout<<"Your Final Score is "<<marks<<endl;
cout<<"See you Again"<<endl;
}

int main()
{cout<<endl;
cout<<"*************************************************"<<endl;
cout<<"**                                             **"<<endl;
cout<<"**               HANGMAN C++ v1.0              **"<<endl;
cout<<"**             -By Tanishq Agarwal             **"<<endl;
cout<<"*************************************************"<<endl;

cout<<"Enter your Good Name, there:"<<endl;
string name;
getline(cin,name);

cout<<endl;
cout<<"1: Menu"<<endl;
cout<<"2: Exit"<<endl;
int opt;
cin>>opt;
cout<<endl;
cout<<endl;
if(opt==1)
	{cout<<"Enter Sub-Game you want to play with:"<<endl;
	 int choice;
	 cout<<"1: The Countryside (Country-Name Guessing)"<<endl;
	 cout<<"2: The Roadside Romeo (Best Selling Car-Name Guessing)"<<endl;
	 cout<<"3: Brand-a-zoma (Brand Name Guessing)"<<endl;
	 cin>>choice;
	 game(name,choice);
	}
else if(opt==2)
	return 0;	

}
