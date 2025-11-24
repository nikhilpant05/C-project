#include <stdio.h>
#include "../include/search.h"
#include "../include/periodic_table.h"

const Element* findElementDetails(int atomicNum) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        if (periodic_table_data[i].atomic_number == atomicNum) {
            return &periodic_table_data[i];
        }
    }
    return NULL;
}
