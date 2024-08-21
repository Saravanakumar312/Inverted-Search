#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[]) {
  int i = 1, empty;
  while (argv[i] != NULL) {
    empty = isFileEmpty(argv[i]);
    if (empty == FILE_NOTAVAILABLE) {
      printf("\033File : %s is not available\033[0m\n", argv[i]);
      printf("\033Hence we are not adding that into file linked list\033[0m\n");
      i++;
      continue;
    } else if (empty == FILE_EMPTY) {
      printf("\033File : %s is not having any contents\033[0m\n", argv[i]);
      printf("\033Hence we are not adding that into file linked list\033[0m\n");
      i++;
      continue;
    } else {
      // add file list
      int ret_val = to_create_list_of_files(f_head, argv[i]);
      if (ret_val == SUCCESS) {
        printf("\033[0;32mSuccess: Inserting the file name %s into file linked list\033[0m\n", argv[i]);
      } else if (ret_val == REPEATATION) {
        printf("\033[0;31mFailed : This file name %s is repeated. Hence we are not adding into File linked list\033[0m\n", argv[i]);
      } else {
        printf("\033Failure\033[0m\n");
      }
      i++;
      continue;
    }
  }
}

int isFileEmpty(char *filename) {
  FILE *fptr = fopen(filename, "r");

  if (fptr == NULL) {
    if (errno == ENOENT) {
      return FILE_NOTAVAILABLE;
    }
  }

  fseek(fptr, 0, SEEK_END);
  if (ftell(fptr) == 0) {
    return FILE_EMPTY;
  }
}

// fun() to create file linked list
int to_create_list_of_files(Flist **f_head, char *name) {
  // Allocate memory for a new node
  Flist *newNode = malloc(sizeof(Flist));
  if (newNode == NULL) {
    return FAILURE;  // Return failure if memory allocation fails
  }

  // Copy the file name to the new node
  strcpy(newNode->file_name, name);
  newNode->link = NULL;

  // If the list is empty, update the head pointer
  if (*f_head == NULL) {
    *f_head = newNode;
    return SUCCESS;
  }
  Flist *temp = *f_head;  // Initialize temp to the head of the list
  // check for duplicancy  ---- > if found ignore
  while (temp != NULL) {
    if (strcmp(temp->file_name, name) == 0) {
      free(newNode);
      return REPEATATION;
    }
    temp = temp->link;
  }
  if (temp == NULL) {
    // Update the last node's link to point to the new node
    Flist *last = *f_head;
    while (last->link != NULL) {
      last = last->link;
    }
    last->link = newNode;
    return SUCCESS;
  }
}

