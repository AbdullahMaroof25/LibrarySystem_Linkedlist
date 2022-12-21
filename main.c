#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define adminpassword  1234

int main()
{
    defaultlist();     //start the program with specific users and books in the list
    u16 pass; // variable to store the password entered from the user
    static u16 choice; // variable to store the choose from the user

     while(1)
    {

    printf("\n Select if you are admin or an user\n\n    1- admin\t2- user\n");
    printf("_______________________________\n");
    scanf("%d",&choice); //read the choice
    printf("\n");
    while(choice != 1 && choice != 2)  // check if the user choose another value from 1 or 2
    {
        printf("please choose 1 for admin or 2 for user");
        scanf("%d",&choice);
    }
    switch(choice)   //when he choose 1
    {
        case 1:
    printf("Enter the password please : "); // ask him to enter the admin password
    scanf("%d",&pass); //read the password entered
    printf("\n");
    while(pass != adminpassword)  //check if it wasn't right and ask him to reenter it again
    {
        printf("wrong password\n");
        scanf("%d",&pass);
    } // when he entered the right password move him to the admin page

    admin();
    break;
    case 2: //when he choose 2 move him to the user page

         usir();
    break;

    }
    }
    return 0;
}
