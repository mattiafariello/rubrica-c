#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
        printf("3. Esci\n");
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
            printf("Uscita...\n");
            return 0;

        default:
            printf("Scelta non valida!\n");
        }
    }
}