#include "list.h"

// add users and books in their lists at the beginning of the program
void defaultlist(void)
{
     /*** name , password , id ****/
     Default_users("abdallah",2020,1);
     Default_users("ahmed",2019,2);
     Default_users("mohamed",2021,3);
     /******* book name , author name , status , the id of the book ****/
     add_book("arabic","ahmed","available",1);
     add_book("english","ali","available",2);
     add_book("french","mohamed","available",3);
     add_book("math","kkk","available",4);
     add_book("science","seka","available",5);

}






