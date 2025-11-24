#ifndef PERIODIC_TABLE_H
#define PERIODIC_TABLE_H

#define NUM_ELEMENTS 118

typedef struct {
    int atomic_number;
    char name[25];
    char symbol[5];
    float atomic_mass;
    char electronic_configuration[60];
    char group[15];
    char block[5];
    char state_at_stp[15];
    char category[35];
} Element;

extern const Element periodic_table_data[NUM_ELEMENTS];

#endif // PERIODIC_TABLE_H
