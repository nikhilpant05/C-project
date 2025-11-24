#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

#define NUM_ELEMENTS 118

const Element periodic_table_data[NUM_ELEMENTS] = {
    {1,"Hydrogen","H",1.008,"1s1","1 (IA)","s","Gas","Nonmetal"},
    {2,"Helium","He",4.003,"1s2","18 (VIIIA)","s","Gas","Noble Gas"},
    {3,"Lithium","Li",6.940,"[He] 2s1","1 (IA)","s","Solid","Alkali Metal"},
    {4,"Beryllium","Be",9.012,"[He] 2s2","2 (IIA)","s","Solid","Alkaline Earth Metal"},
    {5,"Boron","B",10.810,"[He] 2s2 2p1","13 (IIIA)","p","Solid","Metalloid"},
    {6,"Carbon","C",12.011,"[He] 2s2 2p2","14 (IVA)","p","Solid","Nonmetal"},
    {7,"Nitrogen","N",14.007,"[He] 2s2 2p3","15 (VA)","p","Gas","Nonmetal"},
    {8,"Oxygen","O",15.999,"[He] 2s2 2p4","16 (VIA)","p","Gas","Nonmetal"},
    {9,"Fluorine","F",18.998,"[He] 2s2 2p5","17 (VIIA)","p","Gas","Halogen"},
    {10,"Neon","Ne",20.180,"[He] 2s2 2p6","18 (VIIIA)","p","Gas","Noble Gas"},
    {11,"Sodium","Na",22.990,"[Ne] 3s1","1 (IA)","s","Solid","Alkali Metal"},
    {12,"Magnesium","Mg",24.305,"[Ne] 3s2","2 (IIA)","s","Solid","Alkaline Earth Metal"},
    {13,"Aluminum","Al",26.982,"[Ne] 3s2 3p1","13 (IIIA)","p","Solid","Post-transition Metal"},
    {14,"Silicon","Si",28.085,"[Ne] 3s2 3p2","14 (IVA)","p","Solid","Metalloid"},
    {15,"Phosphorus","P",30.974,"[Ne] 3s2 3p3","15 (VA)","p","Solid","Nonmetal"},
    {16,"Sulfur","S",32.060,"[Ne] 3s2 3p4","16 (VIA)","p","Solid","Nonmetal"},
    {17,"Chlorine","Cl",35.450,"[Ne] 3s2 3p5","17 (VIIA)","p","Gas","Halogen"},
    {18,"Argon","Ar",39.948,"[Ne] 3s2 3p6","18 (VIIIA)","p","Gas","Noble Gas"},
    {19,"Potassium","K",39.098,"[Ar] 4s1","1 (IA)","s","Solid","Alkali Metal"},
    {20,"Calcium","Ca",40.078,"[Ar] 4s2","2 (IIA)","s","Solid","Alkaline Earth Metal"},
    {21,"Scandium","Sc",44.956,"[Ar] 3d1 4s2","3 (IIIB)","d","Solid","Transition Metal"},
    {22,"Titanium","Ti",47.867,"[Ar] 3d2 4s2","4 (IVB)","d","Solid","Transition Metal"},
    {23,"Vanadium","V",50.942,"[Ar] 3d3 4s2","5 (VB)","d","Solid","Transition Metal"},
    {24,"Chromium","Cr",51.996,"[Ar] 3d5 4s1","6 (VIB)","d","Solid","Transition Metal"},
    {25,"Manganese","Mn",54.938,"[Ar] 3d5 4s2","7 (VIIB)","d","Solid","Transition Metal"},
    {26,"Iron","Fe",55.845,"[Ar] 3d6 4s2","8 (VIIIB)","d","Solid","Transition Metal"},
    {27,"Cobalt","Co",58.933,"[Ar] 3d7 4s2","9 (VIIIB)","d","Solid","Transition Metal"},
    {28,"Nickel","Ni",58.693,"[Ar] 3d8 4s2","10 (VIIIB)","d","Solid","Transition Metal"},
    {29,"Copper","Cu",63.546,"[Ar] 3d10 4s1","11 (IB)","d","Solid","Transition Metal"},
    {30,"Zinc","Zn",65.380,"[Ar] 3d10 4s2","12 (IIB)","d","Solid","Transition Metal"},
    {31,"Gallium","Ga",69.723,"[Ar] 3d10 4s2 4p1","13 (IIIA)","p","Solid","Post-transition Metal"},
    {32,"Germanium","Ge",72.630,"[Ar] 3d10 4s2 4p2","14 (IVA)","p","Solid","Metalloid"},
    {33,"Arsenic","As",74.922,"[Ar] 3d10 4s2 4p3","15 (VA)","p","Solid","Metalloid"},
    {34,"Selenium","Se",78.971,"[Ar] 3d10 4s2 4p4","16 (VIA)","p","Solid","Nonmetal"},
    {35,"Bromine","Br",79.904,"[Ar] 3d10 4s2 4p5","17 (VIIA)","p","Liquid","Halogen"},
    {36,"Krypton","Kr",83.798,"[Ar] 3d10 4s2 4p6","18 (VIIIA)","p","Gas","Noble Gas"},
    {37,"Rubidium","Rb",85.468,"[Kr] 5s1","1 (IA)","s","Solid","Alkali Metal"},
    {38,"Strontium","Sr",87.620,"[Kr] 5s2","2 (IIA)","s","Solid","Alkaline Earth Metal"},
    {39,"Yttrium","Y",88.906,"[Kr] 4d1 5s2","3 (IIIB)","d","Solid","Transition Metal"},
    {40,"Zirconium","Zr",91.224,"[Kr] 4d2 5s2","4 (IVB)","d","Solid","Transition Metal"},
    {41,"Niobium","Nb",92.906,"[Kr] 4d4 5s1","5 (VB)","d","Solid","Transition Metal"},
    {42,"Molybdenum","Mo",95.960,"[Kr] 4d5 5s1","6 (VIB)","d","Solid","Transition Metal"},
    {43,"Technetium","Tc",98.000,"[Kr] 4d5 5s2","7 (VIIB)","d","Solid","Transition Metal"},
    {44,"Ruthenium","Ru",101.070,"[Kr] 4d7 5s1","8 (VIIIB)","d","Solid","Transition Metal"},
    {45,"Rhodium","Rh",102.906,"[Kr] 4d8 5s1","9 (VIIIB)","d","Solid","Transition Metal"},
    {46,"Palladium","Pd",106.420,"[Kr] 4d10","10 (VIIIB)","d","Solid","Transition Metal"},
    {47,"Silver","Ag",107.868,"[Kr] 4d10 5s1","11 (IB)","d","Solid","Transition Metal"},
    {48,"Cadmium","Cd",112.411,"[Kr] 4d10 5s2","12 (IIB)","d","Solid","Transition Metal"},
    {49,"Indium","In",114.818,"[Kr] 4d10 5s2 5p1","13 (IIIA)","p","Solid","Post-transition Metal"},
    {50,"Tin","Sn",118.710,"[Kr] 4d10 5s2 5p2","14 (IVA)","p","Solid","Post-transition Metal"},
    {51,"Antimony","Sb",121.760,"[Kr] 4d10 5s2 5p3","15 (VA)","p","Solid","Metalloid"},
    {52,"Tellurium","Te",127.600,"[Kr] 4d10 5s2 5p4","16 (VIA)","p","Solid","Metalloid"},
    {53,"Iodine","I",126.904,"[Kr] 4d10 5s2 5p5","17 (VIIA)","p","Solid","Halogen"},
    {54,"Xenon","Xe",131.293,"[Kr] 4d10 5s2 5p6","18 (VIIIA)","p","Gas","Noble Gas"},
    {55,"Cesium","Cs",132.905,"[Xe] 6s1","1 (IA)","s","Solid","Alkali Metal"},
    {56,"Barium","Ba",137.327,"[Xe] 6s2","2 (IIA)","s","Solid","Alkaline Earth Metal"},
    {57,"Lanthanum","La",138.905,"[Xe] 5d1 6s2","3 (IIIB)","d","Solid","Lanthanide"},
    {58,"Cerium","Ce",140.116,"[Xe] 4f1 5d1 6s2","N/A","f","Solid","Lanthanide"},
    {59,"Praseodymium","Pr",140.908,"[Xe] 4f3 6s2","N/A","f","Solid","Lanthanide"},
    {60,"Neodymium","Nd",144.242,"[Xe] 4f4 6s2","N/A","f","Solid","Lanthanide"},
    {61,"Promethium","Pm",145.000,"[Xe] 4f5 6s2","N/A","f","Solid","Lanthanide"},
    {62,"Samarium","Sm",150.360,"[Xe] 4f6 6s2","N/A","f","Solid","Lanthanide"},
    {63,"Europium","Eu",151.964,"[Xe] 4f7 6s2","N/A","f","Solid","Lanthanide"},
    {64,"Gadolinium","Gd",157.250,"[Xe] 4f7 5d1 6s2","N/A","f","Solid","Lanthanide"},
    {65,"Terbium","Tb",158.925,"[Xe] 4f9 6s2","N/A","f","Solid","Lanthanide"},
    {66,"Dysprosium","Dy",162.500,"[Xe] 4f10 6s2","N/A","f","Solid","Lanthanide"},
    {67,"Holmium","Ho",164.930,"[Xe] 4f11 6s2","N/A","f","Solid","Lanthanide"},
    {68,"Erbium","Er",167.259,"[Xe] 4f12 6s2","N/A","f","Solid","Lanthanide"},
    {69,"Thulium","Tm",168.934,"[Xe] 4f13 6s2","N/A","f","Solid","Lanthanide"},
    {70,"Ytterbium","Yb",173.054,"[Xe] 4f14 6s2","N/A","f","Solid","Lanthanide"},
    {71,"Lutetium","Lu",174.967,"[Xe] 4f14 5d1 6s2","3 (IIIB)","d","Solid","Lanthanide"},
    {72,"Hafnium","Hf",178.490,"[Xe] 4f14 5d2 6s2","4 (IVB)","d","Solid","Transition Metal"},
    {73,"Tantalum","Ta",180.948,"[Xe] 4f14 5d3 6s2","5 (VB)","d","Solid","Transition Metal"},
    {74,"Tungsten","W",183.840,"[Xe] 4f14 5d4 6s2","6 (VIB)","d","Solid","Transition Metal"},
    {75,"Rhenium","Re",186.207,"[Xe] 4f14 5d5 6s2","7 (VIIB)","d","Solid","Transition Metal"},
    {76,"Osmium","Os",190.230,"[Xe] 4f14 5d6 6s2","8 (VIIIB)","d","Solid","Transition Metal"},
    {77,"Iridium","Ir",192.217,"[Xe] 4f14 5d7 6s2","9 (VIIIB)","d","Solid","Transition Metal"},
    {78,"Platinum","Pt",195.084,"[Xe] 4f14 5d9 6s1","10 (VIIIB)","d","Solid","Transition Metal"},
    {79,"Gold","Au",196.967,"[Xe] 4f14 5d10 6s1","11 (IB)","d","Solid","Transition Metal"},
    {80,"Mercury","Hg",200.590,"[Xe] 4f14 5d10 6s2","12 (IIB)","d","Liquid","Transition Metal"},
    {81,"Thallium","Tl",204.383,"[Xe] 4f14 5d10 6s2 6p1","13 (IIIA)","p","Solid","Post-transition Metal"},
    {82,"Lead","Pb",207.200,"[Xe] 4f14 5d10 6s2 6p2","14 (IVA)","p","Solid","Post-transition Metal"},
    {83,"Bismuth","Bi",208.980,"[Xe] 4f14 5d10 6s2 6p3","15 (VA)","p","Solid","Post-transition Metal"},
    {84,"Polonium","Po",209.000,"[Xe] 4f14 5d10 6s2 6p4","16 (VIA)","p","Solid","Post-transition Metal"},
    {85,"Astatine","At",210.000,"[Xe] 4f14 5d10 6s2 6p5","17 (VIIA)","p","Solid","Halogen"},
    {86,"Radon","Rn",222.000,"[Xe] 4f14 5d10 6s2 6p6","18 (VIIIA)","p","Gas","Noble Gas"},
    {87,"Francium","Fr",223.000,"[Rn] 7s1","1 (IA)","s","Solid","Alkali Metal"},
    {88,"Radium","Ra",226.000,"[Rn] 7s2","2 (IIA)","s","Solid","Alkaline Earth Metal"},
    {89,"Actinium","Ac",227.000,"[Rn] 6d1 7s2","3 (IIIB)","d","Solid","Actinide"},
    {90,"Thorium","Th",232.038,"[Rn] 6d2 7s2","N/A","f","Solid","Actinide"},
    {91,"Protactinium","Pa",231.036,"[Rn] 5f2 6d1 7s2","N/A","f","Solid","Actinide"},
    {92,"Uranium","U",238.029,"[Rn] 5f3 6d1 7s2","N/A","f","Solid","Actinide"},
    {93,"Neptunium","Np",237.000,"[Rn] 5f4 6d1 7s2","N/A","f","Solid","Actinide"},
    {94,"Plutonium","Pu",244.000,"[Rn] 5f6 7s2","N/A","f","Solid","Actinide"},
    {95,"Americium","Am",243.000,"[Rn] 5f7 7s2","N/A","f","Solid","Actinide"},
    {96,"Curium","Cm",247.000,"[Rn] 5f7 6d1 7s2","N/A","f","Solid","Actinide"},
    {97,"Berkelium","Bk",247.000,"[Rn] 5f9 7s2","N/A","f","Solid","Actinide"},
    {98,"Californium","Cf",251.000,"[Rn] 5f10 7s2","N/A","f","Solid","Actinide"},
    {99,"Einsteinium","Es",252.000,"[Rn] 5f11 7s2","N/A","f","Solid","Actinide"},
    {100,"Fermium","Fm",257.000,"[Rn] 5f12 7s2","N/A","f","Solid","Actinide"},
    {101,"Mendelevium","Md",258.000,"[Rn] 5f13 7s2","N/A","f","Solid","Actinide"},
    {102,"Nobelium","No",259.000,"[Rn] 5f14 7s2","N/A","f","Solid","Actinide"},
    {103,"Lawrencium","Lr",262.000,"[Rn] 5f14 7s2 7p1","3 (IIIB)","d","Solid","Actinide"},
    {104,"Rutherfordium","Rf",267.000,"[Rn] 5f14 6d2 7s2","4 (IVB)","d","Solid","Transition Metal"},
    {105,"Dubnium","Db",268.000,"[Rn] 5f14 6d3 7s2","5 (VB)","d","Solid","Transition Metal"},
    {106,"Seaborgium","Sg",271.000,"[Rn] 5f14 6d4 7s2","6 (VIB)","d","Solid","Transition Metal"},
    {107,"Bohrium","Bh",272.000,"[Rn] 5f14 6d5 7s2","7 (VIIB)","d","Solid","Transition Metal"},
    {108,"Hassium","Hs",270.000,"[Rn] 5f14 6d6 7s2","8 (VIIIB)","d","Solid","Transition Metal"},
    {109,"Meitnerium","Mt",276.000,"[Rn] 5f14 6d7 7s2","9 (VIIIB)","d","Solid","Transition Metal"},
    {110,"Darmstadtium","Ds",281.000,"[Rn] 5f14 6d9 7s1","10 (VIIIB)","d","Solid","Transition Metal"},
    {111,"Roentgenium","Rg",280.000,"[Rn] 5f14 6d10 7s1","11 (IB)","d","Solid","Transition Metal"},
    {112,"Copernicium","Cn",285.000,"[Rn] 5f14 6d10 7s2","12 (IIB)","d","Solid","Transition Metal"},
    {113,"Nihonium","Nh",286.000,"[Rn] 5f14 6d10 7s2 7p1","13 (IIIA)","p","Solid","Post-transition Metal"},
    {114,"Flerovium","Fl",289.000,"[Rn] 5f14 6d10 7s2 7p2","14 (IVA)","p","Solid","Post-transition Metal"},
    {115,"Moscovium","Mc",290.000,"[Rn] 5f14 6d10 7s2 7p3","15 (VA)","p","Solid","Post-transition Metal"},
    {116,"Livermorium","Lv",293.000,"[Rn] 5f14 6d10 7s2 7p4","16 (VIA)","p","Solid","Post-transition Metal"},
    {117,"Tennessine","Ts",294.000,"[Rn] 5f14 6d10 7s2 7p5","17 (VIIA)","p","Solid","Halogen"},
    {118,"Oganesson","Og",294.000,"[Rn] 5f14 6d10 7s2 7p6","18 (VIIIA)","p","Gas","Noble Gas"}
};

void print_title_screen() {
    printf("\n");
    printf("+-----------------------------------------------------+\n");
    printf("|          MODERN PERIODIC TABLE EXPLORER (C)         |\n");
    printf("+-----------------------------------------------------+\n");
    printf("|  COMPREHENSIVE EDITION (1 to 118) - SEM 1 PROJECT   |\n");
    printf("+-----------------------------------------------------+\n");
    printf("\n");
}

const Element* findElementDetails(int atomicNum) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        if (periodic_table_data[i].atomic_number == atomicNum) {
            return &periodic_table_data[i];
        }
    }
    return NULL;
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
                break;

            case 3:
                printf("Exiting... Thank you.\n");
                return 0;  
        }

        printf("\nPress ENTER to return to menu...");
        while (getchar() != '\n');
        getchar();

    } while (1);

    return 0;
}

