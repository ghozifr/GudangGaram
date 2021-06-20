#include <iostream>
#include <iomanip>

using namespace std;

void initailize (double alpha[], int size);

void print (double alpha[], int size);

int main()
{
    
    const int AREA = 50;
    double alpha [AREA];
    initailize(alpha, AREA);
    print(alpha, AREA);
    
    return 0;
    
}

void initailize(double list[], int size){
    int count;
    for (count = 0; count<25; count++){
        list[count] = count * count;
    }
    for (count=25; count<size; count++){
        list[count] = count * 3;
    }
}


void print(double list[], int size){
    for (int count = 0; count<size; count++){
        cout<<setw(3)<<list[count]<<" ";
        if ((count +1)% 10 == 0)
        cout<<endl;
    }
    cout<<endl;
}