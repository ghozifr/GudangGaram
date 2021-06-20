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
int mainPage();
void dataBase();


int main(){

	mainPage();

}



void dataBase(ofstream &outfile){
	
	Passengers input[30];
	
	outfile.open("data.txt");
	
	cout<<"Age: ";
	cin.getline(input.age,30);
	outfile<<input.age<<endl;
	cout<<"Name: ";
	getline(cin,input.name,30);
	outfile<<input.name<<endl;
	cout<<"Country: ";
	getline(cin,input.name,30);
	outfile<<input.country<<endl;
	cout<<"Phone: ";
	getline(cin,input.name,30);
	outfile<<input.phone<<endl;
	
	outfile.close();
}

int mainPage(){
	
	ifstream infile;
	ofstream outfile;
	int userOption = getOption();
	char is_continue;
	
	while(userOption != 6){
		
		switch(userOption){
			case 1:
			cout<<"Register"<<endl;
			dataBase(outfile);
			break;
			case 2:
			cout<<"Display"<<endl;
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









