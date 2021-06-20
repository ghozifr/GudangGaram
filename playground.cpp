#include <iostream>
using namespace std;

void show(double*, int size);
const int SIZE = 8;

int main()
{
    double rates[SIZE] = {6.5, 7.2, 7.5, 8.3, 8.6, 9.4, 9.8, 10.0};
    cout<<endl;
    show(rates, SIZE);
    
    
    return 0;
}


void show(double* rates, int size){
    
    for (int i = 0; i < size; i++, rates++){
        cout<<*rates<< endl;
    }
}

