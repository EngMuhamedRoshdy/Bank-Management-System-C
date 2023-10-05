/*---------------------------------------------------*/
/* [FILE NAME]:<MenuUiUx.h>
   [Author]:<Eng.Muhammad Ahmed Roshdy >
   [Date]: <24-9-2023>
   [Project]: <Bank Management system >
*/
/*---------------------------------------------------*/
/*-------------------INCLUDES------------------------*/
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <windows.h>
/*---------------------------------------------------------------*/
/*-------------------FUNCTIONS PROTOTYPES------------------------*/
/* Function to clear screen using windows library  */
void clear_screen();
/*---------------------------------------------------------------*/
/* Function to set colors for easy readable accessing using windows library  */
void set_color(char* color);
/*---------------------------------------------------*/
/* color full menu using windows library  */
void MAIN_MENU(int selected_option);
/*---------------------------------------------------*/
#endif /* MENUUIUX_H_INCLUDED*/
/*---------------------------*end of file*-------------------------------------------*/
