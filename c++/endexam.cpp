#include<iostream>

using namespace std;


int main(){
	int numP, durS, total;
	
	cout<<"Enter number of people : ";
	cin>>numP;
 
	cout<<"Enter duration of stay : ";
	cin>>durS;
	
	if (numP > 0 && numP <4){
		switch(durS){
			case 2 : cout<<"Paket A"<<endl;
			cout<<"after diskon "<<0.04*1800<<endl;
			cout<<"bnyak orang "<<numP<<endl;
			cout<<"total "<<(0.04*700)*numP<<endl;
			break;
			case 4 : cout<<"Paket B"<<endl;
			cout<<"after diskon "<<0.06*1800<<endl;
			cout<<"bnyak orang "<<numP<<endl;
			cout<<"total "<<(0.06*1200)*numP<<endl;
			break;
			case 6 : cout<<"Paket C"<<endl;
			cout<<"after diskon "<<0.08*1800<<endl;
			cout<<"bnyak orang "<<numP<<endl;
			cout<<"total "<<(0.08*1800)*numP<<endl;
		default:
		;}
	}else if(numP > 3 && numP <7){
		switch(durS){
			case 2 : cout<<"Paket D"<<endl;
			cout<<"after diskon "<<0.05*650<<endl;
			cout<<"bnyak orang "<<numP<<endl;
			cout<<"total "<<(0.05*650)*numP<<endl;
			break;
			case 4 : cout<<"Paket E"<<endl;
			cout<<"after diskon "<<0.07*1100<<endl;
			cout<<"bnyak orang "<<numP<<endl;
			cout<<"total "<<(0.07*1100)*numP<<endl;
			break;
			case 6 : cout<<"Paket F"<<endl;
			cout<<"after diskon "<<0.09*1700<<endl;
			cout<<"bnyak orang "<<numP<<endl;
			cout<<"total "<<(0.09*1700)*numP<<endl;
		default:
		;}
	}else if(numP > 7 && numP < 10){
		switch(durS){
			case 2 : cout<<"Paket G"<<endl;
			cout<<"after diskon "<<0.06*600<<endl;
			cout<<"bnyak orang "<<numP<<endl;
			cout<<"total "<<(0.06*600)*numP<<endl;
			break;
			case 4 : cout<<"Paket H"<<endl;
			cout<<"after diskon "<<0.08*1000<<endl;
			cout<<"bnyak orang "<<numP<<endl;
			cout<<"total "<<(0.08*1000)*numP<<endl;
			break;
			case 6 : cout<<"Paket I"<<endl;
			cout<<"after diskon "<<0.1*1600<<endl;
			cout<<"bnyak orang "<<numP<<endl;
			cout<<"total "<<(0.1*1600)*numP<<endl;
		default: 
			cout<<"Invalid entry. Duration of stay must be at least 1 and not more than 7";
			}
	}else(numP > 9);{
		cout<<"Invalid entry. Please enter a value between 1-9 people only"<<endl;
	}
}

