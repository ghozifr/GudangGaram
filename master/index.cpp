#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

struct Passengers{
	//int num;
	string age;
	string name;
	string country;
	string phone;	
};
int getOption();
void printData(Passengers list[], int length);
void getData(ifstream& inFile, Passengers list[], int listSize);
void addDataPassengers(ifstream &inFile);
void saveData(ofstream& outF, Passengers list[], int length);


int main(){
	
	Passengers cap[30];
	int noOfPassengers = 30;
	
	ifstream inFile;
	ofstream outFile;
	
	inFile.open("input.txt");
	if(!inFile)
	{
		cout<<"Input file does not exist. Please create new file."<<endl;
		return 1;
		
	}
    Passengers PassengersList[noOfPassengers];
    
	
	
	int userOption = getOption();
	char is_continue;
	
	while(userOption != 6){
		
		switch(userOption){
			case 1:
			cout<<"Register"<<endl;
			addDataPassengers(inFile);
			saveData(outFile, cap, noOfPassengers);
			break;
			case 2:
			cout<<"Display"<<endl;
			printData(cap, noOfPassengers);
			break;
			case 3:
			cout<<"Edit"<<endl;
			break;
			case 4:
			cout<<"Delete"<<endl;
			break;
			case 5:
			cout<<"Search"<<endl;
			break;
			default:
				cout<<"Exit"<<endl;
				break;
		}
		label_continue:
		
		cout<<"Countinue?(y/n) : ";
		cin>> is_continue;
		if(is_continue == 'y' | (is_continue == 'Y')){
			userOption = getOption();
		} else if(is_continue == 'n' | (is_continue == 'N')){
			break;
		} else{
			goto label_continue;
		}
		
	}
	
	cout<<"Done."<<endl;
	
	cin.get();
	return 0;
	
}

void getData(ifstream& inFile, Passengers list[], int listSize)
{
    for (int i = 0; i < listSize; i++)
        inFile >> list[i].age >> list[i].name >> list[i].country >> list[i].phone;
        
}

int getOption(){
	
	int input;
	//system("cls"); //to clear the screen
	
	cout<<"\nWelcome passengers arriving in Malaysia."<<endl;
	cout<<"========================================="<<endl;
	cout<<"1. Register"<<endl;
	cout<<"2. Display"<<endl;
	cout<<"3. Edit"<<endl;
	cout<<"4. Delete"<<endl;
	cout<<"5. Search"<<endl;
	cout<<"6. Exit"<<endl;
	cout<<"=========================================="<<endl;
	cout<<"Choose 1-6? : ";
	
	cin>>input;
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); //for make new line on cin
	return input;
}

void saveData(ofstream& outF, Passengers list[], int length)
{
	outF.open("output.txt");
	
	for(int i = 0; i < length; i++)
	outF<<list[i].age
             << " " << list[i].name
             << " " << list[i].country
             << " " << list[i].phone<< endl;
}

void addDataPassengers(ifstream &inFile){
	
	Passengers inputPassengers;
	cout<<"Age: ";
	getline(cin,inputPassengers.age);
	cout<<"Full Name: ";
	getline(cin,inputPassengers.name);
	cout<<"Country: ";
	getline(cin,inputPassengers.country);
	cout<<"Phone Number: ";
	getline(cin,inputPassengers.phone);
}

void printData(Passengers list[], int length)
{
	cout << left << setw(10) << "Age"
         << setw(14) << "Name"
         << setw(12) << "Country"
         << setw(10) << "Phone Number"<< endl;
         
         for (int i = 0; i < length; i++)
        cout << left << setw(10) << list[i].age
             << setw(14) << list[i].name
             << right << setw(10) << list[i].country
             << setw(10) << list[i].phone << endl;
     cout << endl << endl;
}
