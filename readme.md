# Modern Periodic Table Explorer (C)

A comprehensive console-based periodic table application written in C
that allows users to explore detailed information about all 118 chemical
elements.

## Table of Contents

-   [About](#about)
-   [Features](#features)
-   [How to Run](#how-to-run)
-   [System Architecture](#system-architecture)
-   [Data Structure](#data-structure)
-   [Usage Guide](#usage-guide)
-   [Test Cases](#test-cases)
-   [Author](#author)

## About

This is a Semester 1 academic project that implements an interactive
periodic table explorer in C. The program provides a structured database
of all 118 elements with their key chemical properties, organized using
C structures and arrays. Users can search for elements by atomic number
and view comprehensive details including atomic mass, electronic
configuration, group, block, category, and physical state at STP.

## Features

-   **Complete Element Database**: Contains all 118 elements from
    Hydrogen to Oganesson
-   **Detailed Element Information**: Displays 9 key properties for each
    element:
    -   Atomic number
    -   Element name and symbol
    -   Atomic mass
    -   Group and block classification
    -   Electronic configuration
    -   Category (metal, nonmetal, noble gas, etc.)
    -   Physical state at STP
-   **Search Functionality**: Quick lookup by atomic number
-   **Element List View**: Display all 118 elements in tabular format
-   **User-Friendly Interface**: Clean menu-driven console interface
    with formatted output tables
-   **Input Validation**: Error handling for invalid inputs and
    out-of-range atomic numbers

## How to Run

### Prerequisites

-   GCC compiler (or any C compiler)
-   Terminal/Command Prompt

### Compilation

**On Linux/macOS:**

    gcc -o periodic_table periodic_table.c
    ./periodic_table

**On Windows:**

    gcc -o periodic_table.exe periodic_table.c
    periodic_table.exe

### Alternative (Using Make)

Create a `Makefile`:

    CC = gcc
    CFLAGS = -Wall -std=c99

    periodic_table: periodic_table.c
        $(CC) $(CFLAGS) -o periodic_table periodic_table.c

    clean:
        rm -f periodic_table

Then run:

    make
    ./periodic_table

## System Architecture

The program follows a modular design pattern with clear separation of
concerns:

    ┌─────────────────────────────────────┐
    │ Main Program Flow                   │
    ├─────────────────────────────────────┤
    │ 1. Display Title Screen             │
    │ 2. Show Main Menu                   │
    │ 3. Process User Input               │
    │ 4. Call Appropriate Functions       │
    │ 5. Display Results                  │
    │ 6. Loop Until Exit                  │
    └─────────────────────────────────────┘

    ├──► print_title_screen()
    ├──► Menu Selection Handler
    │     ├──► findElementDetails()
    │     └──► displayElement()
    └──► Input Validation & Error Handling

### Key Components

1.  **Data Layer**: Static constant array `periodic_table_data[118]`
    containing all element information\
2.  **Search Module**: `findElementDetails()` function for element
    lookup\
3.  **Display Module**: `displayElement()` for formatted output\
4.  **User Interface**: Menu-driven interaction with input validation\
5.  **Main Controller**: Orchestrates program flow and user interaction

## Data Structure

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

### Data Storage

-   **Storage Type**: Static constant array\
-   **Total Elements**: 118\
-   **Memory Efficient**: Fixed-size structure for predictable memory
    usage\
-   **Search Complexity**: O(n) linear search

## Usage Guide

### Starting the Program

When launched, you'll see the title screen followed by the main menu:

    +-----------------------------------------------------+
    | MODERN PERIODIC TABLE EXPLORER (C)                  |
    +-----------------------------------------------------+
    | COMPREHENSIVE EDITION (1 to 118) - SEM 1 PROJECT    |
    +-----------------------------------------------------+

### Option 1: Search by Atomic Number

1.  Select option `1`
2.  Enter atomic number (1-118)
3.  View detailed element information

### Option 2: List All Elements

Displays a complete table of all 118 elements showing atomic number,
symbol, and name.

### Option 3: Exit

Terminates the program.

## Test Cases

  Test Case          Input      Expected Output     Status
  ------------------ ---------- ------------------- --------
  Valid search       1          Hydrogen details    ✓ Pass
  Valid search       118        Oganesson details   ✓ Pass
  Out of range       0          Error               ✓ Pass
  Out of range       119        Error               ✓ Pass
  Invalid input      abc        Error               ✓ Pass
  Transition metal   26         Iron                ✓ Pass
  Noble gas          10         Neon                ✓ Pass
  Liquid element     35         Bromine             ✓ Pass
  List               Option 2   All 118 elements    ✓ Pass
  Exit               Option 3   Exit                ✓ Pass

## Author

**Semester 1 Project -- Modern Periodic Table Explorer (C)**\
Created by **Nikhil Pant**

------------------------------------------------------------------------


