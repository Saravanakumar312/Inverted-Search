#include "inverted_search.h"

void update_database( Wlist *head[], Flist **f_head)
{
    //prompt the user
    char file_name[FNAME_SIZE];
    printf("Enter the filename for update database\n");
    scanf("%s", file_name);
    //validate
    int i = 0,empty;
    empty = isFileEmpty(file_name);
    if(empty == FILE_NOTAVAILABLE)
    {
        printf("\033[0;31mFile : %s is not available\n\033[0m", file_name);
        printf("\033[0;31mHence we are not adding that into file linked list\n\033[0m");
    }
    else if(empty == FILE_EMPTY)
    {
        printf("\033[0;31mFile : %s is not having any contents \n\033[0m" , file_name);
        printf("\033[0;31mHence we are not adding that into file linked list\n\033[0m");
    }
    else
    {
        //add file list 
        int ret_val = to_create_list_of_files(f_head,file_name);
        if(ret_val == SUCCESS)
        {
        printf("\033[0;32mSuccefull : Inserting the file name %s into file linked list\n\033[0m" , file_name);
        }
        else if (ret_val == REPEATATION )
        {
        printf("\033[0;31mFailed : This file name is repeated. Hence we are not adding into File linked list\n\033[0m");
        }
        else
        {
        printf("\033[0;31mFailure\n\033[0m");
        }
       
    }
  
    while(*f_head)
    {
	if(!(strcmp((*f_head) -> file_name , file_name)))
	{
	    create_database(*f_head , head);
	}
	*f_head = ((*f_head)->link);
    }
}




