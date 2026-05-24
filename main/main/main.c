#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
} Contact;

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
            if (count < MAX_CONTACTS) {
                printf("Nome: ");
                scanf("%s", contacts[count].name);

                printf("Telefono: ");
                scanf("%s", contacts[count].phone);

                count++;

                printf("Contatto aggiunto!\n");
            }
            else {
                printf("Rubrica piena!\n");
            }
            break;

        case 2:
            if (count == 0) {
                printf("Nessun contatto.\n");
            }
            else {
                for (int i = 0; i < count; i++) {
                    printf("\nContatto %d\n", i + 1);
                    printf("Nome: %s\n", contacts[i].name);
                    printf("Telefono: %s\n", contacts[i].phone);
                }
            }
            break;
        
        case 3:
            char searchName[50]; 
            int found = 0;
            printf("Inserisci nome da cercare: ");
            scanf("%s", searchName);

            for (int i = 0; i < count; i++) {
                if (strcmp(contacts[i].name, searchName) == 0) {
                    printf("\nContatto trovato!\n");
                    printf("Nome: %s\n", contacts[i].name);
                    printf("Telefono: %s\n", contacts[i].phone);
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                printf("Contatto non trovato.\n");
            }
            break;

        case 4:
            printf("Uscita...\n");
            return 0;



        default:
            printf("Scelta non valida!\n");
        }
    }
}