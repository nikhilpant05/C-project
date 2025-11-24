#include <stdio.h>
#include "../include/display.h"
#include "../include/periodic_table.h"

void print_title_screen() {
    printf("\n");
    printf("+-----------------------------------------------------+\n");
    printf("|          MODERN PERIODIC TABLE EXPLORER (C)         |\n");
    printf("+-----------------------------------------------------+\n");
    printf("|  COMPREHENSIVE EDITION (1 to 118) - SEM 1 PROJECT   |\n");
    printf("+-----------------------------------------------------+\n");
    printf("\n");
}

void displayElement(const Element* element) {
    if (element == NULL) {
        printf("\n[ERROR] Element data is unavailable.\n");
        return;
    }

    printf("\n+-----------------------------------------------------------------------+\n");
    printf("| %-71s |\n","ELEMENT DETAILS");
    printf("+------------------------------+----------------------------------------+\n");
    printf("| %-28s | %-38d |\n","Atomic Number (Z)",element->atomic_number);
    printf("| %-28s | %-38s |\n","Name",element->name);
    printf("| %-28s | %-38s |\n","Symbol",element->symbol);
    printf("| %-28s | %-38.3f |\n","Atomic Mass (g/mol)",element->atomic_mass);
    printf("| %-28s | %-38s |\n","Group",element->group);
    printf("| %-28s | %-38s |\n","Block",element->block);
    printf("| %-28s | %-38s |\n","Category",element->category);
    printf("| %-28s | %-38s |\n","State (STP)",element->state_at_stp);
    printf("| %-28s | %-38s |\n","Electron Configuration",element->electronic_configuration);
    printf("+------------------------------+----------------------------------------+\n\n");
}

void displayAllElements() {
    printf("+---------------------------------------------------+\n");
    printf("| Available Elements (Atomic Number | Symbol | Name) |\n");
    printf("+---------------------------------------------------+\n");

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("| %3d | %-6s | %-39s |\n",
            periodic_table_data[i].atomic_number,
            periodic_table_data[i].symbol,
            periodic_table_data[i].name
        );
    }

    printf("+---------------------------------------------------+\n");
}
