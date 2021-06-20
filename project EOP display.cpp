#include <iostream>

using namespace std;

int display() {
    
    int input;
    
    cout<<"COVID-19 Screening Procedure"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0. End Program"<<endl;
    cout<<"1. Homepage"<<endl;
    cout<<"2. Edit"<<endl;
    cout<<"3. Search"<<endl;
    cout<<"4. Remove"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"Enter 0-4: ";
    cin>>input;
    
    return input;
}

int main()
{
    string fname[100];
    string lname[100];
    int age[100];
    string country[100];
    int arrival_date[100];
    string arrival_month[100];
    int phone_number[12];
    
    int option = display();
    
    while(option != 0) {
        switch(option) {
            case 1:
              cout<<"Press to go to the homepage"<<endl;
              break;
            case 2:
              cout<<"Edit details"<<endl;
              break;
            case 3:
              cout<<"Search"<<endl;
              break;
            case 4:
              cout<<"Remove"<<endl;
              break;
            default:
              cout<<"Incorrect input"<<endl;
              break;
        }
        
        option = display();
    }
    
    cout<<"End of the program";

    return 0;
}