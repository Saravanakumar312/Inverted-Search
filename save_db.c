#include "inverted_search.h"

// Function to save the database to a file
void save_database(Wlist *head[]) {
    // Prompt for the filename
    char file_name[FNAME_SIZE];
    printf("Enter the filename: ");
    scanf("%s", file_name);
    
    // Open the file in append mode
    FILE *databasefile = fopen(file_name, "w");
    if (databasefile == NULL) {
        printf("\033[0;31mError: Unable to open the file for writing.\n\033[0m");
        return;
    }
    
    // Write the database to the file
    for (int i = 0; i < 27; i++) {
        if (head[i] != NULL) {
            write_databasefile(head[i], databasefile);
        }
    }
    
    // Close the file
    fclose(databasefile);
    printf("\033[0;32mDatabase saved successfully.\033[0m\n");
}

// Function to write the database file
void write_databasefile(Wlist *head, FILE *databasefile) {
    // Traverse the Wlist
    while (head != NULL) {
        // Write the word and its file count
        fprintf(databasefile, "#[%d] \n word is [%s]: file count is %d:file/s:", tolower(head->word[0]) % 97, head->word, head->file_count);

 
        Ltable *Thead = head->Tlink;
        while (Thead != NULL) {
            // Write each file entry
            fprintf(databasefile, " File is  %s: word count is %d", Thead->file_name, Thead->word_count);
            Thead = Thead->table_link; // Move to the next Ltable node
        }
        fprintf(databasefile, "\n");
        head = head->link; // Move to the next word in the Wlist
    }
}

