#include "list.h"
#include "StdTypes.h"
#include <stdio.h>

void admin(void)
{
    u16 choice = 0; // variable to store the choose from the user

    while(choice != 5)       //do all of these statements while the choice wasn't = 5
        {
    printf("\tWelcome to the admin page\n");
    printf("\n\t___________________________\n\n\n");
    printf("\t1 - Show users .\n\n");
    printf("\t2 - add user .\n\n");
    printf("\t3 - Reserve a book .\n\n");
    printf("\t4 - Make a book available .\n\n");
    printf("\t5 - Get back . \n\n");
    printf("\tPlease choose \n\n");

    scanf("%d",&choice); //read the choice that was entered

    switch(choice) //check what does the user choose and perform the choice
    {
    case 1:
         printusers();  //print the list of all the users when he choose 1
    break;//end this case
    case 2:
       add_user();       // add a user to the list  when he choose 2
    break;//end this case
    case 3:
        reservebook();  //reserve a book for a user  when he choose 3
    break;//end this case
    case 4:
        reavailable(); // make a book available  when he choose 4
    break;//end this case
    }
    }
}




