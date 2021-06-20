#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int main(){
	
	ifstream file("myfile.txt");
string line;
if (file.is_open()) {
    fstream cin("myfile.txt");  // swap
    
    
    cout<<"masuk: ";
    cin >> line;
}
std::cout << line;

return 0;
}
