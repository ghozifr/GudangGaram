#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Passengers{
	int num;
	string age;
	string name;
	string country;
	string phone;	
};



int getOption();
void checkDatabase(fstream &inFile);

void writeData(fstream &inFile, int location, Passengers &inputPassengers){
	inFile.seekp((location - 1)*sizeof(inputPassengers), ios::beg); //find data
	inFile.write(reinterpret_cast<char*>(&inputPassengers),sizeof(Passengers));
}




int getDataSize(fstream &inFile){
	int start, end;
	inFile.seekg(0,ios::beg);
	start = inFile.tellg();
	inFile.seekg(0,ios::end);
	end = inFile.tellg();
	return (end-start)/sizeof(Passengers); //calculate the data
	}



Passengers readData(fstream &inFile, int location){
	Passengers readPassengers;
	inFile.seekg((location - 1)*sizeof(Passengers),ios::beg);
	inFile.read(reinterpret_cast<char*>(&readPassengers),sizeof(Passengers));
	return readPassengers;
}



void addDataPassengers(fstream &inFile){
	
	Passengers inputPassengers, lastPassengers;
	
	int size = getDataSize(inFile);
	
	cout<<"size of data: "<<size<<endl;
	
	if(size == 0){
		inputPassengers.num = 1;
	} else {
		lastPassengers = readData(inFile,size);
		cout<<"num= "<<lastPassengers.num<<endl;
		inputPassengers.num = lastPassengers.num + 1;
	}
	
	
	cout<<"Age: ";
	getline(cin,inputPassengers.age);
	cout<<"Full Name: ";
	getline(cin,inputPassengers.name);
	cout<<"Country: ";
	getline(cin,inputPassengers.country);
	cout<<"Phone Number: ";
	getline(cin,inputPassengers.phone);
	
	writeData(inFile,size+1,inputPassengers);
	
}


void displayDataPassengers(fstream &inFile){
	int size = getDataSize(inFile);
	Passengers showPassengers;
	cout << "no.\tnum.\tage.\tname.\tcountry.\tphone." << endl;
	for(int i = 1; i <= size; i++){
		showPassengers = readData(inFile,i);
		cout << i << "\t";
		cout << showPassengers.num << "\t";
		cout << showPassengers.age << "\t";
		cout << showPassengers.name << "\t";
		cout << showPassengers.country << "\t";
		cout << showPassengers.phone << endl;
	}
}



int main(){
	
	fstream inFile;
	
	checkDatabase(inFile);
	
	
	int userOption = getOption();
	char is_continue;
	
	while(userOption != 6){
		
		switch(userOption){
			case 1:
			cout<<"Register"<<endl;
			addDataPassengers(inFile);
			break;
			case 2:
			cout<<"Display"<<endl;
			displayDataPassengers(inFile);
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
	system("cls"); //to clear the screen
	
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

void checkDatabase(fstream &inFile){
	inFile.open("data.txt", ios::out | ios::in | ios::binary);
	//find the file
	
	//check file 
	if (inFile.is_open()){
	cout<<"database exist."<<endl;
	} else {
		cout<<"database not found, new database created."<<endl;
		inFile.close();
		inFile.open("data.txt", ios::trunc | ios::out | ios::in | ios::binary);
		//ios::trunc create new file
	}
}
