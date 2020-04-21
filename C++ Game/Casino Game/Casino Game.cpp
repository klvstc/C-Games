#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

int main()
{cout<<endl;
cout<<"******************************************************"<<endl;
cout<<"**                                                  **"<<endl;
cout<<"**                 CASINO GAME v 1.0                **"<<endl;
cout<<"**                -by Tanishq Agarwal               **"<<endl;
cout<<"******************************************************"<<endl;
cout<<endl;

int amt;
string name;
cout<<"Hey!! there what should I call you:"<<endl;
getline(cin,name);
system("CLS");

cout<<"Enter the Amount you have:"<<endl;
cin>>amt;

do{
system("CLS");
cout<<"Press -1 now if you want to exit"<<endl;

int amt1,guessed;
cout<<"Enter the Amount to Bet:"<<endl;
cin>>amt1;
if(amt1!=-1)
	{srand(time(NULL));
	int random=rand()%6;
	cout<<"Enter the Guessed Number between 0-5:"<<endl;
	cin>>guessed;
	
	if(random==guessed)
		{amt=amt+amt1*2;
		 cout<<"Yeah "<<name<<" you got it right"<<endl;
		 cout<<"Your Total Amount is "<<amt<<endl;}
	else
		{amt=amt-amt1;
		 cout<<"You got it wrong, The right answer was "<<random<<endl;
		 cout<<"Better Luck next time "<<name<<endl;
		 cout<<"You are now left with "<<amt<<endl;}
		 _sleep(5000);
	}}while(amt!=-1);
	
cout<<"You are finally left with "<<amt<<endl;		
return 0;
}
