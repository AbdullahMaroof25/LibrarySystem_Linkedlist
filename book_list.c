#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "StdTypes.h"

book *headb = NULLPTR;   // Pointer to the head of the list
book *tailb = NULLPTR;   // Pointer to the end of the list

void add_book(u8 name1[20],u8 name2[20],u8 status[15],u16 id)
{
    book * ptr ;             // pointer from the type of the node book
    ptr = (book *) malloc((sizeof(book))); // create a new memory equals to book node in the run time of the program
    strcpy(ptr->bname,name1);  // store the book name
    strcpy(ptr->baname,name2); // store the author name
    strcpy(ptr->bstatus,status); // store the status of the book
    ptr->bid = id;                // store the id of the book

     if( headb == NULLPTR )      // checking if the list is still empty
    {                            // while it's empty
        ptr->bnext = NULLPTR;   //make the new node to point to Null
        headb = ptr;            //assign the head of the list to the new pointer
        tailb = ptr;           //assign the tail of the list to the new pointer
    }
    else                      //while the list isn't empty
    {
        ptr->bnext = NULLPTR ;  //make the new node to point to Null
        tailb->bnext = ptr;     //make the last node to point to the null
        tailb = ptr;           //assign the tail of the list to the new pointer
    }

}

void printlistofbook(void)
{

    book *ptr = headb ;   //initialize a pointer from the type book to the head of the list
    printf("\tname | id \n");
    printf("\t____________________\n\n");

      while(ptr != NULLPTR) //while there is still nodes in the list
    { //do these statements while the condition is true
        printf("%s   \t | %d\n" , ptr->bname , ptr->bid);  // print the name and the id of the book
        ptr=ptr->bnext;  // move the the pointer to the next node
    }

    printf("\n");

}

void availablebooks(void)
{
    book *ptr = headb ;  //initialize a pointer from the type book to the head of the list
    printf("\n\tThe list of available books to borrow\n"); //print this statement
    printf("\n\tname | id \n");
    printf("\t____________________\n\n");
    while(ptr!=NULLPTR) //while there is still nodes in the list
    {//do these statements while the condition is true
            if(strcmp(ptr->bstatus,"available")==0)  // check if the status of the book is available
    {

        printf("\t%s   \t | %d\n",ptr->bname , ptr->bid);  //print the name and id of the book
    }
     ptr=ptr->bnext; //move the the pointer to the next node
    }

    printf("\n");  //print to new line
}


u8 borrowedbooks(void)
{
    u8 flag = 0 ;
    book *ptr = headb ;  //initialize a pointer from the type book to the head of the list
    printf("\tThe list of borrowed books\n");  //print this statement
    printf("\n name | id | with user \n");    //print this statement
    printf("____________________\n\n");
    while(ptr != NULLPTR)//while there is still nodes in the list
    {//do these statements while the condition is true
            if(strcmp(ptr->bstatus,"not available") == 0) // check if the status of the book is not available
    { //while the condition is true

        printf("%s   \t | %d |\t%d\n" , ptr->bname , ptr->bid,ptr->buid); // print the book , id and the user id  who borrowed this book
        flag = 1; //return 1 if there's borrowed books
    }
     ptr=ptr->bnext; //move the pointer to the next node in the book list
    }

    printf("\n");
    printf("No borrowed books yet\n"); // print this statement when no borrowed books

    return flag;////return 1 if there's not borrowed books
}


u8 read_idbook(u16 id)
{
    u8 pos = 0; // initialize a variable to store the position of the node in the list
    book *ptr = headb ;  //initialize a pointer from the type book to the head of the list
    while(ptr != NULLPTR) //while there is still nodes in the list
    {//do these statements while the condition is true

        if(id == ptr->bid ) // check if the delivered id is equals to any id of the books
        {
            return pos;    //return the position of the book in the list that equals to
        }

        ptr = ptr->bnext;  //move the pointer to the next book in the list
        pos++; //increase the value of the variable
    }
       return -1;  //return (-1) if the delivered id wasn't found in the list
}

void reservebook(void)
{
    u8 i=0; //initialize a variable to loop
    u8 index=0; // initialize a variable to store the position of the book in the list in
    u16 id=0;   //declare a variable to store the reading id from the user
    u16 uid;   //declare a variable to store the reading user id from the user
    book *bptr = headb; //initialize a pointer from the type book to the head of the list

    availablebooks(); // print the available books to reserve from it
    printf("choose the id of the book you want to reserve : ");
    scanf("%d",&id); // read the id of the book from the user
    index = read_idbook(id);  //store the position of the book in the list in index
    while(index == -1) // check if the if the id wasn't found and make the user enter it again
    {
        printf("choose the correct id of the book you want to reserve : ");
        scanf("%d",&id);
        index = read_idbook(id);
    }

    while(bptr != NULLPTR)  //while there is still nodes in the list
    { //do these statements while the condition is true
        if(i == index) //when we get the position node in the list
        {
          printf("choose the student id you want : ");
          scanf("%d",&uid); //read the user id who we want to reserve this book for
          bptr->buid = uid ; //store the user id in the book
          strcpy(bptr->bstatus,"not available"); // change the status of the book after we reserve it
        }
        i++; //increase the value of iterator till we reach the index
        bptr = bptr->bnext; // move the pointer to the next node
    }
    escapefunc(); // to get out from the function
}

void reavailable(void)
{
    u8 i=0; //initialize a variable to loop
    u8 index=0; // initialize a variable to store the position of the book in the list in
    u16 id=0;  //declare a variable to store the reading book id from the user
    book *bptr = headb; //initialize a pointer from the type book to the head of the list

    if(borrowedbooks()==0) // check if there is no borrowed books yet
    {
        escapefunc(); // to get out from the function
        return; // end the whole function
    }
    printf("choose the id of the book you want to reserve : ");
    scanf("%d",&id); // read the id of the book from the user
    index = read_idbook(id); //store the position of the book in the list in index
    while(index == -1) // check if the if the id wasn't found and make the user enter it again
    {
        printf("choose the correct id of the book you want to reserve : ");
        scanf("%d",&id);
        index = read_idbook(id);
    }

    while(bptr != NULLPTR)  //while there is still nodes in the list
    {//do these statements while the condition is true
        if(i == index) //when we get the position node in the list
        {
          strcpy(bptr->bstatus,"available"); // change the status of the book to be available
        }
        i++; //increase the value of iterator till we reach the index
        bptr = bptr->bnext; // move the pointer to the next node
    }
    escapefunc(); // to get out from the function
}
