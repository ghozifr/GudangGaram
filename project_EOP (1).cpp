#include <iostream>

using namespace std;

string fname, lname;
    string country;
    int arrival_date;
    string arrival_month;
    int phone_number;
    int age;



void dots(){
	cout<<endl<<"................................................................................"<<endl;
}
        

int homePage(){
	do{
		cout<<"Enter your age: ";
    cin>>age;
	}while(age<=0);
    
    if (age > 0 && age <= 16) {
        cout<<"Ask your parents to fill in your details in this form."<<endl;
        
        cout<<"Please enter your child's full name: ";
        cin>>fname>>lname;
    } else if (age >= 17) {
        cout<<"Please fill in your details in this form."<<endl;
        
        cout<<"Please enter your first name: ";
        cin>>fname;
        
        cout<<"Please enter your last name: ";
        cin>>lname;
        
    } else {
        cout<<"Program terminated. Please start over again.";
    }
    
    cout<<"Enter your country of origin: ";
    cin>>country;
    
    cout<<"Enter your arrival date and the month(dd mm): ";
    cin>>arrival_date>>arrival_month;
    cout<<endl;
    
    cout<<"Arrived on the "<<arrival_date<<" of "<<arrival_month<<".";
    
    cout<<"Enter your phone number: ";
    cin>>phone_number;
}








int main()
{
    
    dots();
    cout<<"Welcome passengers arriving in Malaysia.";
    cout<<"\nYou are currently in the Kuala Lumpur International Airport!";
    cout<<"\nPlease kindly proceed to the COVID-19 screening area.";
    dots();
    homePage();
    return 0;
}
