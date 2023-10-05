/*---------------------------------------------------*/
/* [FILE NAME]:<MenuUiUx.c>
   [Author]:<Eng.Muhammad Ahmed Roshdy >
   [Date]: <25-9-2023>
   [Project]: <Bank Management system >
*/
/*-----------------------------------------------------------*/
/*-----------------------------INCLUDES------------------------*/
#include "MenuUiUx.h"
/*-------------------Functions Implementations  ------------------------*/
/* Function to clear screen using windows library  */
void clear_screen() {
    system("cls"); /* Clear the console screen using system command */
}
/*---------------------------------------------------*/
/* Function to set colors for easy readable accessing using windows library  */
void set_color(char* color) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); /** Get the handle to the console window */
    /* Set console text color based on the input color string */
    if (strcmp(color, "BLACK") == 0) SetConsoleTextAttribute(hConsole, 0);
    /* Set text color to black if input color is "BLACK" */
    else if (strcmp(color, "BLUE") == 0) SetConsoleTextAttribute(hConsole, 1);
    /* Set text color to blue if input color is "BLUE" */
    else if (strcmp(color, "GREEN") == 0) SetConsoleTextAttribute(hConsole, 2);
    /* Set text color to green if input color is "GREEN" */
    else if (strcmp(color, "CYAN") == 0) SetConsoleTextAttribute(hConsole, 3);
    /* Set text color to cyan if input color is "CYAN" */
    else if (strcmp(color, "RED") == 0) SetConsoleTextAttribute(hConsole, 4);
    /* Set text color to red if input color is "RED" */
    else if (strcmp(color, "MAGENTA") == 0) SetConsoleTextAttribute(hConsole, 5);
    /* Set text color to magenta if input color is "MAGENTA" */
    else if (strcmp(color, "BROWN") == 0) SetConsoleTextAttribute(hConsole, 6);
    /* Set text color to brown if input color is "BROWN" */
    else if (strcmp(color, "LIGHTGRAY") == 0) SetConsoleTextAttribute(hConsole, 7);
    /* Set text color to light gray if input color is "LIGHTGRAY" */
    else if (strcmp(color, "DARKGRAY") == 0) SetConsoleTextAttribute(hConsole, 8);
    /* Set text color to dark gray if input color is "DARKGRAY" */
    else if (strcmp(color, "LIGHTBLUE") == 0) SetConsoleTextAttribute(hConsole, 9);
    /* Set text color to light blue if input color is "LIGHTBLUE" */
    else if (strcmp(color, "LIGHTGREEN") == 0) SetConsoleTextAttribute(hConsole, 10);
    /* Set text color to light green if input color is "LIGHTGREEN" */
    else if (strcmp(color, "LIGHTCYAN") == 0) SetConsoleTextAttribute(hConsole, 11);
    /* Set text color to light cyan if input color is "LIGHTCYAN" */
    else if (strcmp(color, "LIGHTRED") == 0) SetConsoleTextAttribute(hConsole, 12);
    /* Set text color to light red if input color is "LIGHTRED" */
    else if (strcmp(color, "LIGHTMAGENTA") == 0) SetConsoleTextAttribute(hConsole, 13);
    /* Set text color to light magenta if input color is "LIGHTMAGENTA" */
    else if (strcmp(color, "YELLOW") == 0) SetConsoleTextAttribute(hConsole, 14);
    /* Set text color to yellow if input color is "YELLOW" */
    else if (strcmp(color, "WHITE") == 0) SetConsoleTextAttribute(hConsole, 15);
    /* Set text color to white if input color is "WHITE" */
}
/*-----------------------------------------------------------------------------------*/
/* Colorful menu using windows library */
void MAIN_MENU(int selected_option) {
    clear_screen(); /* Clear the console screen*/
    set_color("BROWN"); /* Set the console text color to bright green */
    printf("*---------------------------------------*\n");
    set_color("YELLOW"); /* Set the console text color to bright green */
    printf("*        BANK MANAGEMENT SYSTEM         *\n");
    set_color("BROWN"); /* Set the console text color to CYAN */
    printf("*---------------------------------------*\n");
    set_color("LIGHTCYAN"); /* Set the console text color to white */
    printf("*---------------------------------------*\n");
    /* Print menu options with different colors based on selection */
    printf("|  ");
    set_color(selected_option == 1 ? "LIGHTBLUE" : "WHITE"); /* Set red if selected, otherwise white */
    printf("1. Create a New Account              ");
    set_color("DARKGRAY");
    printf("|\n");
    printf("|  ");
    set_color(selected_option == 2 ? "LIGHTBLUE" : "WHITE");
    printf("2. Delete an Account                 ");
    set_color("LIGHTGRAY");
    printf("|\n");
    printf("|  ");
    set_color(selected_option == 3 ? "LIGHTBLUE" : "WHITE");
    printf("3. View Customer List                ");
    set_color("DARKGRAY");
    printf("|\n");
    printf("|  ");
    set_color(selected_option == 4 ? "LIGHTBLUE" : "WHITE");
    printf("4. Edit Customer Account             ");
    set_color("LIGHTCYAN");
    printf("|\n");
    printf("|  ");
    set_color(selected_option == 5 ? "LIGHTRED" : "WHITE");
    printf("5. Perform Transaction               ");
    set_color("LIGHTGRAY");
    printf("|\n");
    printf("|  ");
    set_color(selected_option == 6 ? "LIGHTRED" : "WHITE");
    printf("6.View Account Transactions          ");
    set_color("LIGHTGRAY");
    printf("|\n");
    printf("|  ");
    set_color(selected_option == 0 ? "MAGENTA" : "WHITE");
    printf("7. Exit                              ");
    set_color("LIGHTCYAN");
    printf("|\n");
    printf("*---------------------------------------*\n");
    printf("*Enter your choice:*\n");
}
/*-----------------------------------------------------------------------------------*/
/*---------------------------*end of file*-------------------------------------------*/




