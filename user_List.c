#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "StdTypes.h"

user *headu = NULLPTR; // Pointer to the head of the list
user *tailu = NULLPTR; // Pointer to the end of the list

void add_user(void)
{
    user * ptr ; // pointer from the type of the node user
    u8 name[50]; // declare an array to store the name in
    ptr = (user *) malloc((sizeof(user))); // create a new memory equals to usser node in the run time of the program

    if(ptr == NULLPTR)  // if there is no memory to create a new node of the user in the list
    {
        printf("No space in the list \n");
        return ; //end the whole function
    }
    else   // if there is space in the memory
    {

    printf("Add the user name please : "); //ask the the admin to enter the name
    scanf("%s",name);  // store it in an array

    while(checkuname(name)== 0) // check if the user name is found before    --->"Like the Video"<-------
    {
        printf("This user name is already taken please choose another one \n"); // ask him to enter a new name
        printf("Add the user name please : ");
        scanf("%s",name);
    }

    strcpy(ptr->uname,name); // store the name of the user in the node

    printf("Add the password please : "); // ask for the password to store
    scanf("%d",&ptr->upassword);//store the password in the user node

    printf("Add the ID please : ");  // ask for the user id
    scanf("%d",&ptr->uid); //store the user id  in the user node

    if(headu==NULLPTR)  // checking if the list is still empty
    {                       // while it's empty
        ptr->unext = NULLPTR;  //make the new node to point to Null
        headu = ptr;        //assign the head of the list to the new pointer
        tailu = ptr; //assign the tail of the list to the new pointer
    }
    else
    {
        ptr->unext = NULLPTR ; //make the new node to point to Null
        tailu->unext = ptr;  //make the last node to point to the null
        tailu = ptr;   //assign the tail of the list to the new pointer
    }
    }

    escapefunc();  // to get out from the function
    printf("\n\n");
}

u8 checkuname(u8 *name)
{

    user *ptr = headu; // pointer from the type of the node user to the first node in the list

    if (ptr == NULLPTR) // checking if the list is still empty
    {                   // while it's empty
        return 1; //return 1
    }

    while(ptr != NULLPTR) //while the list is't empty or didn't end
    {
        if(strcmp((ptr->uname),name) == 0) //check if the name was found in the list of users
        {
            return 0 ; // return 0

        }

         ptr = ptr->unext;  // move the pointer to the next user in the list
    }
    return 1; // return 1
}

void printusers(void)
{
    user *ptr = headu ; // pointer from the type of the node user to the first node in the list

    printf("\n\tuser name   | password  | id \n");
    printf("\t___________________________________________\n");

    if(ptr == NULLPTR) // check if the list is empty
    {
        printf("there is no users please insert some to show \n\n\n");
        return ; //end the function
    }

    while( ptr != NULL) //while the list is't empty or didn't end
    {
        printf("%s   \t| %d   \t| %d\n" , ptr->uname , ptr->upassword , ptr->uid); // print the user name , password and id
        ptr=ptr->unext; // move the pointer to the next node
    }
    escapefunc(); // to get out
    printf("\n\n");
}

user * finduname(u8 *name)
{

    user *ptr = headu; // pointer from the type of the node user to the first node in the list

    if (ptr == NULLPTR) // check if the list is empty
    {
        return NULLPTR ; // return null if the list is empty
    }

    while(ptr != NULLPTR) //while the list is't empty or didn't end
    {
        if(strcmp((ptr->uname),name) == 0) //check if the name was found in the list of users
        {
            return ptr ; //return a pointer to the node where the name was found in the list

        }

         ptr = ptr->unext; // move the pointer to the next node
    }
    return NULLPTR; // return null if the name wasn't fond
}

u8 checkpassword(user *ptr,u16 password)
{
    if(ptr == NULLPTR) // check if the sent pointer was null "the password wasn't found"
        return 0 ;  //return 0

    //while(ptr != NULLPTR)
    //{
        if(ptr->upassword == password) // check if the user's password equals to the entered password
        {
            return 1; //return 1 if it was right
        }
      //  ptr = ptr->unext; //move the pointer to the next node in the list
    //}
    return 0 ; //return 0 if it was wrong
}

void printuser(user *ptr)
{

    printf("\nUser's data : \n");
    printf("______________________________\n");
    printf("\nUser name : %s\n",ptr->uname); // print the user name
    printf("Password : %d\n",ptr->upassword); // print the user password
    printf("ID : %d\n",ptr->uid); //print the user id
    escapefunc();
}

void Default_users(u8 name[50],u16 pass,u16 id)
{
    user * ptr ; // pointer from the type of the node user
    ptr = (user *) malloc((sizeof(user))); // create a new memory equals to usser node in the run time of the program

    strcpy(ptr->uname,name);  // store the name of the user in the node
    ptr->upassword = pass;   // store the password of the user in the node
    ptr->uid = id;          // store the id of the user in the node

     if(headu==NULLPTR)  // checking if the list is still empty
    { // while it's empty
        ptr->unext = NULLPTR; //make the new node to point to Null
        headu = ptr;  //assign the head of the list to the new pointer
        tailu = ptr;  //assign the tail of the list to the new pointer
    }
    else  // while there other nodes
    {
        ptr->unext = NULLPTR ; //make the new node to point to Null
        tailu->unext = ptr; //make the last node to point to the null
        tailu = ptr; //assign the tail of the list to the new pointer
    }
}

void escapefunc(void)
{
    u8 key='0'; //initialize a variable to read the key from the user
    printf("Enter any key to get back \n");
    fflush(stdin);  //to handle to scanf fun
    scanf("%c",&key); // to read the key entered by the user
}
