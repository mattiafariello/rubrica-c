#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
} Contact;


//Funzione aggiunta contatto
void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Rubrica piena!\n");
        return;
    }

    printf("Nome: ");
    scanf("%s", contacts[*count].name);

    printf("Telefono: ");
    scanf("%s", contacts[*count].phone);

    (*count)++;

    printf("Contatto aggiunto!\n");

}
//Funzione visualizzazione
void showContacts(Contact contacts[], int count) {
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
void searchContact(Contact contacts[], int count) {
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
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n===== RUBRICA =====\n");
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza contatti\n");
        printf("3. Cerca contatto\n");
        printf("4. Esci\n");
        printf("Scelta: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            addContact(contacts, &count);
            break;

        case 2:
            showContacts(contacts, count);
            break;
        
        case 3:
            searchContact(contacts, count);
            break;

        case 4:
            printf("Uscita...\n");
            return 0;



        default:
            printf("Scelta non valida!\n");
        }
    }
}