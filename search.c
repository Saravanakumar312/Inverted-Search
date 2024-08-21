
#include "inverted_search.h"
void search( Wlist *head, char *word)
{
 //check empty or not
    if(head == NULL)
    {
	printf("\033[0;31mList is empty , search not possible\n\033[0m");
	return ;
    }
    //traverse 

    while(head)
    {
	//compare the search word with each node word 
	if(!(strcmp(head->word , word)))
	{
	    printf("Word %s is present in %d file/s " , word , head->file_count);
	    Ltable *Thead = head->Tlink;
	    while(Thead)
	    {
		printf("In file : %s  %d time/s \n" , Thead->file_name , Thead->word_count);
		Thead = Thead->table_link;
	    }
            return ;

	}
	head= head->link;
    }
    printf("\033[0;31mSearch word not found\n\033[0m");
}


