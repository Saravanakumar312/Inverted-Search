#include "inverted_search.h"

int main(int argc, char *argv[]) {
  system("clear");
  int option;
  char word[WORD_SIZE];
  Wlist *head[27] = {NULL};

  // validate CLA
  if (argc <= 1) {
    printf("Enter the valid no. arg\n");
    printf("./Slist.exe file1.txt  file2.txt........\n");
    return 0;
  }
  // create list of files
  // declare head pointer
  Flist *f_head = NULL;

  // validate the filenames (CLA)

  file_validation_n_file_list(&f_head, argv);
  if (f_head == NULL) {
    printf("No files are added to file list\n");
    printf("Hence the process terminated\n");
    return 0;
  }
  printf(
      "Select your choice among following options:\n1. Create DATABASE\n2. "
      "Display DATABASE\n3. Update DATABASE\n4. Search\n5. Save "
      "DATABASE\n6.Exit\n");
  while (1) {
    printf("Enter your choice ");
    /*ask user options*/
    scanf("%d", &option);
    switch (option) {
      case 1:
        // create database
        create_database(f_head, head);
        break;
      case 2:
        // display database
        display_database(head);
        break;
      case 3:
        // update database
        update_database(head, &f_head);
        break;
      case 4:
        // search
        printf("Enter the word for search\n");
        scanf("%s", word);
        search(head[tolower(word[0]) % 97], word);
        break;
      case 5:
        // save database
        save_database(head);
        break;
      case 6:
        return SUCCESS;
      default:
        printf("Enter proper choice !!\n");
        break;
    }
  }
  return 0;
}

