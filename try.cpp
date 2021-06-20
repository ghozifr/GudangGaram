#include<iostream>
using namespace std;


const int ARRAY_SIZE = 9;

void show (double *rates)
{
	int i;

	for (i = 0; i < ARRAY_SIZE; i++)
	  cout << *(rates + i) << endl;

	return;
}

void capit(char *, char *);


int main(){
	
void show(double *);
	double rates[ARRAY_SIZE] = {6.5,7.2,7.5,8.3,8.6,9.4,9.6,9.8,10.0};

	show(rates);
	}
