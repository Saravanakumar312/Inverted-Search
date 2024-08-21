#include "inverted_search.h"

// Ensure fname is declared as a global variable
extern char *fname;
int insert_at_last(Wlist **head, data_t *data)
{
 //create new node

    Wlist *new = malloc(sizeof(Wlist));
    if(new == NULL)
    {
	return FAILURE;
    }
    //update the fields
    new->file_count = 1;
    strcpy(new->word,data);
    new->Tlink = NULL;
    new->link = NULL;
    //cal fun to update link table

    update_link_table(&new);

    //check WList is empty or not

    if(*head == NULL)
    {
	*head = new;
	return SUCCESS;
    }
    //not empty
    Wlist *temp = *head;
    //traverse through the WList
    while(temp->link)
    {
	temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}

int update_link_table(Wlist **head)
{
    //create Ltable node
    Ltable *new = malloc(sizeof(Ltable));
    if(new == NULL)
    {
	return FAILURE;
    }

    //update fields
    new->word_count = 1;
    strcpy(new->file_name ,fname);
    new->table_link = NULL;

    (*head)->Tlink = new;
    return SUCCESS;

}




















