#include <iostream>

using namespace std;

void dots(){
	cout<<endl<<"................................................................................"<<endl;
}           

int main()
{
    string fname, lname;
    int age;
    string country;
    int arrival_date;
    string arrival_month;
    int phone_number;
    
    dots();
    cout<<"Welcome passengers arriving in Malaysia.";
    cout<<"\nYou are currently in the Kuala Lumpur International Airport!";
    cout<<"\nPlease kindly proceed to the COVID-19 screening area.";
    dots();
    
    cout<<"Enter your age: ";
    cin>>age;
    
    if (age > 1 && age < 18) {
        cout<<"Ask your parents to fill in your details in this form."<<endl;
        
        cout<<"Please enter your child's full name: ";
        cin>>fname>>lname;
    } else if (age >= 18) {
        cout<<"Please fill in your details in this form."<<endl;
        
        cout<<"Please enter your full name: ";
        cin>>fname>>lname;
    } else {
        cout<<"Program terminated. Please start over again.";
    }
    
    cout<<"Enter your country of origin: ";
    cin>>country;
    
    cout<<"Enter your arrival date and the month: ";
    cin>>arrival_date>>arrival_month;
    cout<<endl;
    
    cout<<"Arrived on the "<<arrival_date<<" of "<<arrival_month<<".";
    
    cout<<"Enter your phone number: ";
    cin>>phone_number;

    return 0;
}
