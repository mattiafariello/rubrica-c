#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char name[50];
    char phone[20];
} Contact;


//Funzione caricameto 



//Funzione cariamento contatti
void loadContacts(Contact* contacts, int *count, int capacity) {
    FILE* f = fopen("contacts.txt","r");

    if (f == NULL) {
        printf("Nessun file trovato, inizio vuoto.\n");
        return;
    }
    while (*count < capacity && fscanf(f, "%s %s",contacts[*count].name,contacts[*count].phone) == 2) {
        (*count)++;
    }
    fclose(f);

    printf("Contatti caricati!\n");

}

//Funzione salva contatti
void saveContacts(Contact* contacts, int count) {

    FILE* f = fopen("contacts.txt", "a");

    if (f == NULL) {
        printf("Errore apertura file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(f, "%s %s\n",
            contacts[i].name,
            contacts[i].phone);
    }

    fclose(f);

    printf("Contatti salvati!\n");
}

//Funzione aggiunta contatto (memoria dinamica)
void addContact(Contact **contacts, int *count, int *capacity) {

    //se pieno, espandi 
    if (*count >= *capacity) {
        *capacity *= 2;
        Contact*temp = realloc(*contacts, (*capacity) * sizeof(Contact));

        if (temp == NULL) {
            printf("Errore allocazione memoria!\n");
            return;
        }
        *contacts = temp; 
    }


    printf("Nome: ");
    scanf("%s", (*contacts)[*count].name);

    printf("Telefono: ");
    scanf("%s", (*contacts)[*count].phone);

    (*count)++;

    printf("Contatto aggiunto!\n");

}
//Funzione visualizzazione
void showContacts(Contact *contacts, int count) {
    if (count == 0) {
        printf("Nessun contatto.\n");
        return;

    }
    for (int i = 0; i < count; i++) {
        printf("\nContatto %d\n", i);
        printf("\n Nome: %s", contacts[i].name);
        printf("\n Telefono:%s", contacts[i].phone);
    }
}


// Funzione ricerca
void searchContact(Contact *contacts, int count) {
    char searchName[50];
    int found = 0;

    printf("Inserisci nome da cercare:");
    scanf("%s", searchName);

    for (int i = 0; i < count;i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("\nContatto trovato!");
            printf("\nNome: %s\n", contacts[i].name);
            printf("Telefono: %s\n", contacts[i].phone);
            found = 1;
            break;

        }



    }
    if (found == 0) {
        printf("\nContatto non trovato!");
    }
    
}


int main() {
    int capacity = 2;
    Contact *contacts = malloc(capacity * sizeof(Contact));
    int count = 0;
    int choice; 

    while (1) {
        printf("\n===== RUBRICA =====\n");
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza contatti\n");
        printf("3. Cerca contatto\n");
        printf("4. Esci\n");
        printf("5. Salva su file\n");
        printf("6. Carica da file\n");
        printf("Scelta: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            addContact(&contacts, &count, &capacity);
            break;

        case 2:
            showContacts(contacts, count);
            break;
        
        case 3:
            searchContact(contacts, count);
            break;

        case 4:
            free(contacts);
            printf("Uscita...\n");
            return 0;
        case 5:
            saveContacts(contacts, count);
            break;
        case 6: 
            loadContacts(contacts, &count, capacity);
            break;



        default:
            printf("Scelta non valida!\n");
        }
    }
}