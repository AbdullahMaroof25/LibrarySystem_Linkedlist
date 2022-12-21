#ifndef   list_h
#define    list_h

#include "StdTypes.h"


typedef struct mybook
{
    u8 bname[50];        //the book name
    u8 baname[50];      //the author name
    u8 bstatus[15];     //the status of the book
    u16 buid;           //the id of the user that borrow the book
    u16 bid;            //the id of the book
    struct mybook *bnext;  // a pointer from the type of the node to store the address of the next node in

}book;

typedef struct myuser
{
    u8 uname[50]; //the user name
    u16 upassword;//the password of the user
    u16 uid;   // the id of the user
    struct myuser *unext; // a pointer from the type of the node to store the address of the next node in
}user;



// default list of users and book funcs
void defaultlist(void); // the fun that run them in
void Default_users(u8 name[50],u16 pass,u16 id);
void add_book(u8 name1[20],u8 name2[20],u8 status[15],u16 id);


//the funcs related to the user

user * finduname(u8 *name);
u8 checkuname(u8 *name);
u8 checkpassword(user *ptr,u16 password);
void printuser(user *ptr);
void availablebooks(void);
u8 borrowedbooks(void);
void escapefunc(void);

//THE funcs related to the admin

void add_user(void);
void printusers(void);
void reservebook(void);
void reavailable(void);

//


void admin(void);
void usir(void);

void printlistofbook(void);


u8 read_idbook(u16 id);




#endif // list_h
