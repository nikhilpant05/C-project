#include <stdio.h>
#include <stdlib.h>
#include "../include/periodic_table.h"
#include "../include/display.h"
#include "../include/search.h"

int main() {
    int choice = 0;
    int atomicNumber = 0;
    const Element* foundElement = NULL;

    print_title_screen();

    do {
        printf("--- Main Menu ---\n");
        printf("1. Search Element by Atomic Number (1-%d)\n", NUM_ELEMENTS);
        printf("2. Show list of all elements\n");
        printf("3. Exit Program\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\n[ERROR] Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }
        printf("\n");

        switch (choice) {
            case 1:
                printf("Enter Atomic Number (1-%d): ", NUM_ELEMENTS);
                if (scanf("%d", &atomicNumber) != 1) {
                    printf("\n[ERROR] Invalid number.\n");
                    while (getchar() != '\n');
                    break;
                }

                if (atomicNumber < 1 || atomicNumber > NUM_ELEMENTS) {
                    printf("Invalid range. Enter 1–%d.\n", NUM_ELEMENTS);
                    break;
                }

                foundElement = findElementDetails(atomicNumber);
                if (foundElement != NULL)
                    displayElement(foundElement);
                else
                    printf("Element not found.\n");

                break;

            case 2:
                displayAllElements();
                break;

            case 3:
                printf("Exiting... Thank you.\n");
                return 0;

            default:
                printf("[ERROR] Invalid choice. Please select 1-3.\n");
                break;
        }

        printf("\nPress ENTER to return to menu...");
        while (getchar() != '\n');
        getchar();

    } while (1);

    return 0;
}
