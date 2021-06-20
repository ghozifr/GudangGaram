#include <stdio.h> 
#include <string.h> 
#include <conio.h> 
 
int main() 
{ 
    char username[15]; 
    char password[12]; 
    int a;
    
	while (a!=1)
	{
	fflush(stdin);
    printf("Username: "); 
    scanf("%s",&username); 
	
    printf("Password: "); 
    scanf("%s",&password); 
 
    if(strcmp(username,"Balqis")==0)
    {
        if(strcmp(password,"Hello123")==0)
        {
            printf("\nLogin Successfully");
            a=1;
        }
         else
        {
            printf("\nInvalid User!\n\n");
            
        } 
    }
    else if(strcmp(username,"Aqiff")==0)
    {
        if(strcmp(password,"Welcome")==0)
        {
            printf("\nLogin Successfully");
            a=1;
        }
        else
        {
            printf("\nInvalid User!\n\n");
            
        } 
    }
    else if(strcmp(username,"Adni")==0)
    {
        if(strcmp(password,"$frt#a25")==0)
        {
            printf("\nLogin Successfully");
            a=1;
        }
         else
        {
            printf("\nInvalid User!\n\n");
            
        } 
    }
    else
        {
            printf("\nInvalid User!\n\n");
            
        } 
	}
return 0; 
 
}
