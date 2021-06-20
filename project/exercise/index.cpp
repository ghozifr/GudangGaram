#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
   Name: Robbani Ghozi Fikri

   Matric No: 1832765

   Section : 2

*/

const int ROW = 8;

const int COL = 6;

struct States
{
    string Name;
    string Capital;
    double GDP;
    double HDI;
    int Population;
    int Area;
};


int storeInfo(){

cout<<""<<endl;
}

void store_state_details(){
    
    cout<<""<<endl;
}

int main(){

string filename = "data.txt"; 
  string line;
  ofstream outfile;
  outfile.open(filename.c_str());

  if(outfile.fail())
  {
      cout<<"\nFile not exist"
      <<"\nPlease create new file"<<endl;
      
      exit(1);
      
  }

    return 0;
}




/* Question 1 (PS)

   Name: Robbani Ghozi Fikri

   Matric No: 1832765

   Section : 2

*/

 
/*
#include <iostream>

#include <iomanip>

#include <string>

using namespace std;

const int ROW = 4;

const int COL = 8;

 

//prototype

void enterData(double &wind_speeds[][]);

double calcAvgSpeed(double &wind_speeds[][]);

void displayData(double &wind_speeds[][]);

string week[] = {"Week 1", "Week 2", "Week 3", "Week 4"};

 

int main()

{

   double wind_speeds[ROW][COL];

   double avg, sum;

  

   //function call to enter data (0.5 mark)
enterData(wind_speeds);
  

   for (int k = 0; k < ROW; k++)

   {

        sum = 0.0;

        //function call here to calculate average (2 marks)     
calcAvgSpeed(avg);
   }

   cout << endl;

   //function call to display (0.5 mark)
   displayData(sum);

 

   return 0;

}

 

void enterData(double &wind_speeds[][]) //(0.5 mark)
{   
    int sizex = 7;
    int sizey = 1;

cout << setw(38) << "Day" << setw(5) << "1" << setw(5) << "2"

          << setw(5) << "3" << setw(5) << "4" << setw(5) << "5" << setw(5) << "6" << setw(5) << "7" << endl << endl;

for(int j = 0; j < 5; j++){ //loop through user entry (1 marks)
    cout<<"Enter daily wind speeds reported for Week "<<week[j]<<":";
    cin wind_speeds[sizey][sizex]<<endl;
         
}

}

 

void displayData(double &wind_speeds[][]) // (0.5 mark)

{
    int sizex = 7;
    int sizey = 1;

     cout << setw(6) << "Day" << setw(7) << "1" << setw(8) << "2"

          << setw(8) << "3" << setw(8) << "4" << setw(8) << "5" << setw(8) << "6" << setw(8) << "7" << setw(10) <<"Avg" << endl;   

           //loop through display data (2 marks)
           for(int i = 0; i < 5; i++)
           {
               wind_speeds[sizex];
               for(int j = 0; j < 8; j++)
               wind_speeds[sizey];
               
           }

 

}

double calcAvgSpeed(double &wind_speeds[][])  //(0.5 mark)

{

     double average, sum = 0.0;

    

           //loop through accumulate total (2 marks)
           for(int i = 0; i < 5; i++)
           {
               average = wind_speeds[][];
           }

    

     //calculate average (0.5 mark)
     sum = average++;

    

     return average;

}
*/

/*
#include <iostream>
#include <iomanip>
using namespace std;
void compute(int x, int& y, int& z)
{
    x = x + y;
    y = x % 2;
    z = 2;
}
int main(){


int one = 1;
int two = 2;
int three = 3;

compute(one, two,three);
cout<<one<<" "<<two<<" "<<three<<endl;
*/
/*
int x=56, y = 5;

switch (x % 7)
{
case 0:
case 1:
    y++;
case 2:
case 3:
y=y + 2;
case 4:
    break;
case 5:
default:
y= y - 3;
   }

   cout<<y<<endl;
*/
/*
int sum, num, j;

cin>>sum;
cin>>num;
for(j=0;j<3;j++)
{
    cin>>num;
    sum += num;
}
cout<<sum<<endl;
*/
/*
int i, j;
for (i=1; i <= 3; i++)
{
    for(j=1;j<=i;j++)
    cout<<setw(3)<<j;
    cout<<endl;
}
*/
/*
int x = 2;
int y = 5;
//int z = 7;

bool found = x < y;
if(x+y == 7 || y <= x && !found)
{
    if(found)
    {
        cout<<'L';
    }
    else{
        cout<<'S';
    }
    cout<<'F';
}
else
{
    cout<<'J';
}

*/
/*
int num1 = 18,num2 = 5;

bool found = false;

found = (num1>num2);
if (found)
switch (num1 % num2)
{
case 0:
    num2 = num1 / 2;
    break;
case 1:
    num1 = num2 / 2;
    break;
default:
num1 = num1 / num2;
num2 = num1 * num2;
}

else{
    num1 = num1 - num2;
    num2 = (num1 + num2) / 10;
}

cout<<num1<<" "<<num2<<endl;

*/
/*
int divd_price, orig_price = 1100;

divd_price = orig_price;
if(orig_price > 1000)
divd_price = orig_price + 100;

cout<< divd_price<<endl;

*/
/*
    double x = 33.80, y = 791.211, z = 2006.7475;

    cout<<fixed<<showpoint;
    cout<< setprecision(3);
    cout<<x<<" "<<y<<" "<<z<<endl;
    */
/*
    return 0;
}*/