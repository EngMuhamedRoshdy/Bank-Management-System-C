/*--------------------------------------------------------------------*/
            /*---------------------------------------*/
                    /*---***MAIN FILE***--*/
/*--------------------------------------------------------------------*/
/* [FILE NAME]:<main.C>
   [Author]:<Eng.Muhammad Ahmed Roshdy >
   [Date]: <27-9-2023>
   [Project]: <Bank Management system >
*/
/*---------------------------------------------------------------------*/
/*-------------------------*INCLUDES HERE*-----------------------------*/
#include"Bank.h"/* Include the Bank.h header file */
#include"MenuUiUx.h"/* Include the MenuUiUx.h header file */
/*------------------THERE IS NO GLOBAL VAR "MISRA C RULES"-------------*/
/*------------------------***MAIN FUNCTION***---------------------------*/
int main()
 {
    account* root = NULL;
    int choice, account_to_edit;
    choice = -1;
    MAIN_MENU(choice); /* Print first time for view effect in second time */
    do
        {
             /* Read user choice */
        while (scanf("%d", &choice) != 1) { /*for avoiding infinite loop!!*/
        fflush(stdin);/*free standard input buffer*/
        set_color("RED"); /*free root from heap avoiding any memory leakage*/
        printf("Error!! Invalid input...\n");
        set_color("LIGHTCYAN");/*function to set color you can find it in (MenuUiUi.h) file*/
        printf("Please enter an integer [1-7]:");
        /* Wait for user to press Enter */
        fflush(stdin); /* Clear input buffer */
        }
        MAIN_MENU(choice); /* Get the selected option "effect will viewed here" */
        switch (choice) {
            case 1:
                root = insertCustomer(root, createCustomer(root)); /*call insert Customer function*/
                set_color("LIGHTBLUE");/*function to set color you can find it in (MenuUiUi.h) file*/
                printf("*Enter your choice:*\n");
                break;
            case 2:
                printf("Enter Account Number of customer to delete: ");
                scanf("%d", &account_to_edit);
                fflush(stdin);/*free standard input buffer*/
                Delete_Customer(&root, account_to_edit); /*call Delete_Customer function*/
                set_color("LIGHTBLUE");/*function to set color you can find it in (MenuUiUi.h) file*/
                printf("*Enter your choice:*\n");
                break;
            case 3:
                CustomerDisplayList(root); /*call Customer Display List function*/
                set_color("LIGHTBLUE");
                printf("*Enter your choice:*\n");
                break;
            case 4:
                printf("Enter account number to edit: ");
                scanf("%d", &account_to_edit);
                fflush(stdin);/*free standard input buffer*/
                updateCustomer(root, account_to_edit, root); /*call update Customer function*/
                set_color("LIGHTBLUE");/*function to set color you can find it in (MenuUiUi.h) file*/
                printf("*Enter your choice:*\n");
                break;
            case 5:
                performTransaction(root); /*call performT ransaction function*/
                set_color("LIGHTBLUE");/*function to set color you can find it in (MenuUiUi.h) file*/
                printf("*Enter your choice:*\n");
                break;
            case 6:
                viewAccountTransactions(root); /*call view Account Transactions function*/
                set_color("LIGHTBLUE");/*function to set color you can find it in (MenuUiUi.h) file*/
                printf("*Enter your choice:*\n");
                break;
            case 7:
                set_color("LIGHTGREEN");/*function to set color you can find it in (MenuUiUi.h) file*/
                freeMemory(root); /* Free allocated memory before exiting */
                exit(0);           /* exiting success  */
            default:
                set_color("RED");/*function to set color you can find it in (MenuUiUi.h) file*/
                printf("Invalid choice. Please try again.\n");
                set_color("LIGHTBLUE");/*function to set color you can find it in (MenuUiUi.h) file*/
                printf("*Enter your choice:*\n");
                break;
        }
        }while(choice!=7);
    return 0;
}
/*---------------------------*end of file*-------------------------------------------*/
