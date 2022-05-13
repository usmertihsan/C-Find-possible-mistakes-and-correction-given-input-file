#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Date
{
	public:
	int day,year;
	string month;
	Date(int d,string m,int y) : day(d), month(m),year(y) {	}		
};
class Person
{
	private:	
	string first,last;
	Date birthdate;		
	public:
	Person(string f, string l, int da, string mon, int yea) : birthdate(da,mon,yea)	{first=f;last=l;}
	void setMonth(string m);
	void printInfo(ostream &);
	int getDay() {return birthdate.day;};
	int getYear() { return birthdate.year;};
};
void Person::setMonth(string m)
{
	birthdate.month=m;
}
void Person::printInfo(ostream &a)
{	
    a<<first<<" "<<last<<" -- "<<birthdate.month<<" "<<birthdate.day<<","<<" "<<birthdate.year<<endl;	
}
int main(void)
{
	int day,year;
	string first,last,month;
	string months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	ifstream input("input.txt", ios::in);
	ofstream output("output.txt", ios::out);
	int i=0;
	string temporary;
	bool a;
	a=true;
	while(!input.eof())
	{
		input>>first>>last>>day>>month>>year;		
		try
		{
			if(day>31 || year>2020)
		    throw Person(first,last,day,month,year);			
			else	
			try
			{
				for(i=0;i<12;i++)
				{
					
				  if(month.substr(0,3)==months[i].substr(0,3))
					{
						a=false;
						throw Person(first,last,day,month,year);		
					}			
				}								
				if(a)
				cout<<"Incorrectly inputted month:"<<month<<endl;
			}	
			catch(Person &b)
			{									  
			  for(i=0;i<12;i++)
				{							
				if (month.substr(0,3)==months[i].substr(0,3))
				temporary=months[i];
			    }			    
			   if(temporary!=month)				
			   cout<<"Incorrectly inputted month:"<<month<<" "<<"is corrected to"<<" "<<temporary<<endl;			   
			   b.setMonth(temporary);
			   b.printInfo(output);
			   a=true;    
		}			
   	}	
   	catch(Person &a )
		{
			if(a.getDay()>31 )
			cout<<"Incorrectly input for day/year:"<<a.getDay()<<endl;			
			else if(a.getYear()>2020)
			cout<<"Incorrectly input for day/year:"<<a.getYear()<<endl;
		}
}
}
