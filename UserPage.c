
#include "list.h"
#include "StdTypes.h"
#include <stdio.h>

void usir()
{
    static user *uptr = NULLPTR;  //declare a pointer from the type from the node of the user type
    u16 choice=0;  // variable to store the choose from the user
    u16 password; // variable to store the password entered from the user
    u8 name[20];  // variable to store the name entered in
    u8 i;  // variable to store the return value of the function


    printf("Enter the user name please : ");
    scanf("%s",name); //read the name and store

    uptr = finduname(name);  // save the return value that returned from the function to use it

    if(uptr == NULLPTR) //check if the name wasn't found in the list of the users
    {
        printf("No user name with this name \n");
        return;//end the function of the usir
    }

    printf("Enter the password : ");
    scanf("%d",&password); //read the the password

    if(checkpassword(uptr,password) == 0) // check if the password is right
    {
        printf("Wrong password\n");
        return;//end the function of the usir
    }

    while(choice != 4)
    {
    printf("\n\tWelcome to the user page\n");
    printf("\t______________________________\n\n");
    printf("\t1 - Show my status .\n");
    printf("\t2 - Show available books .\n");
    printf("\t3 - show borrowed books .\n");
    printf("\t4 - get back .\n");
    printf("\tplease choose\n");
    scanf("%d",&choice); //read the choice


    switch(choice) //check what does the user choose and perform the choice
    {
    case 1 :
        printuser(uptr);      // print the status of the current user when he choose 1
    break ;//end this case

    case 2:
        availablebooks();  //print the available books to borrow when he choose 2
        escapefunc(); //get out from that choice
    break;//end this case

    case 3:
        i = borrowedbooks(); //print the borrowed books when he choose 3
        escapefunc(); //get out from that choice
    break;//end this case
    }

}
}
