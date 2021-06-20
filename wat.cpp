#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct Date{
       int month;
       int day;
       int year;
       };
       
       
long days(Date);

int main(){
  string filename = "data.dat";
  
  string line;
  
  ofstream outfile;
  
  outfile.open(filename.c_str());
  
  if(outfile.fail())
  {
      cout<<"\nFile not exist"
      <<"\nPlease create new file"<<endl;
      
      exit(1);
      
  }
  
  cout<<"Enter lines of text, enter a blank line to end"<<endl;
  
  
  getline(cin,line);
  while(line != "")
  {
      outfile<<line<<endl;
      getline(cin,line);
  }
  
  outfile.close();
  cout<<"\nEnd of data input"<<endl;
  cout<<"\nThe file has been written"<<endl;
   return 0;
}

