#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Passengers{
	int datanum;
	string name;
	string age;
	string country;
	string phone;	
};



int getOption();
void checkDatabase(fstream &data);
void addDataPassengers(fstream &data);
int getDataSize(fstream &data);
void writeData(fstream &data, int position, Passengers &inputPassengers);
void displayDataPassengers(fstream &data);
Passengers readData(fstream &data, int position);
void updateDataPassengers(fstream &data);
void deletePassengers(fstream &data);

void searchPassengers(fstream &data){

	int pn;
	Passengers findPassengers;

	cout<<"Enter Passenger Numbers: ";
	cin>>pn;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	findPassengers = readData(data,pn);
	
	cout<<"\n\nPassengers Details: "<<endl;
	cout<<"Name: "<<findPassengers.name<<endl;
	cout<<"Age: "<<findPassengers.age<<endl;
	cout<<"Country: "<<findPassengers.country<<endl;
	cout<<"Phone: "<<findPassengers.phone<<endl;
}



int main(){
	
	fstream data;
	
	checkDatabase(data);
	
	
	int userOption = getOption();
	char is_continue;
	
	while(userOption != 6){
		
		switch(userOption){
			case 1:
			cout<<"Register"<<endl;
			addDataPassengers(data);
			break;
			case 2:
			cout<<"Display"<<endl;
			displayDataPassengers(data);
			cin.get();
			break;
			case 3:
			cout<<"Edit"<<endl;
			displayDataPassengers(data);
			updateDataPassengers(data);
			displayDataPassengers(data);
			break;
			case 4:
			cout<<"Delete"<<endl;
			displayDataPassengers(data);
			deletePassengers(data);
			displayDataPassengers(data);
			break;
			case 5:
			cout<<"Search"<<endl;
			displayDataPassengers(data);
			searchPassengers(data);
			break;
			default:
				cout<<"Exit"<<endl;
				break;
		}
		label_continue:
		
		cout<<"Continue?(y/n) : ";
		cin>> is_continue;
		if((is_continue == 'y') | (is_continue == 'Y')){
			userOption = getOption();
		} else if((is_continue == 'n') | (is_continue == 'N')){
			break;
		} else{
			goto label_continue;
		}
		
	}
	
	cout<<"Done."<<endl;
	
	cin.get();//before end
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
	cout<<"========================================="<<endl;
	cout<<"Choose 1-6? : ";
	
	cin>>input;
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); //for make new line on cin
	return input;
}


void checkDatabase(fstream &data){
	data.open("data.txt", ios::out | ios::in | ios::binary);
	//find the file
	
	//check file
	if (data.is_open()){
	cout<<"database exist."<<endl;
	} else {
		cout<<"database not found, new database created."<<endl;
		data.close();
		data.open("data.txt", ios::trunc | ios::out | ios::in | ios::binary);
		//ios::trunc create new file
	}
}


void addDataPassengers(fstream &data){
	
	Passengers inputPassengers,lastPassengers;
	
	int size = getDataSize(data);
	
	cout<<"Passenger Numbers: "<<size+1<<endl;
	
	// if(size == 0){
	// 	inputPassengers.num = 1;
	// } else {
	// 	lastPassengers = readData(data,size);
	// 	//cout<<" "<<lastPassengers.num<<endl;
	// 	inputPassengers.num = lastPassengers.num + 1;
	// }

	
	cout<<"Name: ";
	getline(cin,inputPassengers.name);
	cout<<"Age: ";
	getline(cin,inputPassengers.age);
	cout<<"Country: ";
	getline(cin,inputPassengers.country);
	cout<<"Phone Number: ";
	getline(cin,inputPassengers.phone);
	
	writeData(data,size+1,inputPassengers);
}


void writeData(fstream &data, int position, Passengers &inputPassengers){
	data.seekp((position - 1)*sizeof(Passengers), ios::beg); //find data position
	data.write(reinterpret_cast<char*>(&inputPassengers),sizeof(Passengers)); //write data
}


int getDataSize(fstream &data){
	int start, end;
	data.seekg(0,ios::beg); //start from the beginning of the line
	start = data.tellg();   //take position
	data.seekg(0,ios::end); //read position
	end = data.tellg();
	return (end-start)/sizeof(Passengers); //calculate the data
	}


Passengers readData(fstream &data, int position){
	Passengers readPassengers;
	data.seekg((position - 1)*sizeof(Passengers),ios::beg);
	data.read(reinterpret_cast<char*>(&readPassengers),sizeof(Passengers));
	return readPassengers;
} //read for show


void displayDataPassengers(fstream &data){
	int size = getDataSize(data);
	Passengers showPassengers;
	cout<<"No:\tName:\tAge:\tCountry:\tPhone:"<<endl;
	for(int i = 1; i <= size; i++){
		showPassengers = readData(data,i);
		cout<<i<<"\t";
		//cout << showPassengers.num << "\t";
		cout<<showPassengers.name<<"\t";
		cout<<showPassengers.age<<"\t";
		cout<<showPassengers.country<<"\t";
		cout<<showPassengers.phone<<endl;
	}
}


void updateDataPassengers(fstream &data){
	int pn;
	Passengers updatePassengers;
	cout<<"Choose Passenger Numbers: ";
	cin>>pn;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	updatePassengers = readData(data,pn);
	
	cout<<"\n\nChoose data: "<<endl;
	cout<<"Name: "<<updatePassengers.name<<endl;
	cout<<"Age: "<<updatePassengers.age<<endl;
	cout<<"Country: "<<updatePassengers.country<<endl;
	cout<<"Phone: "<<updatePassengers.phone<<endl;

	cout<<"\nChange data: "<<endl;
	cout<<"Name: ";
	getline(cin,updatePassengers.name);
	cout<<"Age: ";
	getline(cin,updatePassengers.age);
	cout<<"Country: ";
	getline(cin,updatePassengers.country);
	cout<<"Phone: ";
	getline(cin,updatePassengers.phone);

	writeData(data,pn,updatePassengers);
}


void deletePassengers(fstream &data){
	int pn,size,offset = 0;
	Passengers blankPassengers, tempPassengers;
	fstream temporaryData;
	size = getDataSize(data);
	// choose
	cout<<"Delete Passenger Numbers: ";
	cin>>pn;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	// replace with empty data
	writeData(data,pn,blankPassengers);
	// check data drom file data.txt
	temporaryData.open("blank.txt", ios::trunc | ios::out | ios::in | ios::binary);
	
	for(int i = 1; i <= size; i++){
		tempPassengers = readData(data,i);

		if(!tempPassengers.name.empty()){ //empty string
			writeData(temporaryData,i - offset,tempPassengers); //calculate existing data
		} else {
			offset++;
			cout<<"deleted data"<<endl;
		}
	}
	// place empty data to data txt
	size = getDataSize(temporaryData);
	data.close();
	data.open("data.txt", ios::trunc | ios::out | ios::in | ios::binary);
	data.close(); //delete
	data.open("data.txt", ios::trunc | ios::out | ios::in | ios::binary);

	for(int i = 1; i <= size; i++){
		tempPassengers = readData(temporaryData,i);
		writeData(data,i,tempPassengers);
	}
}
