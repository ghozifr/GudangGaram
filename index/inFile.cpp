#include <iostream>
#include <fstream>
#include <cstdlib>   // needed for exit()
using namespace std;

int main(){
	
	ifstream inFile;
	inFile.open("test.dat", ios::out | ios::in | ios::binary);  // open the file with the external name test.dat
	
	if (inFile.is_open()){
		cout<<"database found."<<endl;
	} else{
		cout<<"database not found, create new database."<<endl;
		inFile.close();
		inFile.open("test.dat", ios::trunc | ios::out | ios::in | ios::binary);
	}
	
	
	
	cout<<"\nThe file has been successfully opened for reading."<<endl;
	// statements to read data from the file are placed here
	
	return 0;	
}
