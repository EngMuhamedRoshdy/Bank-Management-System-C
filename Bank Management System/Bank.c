/*--------------------------------------------------------------------------------*/
/* [FILE NAME]:<Bank.c>
   [Author]:<Eng.Muhammad Ahmed Roshdy >
   [Date]: <25-9-2023>
   [Project]: <Bank Management system >
*/
/*--------------------------------------------------------------------------------*/
/*--------------------------INCLUDES---------------------------------------------*/
#include "Bank.h"    /* Include the header file "Bank.h" */
#include "MenuUiUx.h" /* Include the header file "MenuUiUx.h" */
/*
    Example Binary Search Tree (BST) using Customer Structure:

                Node 1 (Account Number: 50)
            /                                 \
     Node 2 (Account Number: 30)       Node 3 (Account Number: 70)
            \                               /               \
    Node 4 (Account Number: 40)     Node 5 (Account Number: 80)

                                1
                               / \
                              2   3
                             / \ / \
                            4  5 6  7
*/
/*-----------------------------------------------------------------------
 * Linked List Representation using Transaction Structure:
 *
 * Node 1          Node 2          Node 3
 * +--------------+ +--------------+ +--------------+
 * | Transaction  | | Transaction  | | Transaction  |
 * | date: ...    | | date: ...    | | date: ...    |
 * | amount: ...  | | amount: ...  | | amount: ...  |
 * | next:   ---->| | next:   ---->| | next: NULL   |
 * +--------------+ +--------------+ +--------------+
 *
 * In this representation:
 * - Each "Node" represents an instance of the Transaction structure.
 * - Each node has the fields date, amount, and next.
 * - The next field is represented as an arrow pointing to the next node. In the
 *   last node, next points to NULL indicating the end of the linked list.
 *----------------------------------------------------------------------- */
/*---------------------------------------------------------------------------------------------*/
/**
 * Initializes a customer structure with default values.
 *
 * @param customer A pointer to the customer structure to be initialized.
 */
void initializeCustomer(account* customer) {
    if (customer != NULL) {
        customer->name[0] = '\0';      /**< Set name to an empty string. */
        customer->dob[0] = '\0';       /**< Set date of birth to an empty string. */
        customer->account_number = 0;  /**< Set account number to 0. */
        customer->address[0] = '\0';   /**< Set address to an empty string. */
        customer->phone_number[0] = '\0'; /**< Set phone number to an empty string. */
        customer->balance = 0.0;       /**< Set balance to 0.0. */
        customer->transactions = NULL; /**< Set transactions pointer to NULL. */
        customer->left = NULL;         /**< Initialize left pointer to NULL. */
        customer->right = NULL;        /**< Initialize right pointer to NULL. */
    }
    else{
        /*not used MISRA C RULE*/
    }
}
/*---------------------------------------------------------------------------------------------*/
/**
 * Initialize a transaction node.
 *
 * @param transaction A pointer to the transaction node to be initialized.
 */
void initializeTransaction(Transaction* transaction) {
    if (transaction != NULL) {
        transaction->date[0] = '\0'; /**< Set date to an empty string. */
        transaction->amount = 0.0; /**< Set amount to 0.0. */
        transaction->next = NULL; /**< Set next pointer to NULL. */
    }
}
/*---------------------------------------------------------------------------------------------*/
/**
 * Function to create a new customer account.
 *
 * @param root The root of the customer binary tree.
 * @return A pointer to the newly created customer account.
 */
/**
 * Create a new customer node and populate its details.
 *
 * @param root The root of the customer binary tree.
 * @return A pointer to the newly created customer node.
 */
account* createCustomer(account* root) {
    /** Allocate memory for the new customer */
    account* newCustomer = (account*)malloc(sizeof(account));
    if (newCustomer == NULL) {  /** Check if memory allocation was successful */
        printf("Memory allocation failed.\n");
        return NULL; /*RETURN null or newCustomer */
    } else {
        initializeCustomer(newCustomer);  /** initialize Customer with default values*/
        printf("Enter customer details:\n");
        /* getOnlyString is a function to accept only string you can read a brief of function from header file called (Bank.h)*/
        getOnlyString(newCustomer->name, sizeof(newCustomer->name), "Enter Name: ");  /** Get the name of the customer */
        fflush(stdin); /*free standard input buffer*/
        /* Get a unique account number */
        do {
            /* getPositiveInt is a function to accept only Positive Int you can read a brief of function from header file called (Bank.h)*/
            newCustomer->account_number = getPositiveInt("Enter account number (positive number): ");
            fflush(stdin); /*free standard input buffer*/
            /* Check if the account number already exists */
            if (searchCustomer(root, newCustomer->account_number) != NULL) {
                set_color("RED"); /*function to set color you can find it in (MenuUiUi.h) file*/
                printf("This Account Number Is Taken, please Try Another One.\n");
                fflush(stdin);/*free standard input buffer*/
                set_color("LIGHTCYAN"); /*function to set color you can find it in (MenuUiUi.h) file*/
            } else {
                break; /* Exit loop if the account number is unique*/
            }
        } while (1);
        printf("Date of Birth (YYYY-MM-DD): "); /*< Prompt for date of birth */
        while (1) { /*< Start an infinite loop for input validation */
            fflush(stdin); /*< Clear the input buffer */
            fgets(newCustomer->dob, sizeof(newCustomer->dob), stdin); /*< Get date of birth */
            fflush(stdin); /*< Clear the input buffer again */
            newCustomer->dob[strcspn(newCustomer->dob, "\n")] = '\0';  /*< Remove the newline character from the end of the input */
            fflush(stdin); /*< Clear the input buffer again */
            if (strlen(newCustomer->dob) > 0) { /**< Check if the input is not empty (user pressed only "Enter") */
                int valid = 1; /*< Initialize a flag for input validation */
                for (int i = 0; i < strlen(newCustomer->dob); i++) { /*< Iterate through the characters of the input */
                    if (!isdigit(newCustomer->dob[i]) && newCustomer->dob[i] != '-') { /*< Check if the character is not a digit or a dash */
                        valid = 0; /*< Set the validation flag to 0 if an invalid character is found */
                        break; /*< Exit the loop if an invalid character is found */
                    }
                }

                if (valid) { /*< If the input is valid, exit the loop */
                    break;
                } else {
                    set_color("RED"); /*function to set color you can find it in (MenuUiUi.h) file*/
                    printf("Invalid input. Please enter a valid date of birth (YYYY-MM-DD).\n"); /**< Print error message */
                    set_color("LIGHTCYAN"); /*function to set color you can find it in (MenuUiUi.h) file*/
                    printf("Date of Birth (YYYY-MM-DD): "); /*< Print the prompt message again */
                }
            } else {
                set_color("RED"); /*function to set color you can find it in (MenuUiUi.h) file*/
                printf("Invalid input. Please enter a date of birth.\n"); /**< Print error message */
                set_color("LIGHTCYAN"); /*function to set color you can find it in (MenuUiUi.h) file*/
                printf("Date of Birth (YYYY-MM-DD): "); /**< Print the prompt message again */
            }
        }

        printf("Address: "); /**< Prompt for address */
        while (1) { /*< Start an infinite loop for input validation */
            fflush(stdin); /*< Clear the input buffer */
            fgets(newCustomer->address, sizeof(newCustomer->address), stdin); /*< Get address */
            fflush(stdin); /*< Clear the input buffer again */
            newCustomer->address[strcspn(newCustomer->address, "\n")] = '\0';  /*< Remove the newline character from the end of the input */
            fflush(stdin); /*< Clear the input buffer again */
            if (strlen(newCustomer->address) > 0) { /*< Check if the input is not empty (user pressed only "Enter") */
                break; /*< If input is not empty, exit the loop */
            } else {
                set_color("RED");/*function to set color you can find it in (MenuUiUi.h) file*/
                printf("Invalid input. Please enter an address.\n"); /*< Print error message */
                set_color("LIGHTCYAN");/*function to set color you can find it in (MenuUiUi.h) file*/
                printf("Address: "); /*< Print the prompt message again */
            }
        }

        printf("Phone Number (Optional): "); /*< Prompt for phone number */
        fgets(newCustomer->phone_number,sizeof(newCustomer->phone_number),stdin); /**< Get phone number */
        newCustomer->phone_number[strcspn(newCustomer->phone_number, "\n")] = '\0'; /**< Remove trailing newline character */
        fflush(stdin); /*< Clear input buffer */
        newCustomer->balance = getPositiveDouble("Enter Balance (positive number): "); /**< Get positive double input */
        fflush(stdin); /*< Clear input buffer */
        newCustomer->left = NULL; /*< Initialize left pointer to NULL */
        newCustomer->right = NULL; /*< Initialize right pointer to NULL */
        set_color("LIGHTGREEN");/*function to set color you can find it in (MenuUiUi.h) file*/
        printf("Account Added successfully 'Welcome on board;)'\n ");
        set_color("LIGHTCYAN");/*function to set color you can find it in (MenuUiUi.h) file*/
        return newCustomer; /*< Return the newly created customer node */
    }
}
/*---------------------------------------------------------------------------------------------*/
/*
 * Function: insertCustomer
 * ------------------------
 * Inserts a customer node into the binary tree recursively.
 *
 * root: The root of the customer binary tree.
 * newCustomer: A pointer to the new customer node to be inserted.
 *
 * returns: The root of the updated customer binary tree.
 */
account* insertCustomer(account* root, account* newCustomer) {
        /* Base case: If the tree is empty, return the new customer as the root */
    if (root == NULL) {
        return newCustomer; /* Return new customer if tree is empty */
    } else {
        /* Compare the account number of newCustomer with the current root node */
        if (newCustomer->account_number < root->account_number) {
            /* If newCustomer's account number is smaller, insert in the left subtree */
            root->left = insertCustomer(root->left, newCustomer); /* Recur for left subtree if new account number is smaller */
        } else if (newCustomer->account_number > root->account_number) {
            /* If newCustomer's account number is greater, insert in the right subtree */
            root->right = insertCustomer(root->right, newCustomer); /* Recur for right subtree if new account number is greater */
        } else {
            printf("This Account Number Is Taken , please Try Another One \n");/* Account number already exists, print a message */
        }
        return root; /* Return the root of the tree after insertion */
    }
}
/*---------------------------------------------------------------------------------------------*/
/**
 * Delete a customer node by account number (recursive).
 *
 * @param root The root of the customer binary tree.
 * @param account_number The account number to be deleted.
 * @return The root of the updated customer binary tree.
 */
account* Del_Cstmr(account* root, int account_number) {
    if (root == NULL) {
        return root; /*< Return NULL if tree is empty */
    } else {
        if (account_number < root->account_number) {
            root->left = Del_Cstmr(root->left, account_number); /*< Recur for left subtree if account number is smaller */
        } else if (account_number > root->account_number) {
            root->right = Del_Cstmr(root->right, account_number); /*< Recur for right subtree if account number is greater */
        } else {
            if (root->left == NULL) {
                account* temp = root->right;
                free(root); /*free root from heap avoiding any memory leakage*/
                return temp; /*< Return right subtree if left child is NULL */
            } else if (root->right == NULL) {
                account* temp = root->left;
                free(root); /*free root from heap avoiding any memory leakage*/
                return temp; /*< Return left subtree if right child is NULL */
            } else {
                account* temp = root->right;
                while (temp->left != NULL) {
                    temp = temp->left; /*temp here the leaf node of the right to swap it with deleted node to keep tree balanced*/
                }
                strcpy(root->name, temp->name);/* Copy the name from temp node to root node. */
                strcpy(root->dob, temp->dob); /* Copy the date of birth from temp node to root node. */
                root->account_number = temp->account_number; /** Copy the account number from temp node to root node. */
                strcpy(root->address, temp->address);/** Copy the address from temp node to root node. */
                strcpy(root->phone_number, temp->phone_number);/** Copy the phone number from temp node to root node. */
                root->balance = temp->balance;/** Copy the balance from temp node to root node. */
                root->right = Del_Cstmr(root->right, temp->account_number); /**< Recur to delete duplicate node in right subtree */
            }
        }
        return root; /**< Return the root of the tree after deletion */
    }
}
/*---------------------------------------------------------------------------------------------*/
/**
 * "Wrapper" function to delete a customer by account number.
 *
 * @param root A pointer to the root of the customer binary tree.
 * @param account_number The account number of the customer to be deleted.
 */
void Delete_Customer(account** root, int account_number) {
    account* Customer_To_Delete = searchCustomer(*root, account_number); /*< Find the customer node to be deleted. */

    if (Customer_To_Delete == NULL) {
        printf("Customer with Account Number %d not found please make sure that you type it correctly.\n", account_number); /*< Print error message if customer not found. */
        return; /*return out of the function*/
    } else {
        *root = Del_Cstmr(*root, account_number); /*< Delete the customer node. */
        printf("Customer with Account Number %d has been deleted.\n", account_number); /**< Print success message. */
    }
}
/*---------------------------------------------------------------------------------------------*/
/**
 * Search for a customer node by account number.
 *
 * @param root The root of the customer binary tree.
 * @param account_number The account number to search for.
 * @return A pointer to the customer node if found, otherwise NULL.
 */
account* searchCustomer(account* root, int account_number) {
    if (root == NULL || root->account_number == account_number) {
        return root; /*< Return the root node if it is NULL or if the account number matches. */
    } else {
        if (account_number < root->account_number) {
            return searchCustomer(root->left, account_number); /*< Recur for left subtree if account number is smaller. */
        } else {
            return searchCustomer(root->right, account_number); /*< Recur for right subtree if account number is greater. */
        }
    }
}
/*---------------------------------------------------------------------------------------------*/
/**
 * Update customer information.
 *
 * @param customer A pointer to the customer to be updated.
 * @param account_to_edit The account number of the customer to be updated.
 * @param root The root of the customer binary tree.
 */
void updateCustomer(account* customer, int account_to_edit, account* root) {
    account* edit_customer = searchCustomer(customer, account_to_edit); /** Find the customer to be edited */
    if (edit_customer == NULL) {
        set_color("RED");
        printf("Customer not found.\n"); /* If customer is not found, print error message and return */
        set_color("LIGHTCYAN");
        return; /*return out of the function*/
    }
    /*menu for editing customer with Account Number from {1-6,0}*/
    printf("| Editing customer with Account Number %d\n", account_to_edit); /* Display menu for editing options */
    printf("-----------------------------------------------\n");
    set_color("LIGHTGREEN");/*function to set color you can find it in (MenuUiUi.h) file*/
    printf("1. Name\n");
    printf("2. Date of Birth\n");
    printf("3. Account Number\n");
    printf("4. Address\n");
    printf("5. Phone Number\n");
    printf("6. Balance\n");
    printf("0. Cancel\n");
    set_color("LIGHTCYAN");/*function to set color you can find it in (MenuUiUi.h) file*/
    printf("************************************************\n");
    printf("Enter your choice: ");
    int choice; /*declare variable to choose */
    scanf("%d", &choice); /*< Read user's choice */
    fflush(stdin); /*< Clear input buffer */
    switch (choice) {
        case 1:
           getOnlyString(edit_customer->name, sizeof(edit_customer->name), "Enter New Name: ");  /** Get the name of the customer */
           fflush(stdin); /*free standard input buffer*/
            break;
        case 2:
        printf("Date of Birth (YYYY-MM-DD): "); /*< Prompt for date of birth */
        while (1) { /*< Start an infinite loop for input validation */
            fflush(stdin); /*< Clear the input buffer */
            fgets(edit_customer->dob, sizeof(edit_customer->dob), stdin); /*< Get date of birth */
            fflush(stdin); /*< Clear the input buffer again */
            edit_customer->dob[strcspn(edit_customer->dob, "\n")] = '\0';  /*< Remove the newline character from the end of the input */
            fflush(stdin); /*< Clear the input buffer again */
            if (strlen(edit_customer->dob) > 0) { /*< Check if the input is not empty (user pressed only "Enter") */
                int valid = 1; /*< Initialize a flag for input validation */
                for (int i = 0; i < strlen(edit_customer->dob); i++) { /*< Iterate through the characters of the input */
                    if (!isdigit(edit_customer->dob[i]) && edit_customer->dob[i] != '-') { /*< Check if the character is not a digit or a dash */
                        valid = 0; /*< Set the validation flag to 0 if an invalid character is found */
                        break; /*< Exit the loop if an invalid character is found */
                    }
                }
                if (valid) { /*< If the input is valid, exit the loop */
                    break;
                } else {
                    set_color("RED"); /*function to set color you can find it in (MenuUiUi.h) file*/
                    printf("Invalid input. Please enter a valid date of birth (YYYY-MM-DD).\n"); /**< Print error message */
                    set_color("LIGHTCYAN"); /*function to set color you can find it in (MenuUiUi.h) file*/
                    printf("Date of Birth (YYYY-MM-DD): "); /*< Print the prompt message again */
                }
            } else {
                set_color("RED"); /*function to set color you can find it in (MenuUiUi.h) file*/
                printf("Invalid input. Please enter a date of birth.\n"); /**< Print error message */
                set_color("LIGHTCYAN"); /*function to set color you can find it in (MenuUiUi.h) file*/
                printf("Date of Birth (YYYY-MM-DD): "); /**< Print the prompt message again */
            }
        }
            break;
        case 3: {
                    do {
             int new_account_number;
            /* getPositiveInt is a function to accept only Positive Int you can read a brief of function from header file called (Bank.h)*/
            new_account_number = getPositiveInt("Enter New account number (positive number): ");
            fflush(stdin); /*free standard input buffer*/
            /* Check if the account number already exists */
            if (searchCustomer(root, new_account_number) != NULL) {
                set_color("RED"); /*function to set color you can find it in (MenuUiUi.h) file*/
                printf("This Account Number Is Taken, please Try Another One.\n");
                fflush(stdin);/*free standard input buffer*/
                set_color("LIGHTCYAN"); /*function to set color you can find it in (MenuUiUi.h) file*/
            } else {
                edit_customer->account_number = new_account_number; /*< Set new account number */
                break; /* Exit loop if the account number is unique*/
            }
        } while (1);
          break; /* Exit loop if the account number is unique*/
        }
        case 4:
                printf("Enter New Address: "); /*< Prompt for address */
                while (1) { /*< Start an infinite loop for input validation */
                fflush(stdin); /*< Clear the input buffer */
                fgets(edit_customer->address, sizeof(edit_customer->address), stdin); /*< Get address */
                fflush(stdin); /*< Clear the input buffer again */
                edit_customer->address[strcspn(edit_customer->address, "\n")] = '\0';  /*< Remove the newline character from the end of the input */
                fflush(stdin); /*< Clear the input buffer again */
                if (strlen(edit_customer->address) > 0) { /*< Check if the input is not empty (user pressed only "Enter") */
                    break; /*< If input is not empty, exit the loop */
                } else {
                    set_color("RED");/*function to set color you can find it in (MenuUiUi.h) file*/
                    printf("Invalid input. Please enter an address.\n"); /*< Print error message */
                    set_color("LIGHTCYAN");/*function to set color you can find it in (MenuUiUi.h) file*/
                    printf("Address: "); /*< Print the prompt message again */
                }
            }
            break;
        case 5:
            printf("Enter New Phone Number: ");
            fgets(edit_customer->phone_number, sizeof(edit_customer->phone_number), stdin); /* Prompt and edit Phone Number */
            edit_customer->phone_number[strcspn(edit_customer->phone_number, "\n")] = '\0'; /*< Remove newline character from input */
            fflush(stdin); /*< Clear input buffer */
            break;
        case 6:
            edit_customer->balance = getPositiveDouble("Enter New Balance (positive number): "); /**< Get positive double input */
            fflush(stdin); /*< Clear input buffer */
            break;
        case 0:
            printf("Editing canceled.\n"); /*< Display cancellation message */
            break;
        default:
            printf("Invalid choice.\n"); /*< Display error message for invalid input */
    }
}
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief "helper function" Compare function for sorting customers by names.
 *
 * @param x A pointer to the first customer.
 * @param y A pointer to the second customer.
 * @return An integer less than, equal to, or greater than zero if the first customer
 *         is found to be less than, equal to, or greater than the second customer.
 */
int compare(const void* x, const void* y) {
    account* customer_x = *((account**)x); /*< Cast void pointer to account pointer for comparison */
    account* customer_y = *((account**)y); /*< Cast void pointer to account pointer for comparison */
    return strcmp(customer_x->name, customer_y->name); /*< Compare names using strcmp */
}
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Helper function to populate customers array and count (in-order traversal).
 *
 * @param root The root of the customer binary tree.
 * @param customers An array to store customer pointers.
 * @param count A pointer to the count of customers.
 */
void Customer_list_sort(account* root, account* customers[], int* count) {
    if (root == NULL) {
        return; /*< Return if tree is empty */
    }
    else{
        Customer_list_sort(root->left, customers, count); /*< Traverse left subtree */
        customers[*count] = root; /*< Store current customer in the array */
        (*count)++; /*< Increment the count */
        Customer_list_sort(root->right, customers, count); /*< Traverse right subtree */
    }
}
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Function to free memory (called when exiting the program).
 *
 * @param root The root of the customer binary tree.
 */
void freeMemory(account* root) {
    if (root != NULL) {
        freeMemory(root->left); /*< Recursively free left subtree */
        freeMemory(root->right); /*< Recursively free right subtree */
        free(root); /*< Free current node */
    }
    else{
        /*No else here for MISRA C Rules*/
    }
}
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Function to display the customer list in ascending order by name.
 *
 * @param root The root of the customer binary tree.
 */
void CustomerDisplayList(account* root) {
    /* If the tree is empty (no students), return without further processing */
    if (root == NULL) {
        return; /*< If the tree is empty, return */
    }
    else{
        account* customers[100]; /*< Array to hold customer pointers */
        int count = 0; /*< Initialize count of customers */
        Customer_list_sort(root, customers, &count); /* Populate the customers array in in-order traversal */
        qsort(customers, count, sizeof(account*), compare); /* Sort the customers array by name */
        /* Assuming you have an array of Customer structures named customers[] */
        /* Print the top border of the table */
        printf("*--------------------------------*-----------------*-----------------*--------------------------------*-----------------*-----------------*\n");
        /* Print the table header */
        printTableHeader();
        /* Print the separator between header and data */
        printf("*--------------------------------*-----------------*-----------------*--------------------------------*-----------------*-----------------*\n");
        /* Loop through customers and print their information */
        for (int i = 0; i < count; i++) {
            printCustomerInfo(customers[i]);
            printf("*--------------------------------*-----------------*-----------------*--------------------------------*-----------------*-----------------*\n");
        }
    /* Print the bottom border of the table */
    }
}
     /*------------------------------------------------------------------------*/
                     /*-------------------------------*/
                            /*----transaction----*/
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Function to add a new transaction to a customer's list.
 *
 * @param transactions Pointer to the first transaction in the list.
 * @param date Date of the transaction.
 * @param amount Amount of the transaction.
 */
void addTransaction(Transaction** transactions, char* date, double amount) {
    Transaction* newTransaction = (Transaction*)malloc(sizeof(Transaction)); /**< Allocate memory for new transaction */
    if (newTransaction == NULL) {
        printf("Memory allocation failed.\n"); /*< Print error message if memory allocation fails */
    }
    else
    {
        initializeTransaction(newTransaction); /*< Initialize the new transaction */
        strcpy(newTransaction->date, date); /*< Copy the date to the new transaction */
        newTransaction->amount = amount; /*< Set the amount of the new transaction */

        newTransaction->next = *transactions; /*< Link the new transaction to the existing list */
        *transactions = newTransaction; /*< Update the pointer to the first transaction */
    }
}
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Function to get the current date in YYYY-MM-DD format.
 *
 * @param date Pointer to a character array where the date will be stored.
 */
void getCurrentDate(char* date) {
    time_t t; /**< Variable to hold the current time */
    struct tm* now; /**< Structure to hold date and time information */

    t = time(NULL); /**< Get current time */
    now = localtime(&t); /**< Convert to local time */

    /* Format the date and store it in the provided character array */
    sprintf(date, "%d-%02d-%02d", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
}
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Function to perform a transaction (deposit or withdrawal).
 *
 * @param root The root of the customer binary tree.
 */
void performTransaction(account* root) {
    int account_number; /* Variable to store account number */
    int choice; /* Variable to store user choice */
    double amount = 0.0; /* Variable to store transaction amount */
    char date[12]; /* Array to store transaction date in YYYY-MM-DD format */
    printf("Enter your account number: "); /* Prompt for account number */
    scanf("%d", &account_number); /* Read account number from user */
    fflush(stdin); /* Clear input buffer */
    account* customer = searchCustomer(root, account_number); /* Search for customer */
    if (customer == NULL) {
        printf("Customer with Account Number %d not found.\n", account_number); /* Print error message if customer not found */
    }
    else{
        printf("1. Deposit\n"); /* Print option for deposit */
        printf("2. Withdrawal\n"); /* Print option for withdrawal */
        printf("Enter your choice: "); /* Prompt for user choice */
        scanf("%d", &choice); /* Read user choice */
        fflush(stdin); /* Clear input buffer */
    if (choice == 1) {
        printf("Enter the deposit amount: "); /* Prompt for deposit amount */
        scanf("%lf", &amount); /* Read deposit amount */
        fflush(stdin); /* Clear input buffer */
        getCurrentDate(date); /* Get current date in YYYY-MM-DD format */
        addTransaction(&(customer->transactions), date, amount); /* Add transaction to customer's list */
        customer->balance += amount; /* Update customer's balance */
        printf("Deposit of %.2lf successfully added to your account.\n", amount); /* Print success message */
    }
    else if (choice == 2) {
        printf("Enter the withdrawal amount: "); /* Prompt for withdrawal amount */
        scanf("%lf", &amount); /* Read withdrawal amount */
        fflush(stdin); /* Clear input buffer */
        if (amount > customer->balance) {
            printf("Insufficient balance for withdrawal.\n"); /* Print error message if insufficient balance */
        }
        getCurrentDate(date); /* Get current date in YYYY-MM-DD format */
        addTransaction(&(customer->transactions), date, -amount); /* Add transaction to customer's list with negative amount (withdrawal) */
        customer->balance -= amount; /* Update customer's balance */
        printf("Withdrawal of %.2lf successfully processed.\n", amount); /* Print success message */
    }
    else {
        printf("Invalid choice.\n"); /* Print error message for invalid choice */
        }
    }
}
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Function to display the list of transactions for a given customer.
 *
 * @param customer A pointer to the customer node.
 */
void displayTransactions(account* customer) {
    Transaction* currentTransaction = customer->transactions; /* Initialize pointer to first transaction */
    if (currentTransaction == NULL) {
        printf("No transactions for this account.\n"); /* Print message if no transactions */
    }
    else{
       while (currentTransaction != NULL) { /* Loop through transactions */
        printf("Date: %s\n", currentTransaction->date); /* Print transaction date */
        printf("Amount: %.2lf\n", currentTransaction->amount); /* Print transaction amount */
        printf("-----------------------------\n"); /* Separator */
        currentTransaction = currentTransaction->next; /* Move to next transaction */
    }
            set_color("LIGHTGREEN");/*function to set color you can find it in (MenuUiUi.h) file*/
            printf("Total ballance = %.2lf\n",customer->balance);/*function to total balance of customer*/
            set_color("LIGHTCYAN");/*function to set color you can find it in (MenuUiUi.h) file*/
            printf("-----------------------------\n"); /* End separator */
    }
}
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Function to view account transactions.
 *
 * @param root A pointer to the root of the customer binary tree.
 */
void viewAccountTransactions(account* root) {
    int account_number;
    printf("Enter your account number: ");
    scanf("%d", &account_number);
    fflush(stdin);
    account* customer = searchCustomer(root, account_number); /* Search for customer */
    if (customer == NULL) {
        printf("Customer with Account Number %d not found.\n", account_number); /* Print error message if customer not found */
    }
    else if (customer->transactions == NULL) {
        printf("No transactions for Account Number %d.\n", account_number); /* Print message if no transactions */
    }
    else {
        printf("Account Transactions for Account Number %d:\n", account_number); /* Display account transactions */
        displayTransactions(customer); /*display customer Transactions*/
    }
}
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Function to get a only string input and don't accept any string with numbers or numbers
 *  with specified maximum length and prompt message.
 * @param str Pointer to the string where the input will be stored.
 * @param maxLen Maximum length of the input string.
 * @param prompt The prompt message to display.
 */
void getOnlyString(char* str, size_t maxLen, const char* prompt) {
    printf("%s", prompt); /*< Print the prompt message */
    while (1) { /*< Start an infinite loop for input validation */
        fflush(stdin); /*< Clear the input buffer */
        fgets(str, maxLen, stdin); /*< Read a line of input from the user */
        fflush(stdin); /*< Clear the input buffer again */
        str[strcspn(str, "\n")] = '\0';  /*< Remove the newline character from the end of the input */
        fflush(stdin); /*< Clear the input buffer again */
        if (strlen(str) == 0) { /*< Check if the input is empty (user pressed only "Enter") */
            set_color("RED");/*function to set color you can find it in (MenuUiUi.h) file*/
            printf("Error: You must provide input:\n"); /*< Print error message for empty input */
            set_color("LIGHTCYAN");/*function to set color you can find it in (MenuUiUi.h) file*/
             printf("%s", prompt); /*< Print the prompt message again */
            continue; /*< Prompt for input again if it's empty */
        }
        int valid = 1; /*< Initialize a flag for input validation */
        int register i; /* This declares a counter 'i' to consider using a CPU register for this variable. */
        for ( i = 0; i < strlen(str); i++) { /*< Iterate through the characters of the input */
            if (!isalpha(str[i]) && str[i] != ' ') { /*< Check if the character is not an alphabet or a space */
                valid = 0; /*< Set the validation flag to 0 if an invalid character is found */
                break; /*< Exit the loop if an invalid character is found */
            }
        }
        if (valid) { /*< If the input is valid (contains only alphabets and spaces), exit the loop */
            break;
        } else { /*< If the input is not valid, display an error message and prompt for input again */
            set_color("RED"); /*< Set text color to red for error message */
            printf("Invalid input. Please enter a valid name.\n"); /**< Print error message */
            fflush(stdin);/*free standard input buffer*/
            set_color("LIGHTCYAN"); /*< Set text color back to light cyan */
            printf("%s", prompt); /*< Print the prompt message again */

        }
    }
}
/*-----------------------------------------------------------------------*/
/**
 * @brief This function prompts the user for a positive integer input. It continues to
    prompt until a valid positive integer is provided. It also checks for any
    non-numeric characters in the input..
 *
 * @param prompt The prompt message to display.
 * @return The positive integer entered by the user.
 */
int getPositiveInt(const char* prompt) {
    int value; /* Declare a variable to store the user's input. */
    int validInput; /* Declare a flag to track input validity. */
    char buffer[100]; /* Assuming a reasonable maximum length for the input */
    while (1) {
        validInput = 1; /* Assume input is valid by default. */
        printf("%s", prompt); /* Print the provided prompt message. */
        if (fgets(buffer, 100, stdin) == NULL || sscanf(buffer, "%d", &value) != 1 || value <= 0) {
            validInput = 0; /* Set input validity flag to 0. */
        }
        if (validInput) {
            /* Now, we'll check if there are any non-numeric characters in the input */
            char* ptr = buffer;
            while (*ptr != '\0' && *ptr != '\n') {
                if (!isdigit(*ptr)) {
                    validInput = 0;
                    break;
                }
                ptr++;
            }
        }
        if (validInput) {
            break; /* If valid input, exit the loop. */
        } else {
            set_color("RED"); /* Set text color to red for error message. */
            printf("Invalid input. Please enter a positive integer.\n"); /** Print an error message. */
            set_color("LIGHTCYAN"); /* Set text color back to light cyan. */
        }
    }
    return value; /* Return the valid positive integer. */
}
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief This function prompts the user for a positive double input. It continues to
    prompt until a valid positive double is provided. It also checks for any
    non-numeric characters in the input.
 *
 * @param prompt The prompt message to display.
 * @return The positive double entered by the user.
 */
double getPositiveDouble(const char* prompt) {
    double value; /* Declare a variable to store the user's input. */
    int validInput; /* Declare a flag to track input validity. */
    char buffer[100]; /* Assuming a reasonable maximum length for the input */
    while (1) {
        validInput = 1; /* Assume input is valid by default. */
        printf("%s", prompt); /* Print the provided prompt message. */
        if (fgets(buffer, 100, stdin) == NULL) { /*i don't use sizeof() in string because MISRA C rules does not accept this */
            continue; /* Error reading input, try again */
        }
        if (sscanf(buffer, "%lf", &value) != 1 || value <= 0) {
            validInput = 0; /* Set input validity flag to 0. */
        }
        if (validInput) {
            /* Now, we'll check if there are any non-numeric characters in the input */
            char *ptr = buffer;
            while (*ptr != '\0' && *ptr != '\n') {
                if (!isdigit(*ptr) && *ptr != '.' && *ptr != '-') {
                    validInput = 0;
                    break;
                }
                ptr++;
            }
        }

        if (validInput) {
            break; /* If valid input, exit the loop. */
        } else {
            set_color("RED"); /* Set text color to red for error message. */
            printf("Invalid input. Please enter a positive number.\n");
            set_color("LIGHTCYAN"); /* Set text color back to light cyan. */
        }
    }

    return value; /* Return the valid positive double. */
}
/**
 * This function prints customer information in a formatted table.
 * It takes a pointer to a 'customer' structure as input and prints
 * their name, date of birth, account number, address, phone number, and balance.
 *
 * @param customer A pointer to a 'customer' structure.
 */
void printCustomerInfo(account *customer) {
    printf("| %-30s | %-15s | %-15d | %-30s | %-15s | %15.2lf |\n",
           customer->name,      /*< Name of the customer. */
           customer->dob,       /*< Date of birth of the customer. */
           customer->account_number, /*< Account number. */
           customer->address,   /*< Address of the customer. */
           customer->phone_number,   /*< Phone number of the customer. */
           customer->balance);  /*< Current balance. */
}
/**
 * This function prints the header of a table displaying customer information.
 * The table includes columns for Name, Date of Birth, Account Number, Address,
 * Phone Number, and Balance.
 */
void printTableHeader() {
    set_color("YELLOW");/*function to set color you can find it in (MenuUiUi.h) file*/
    printf("| %-30s | %-15s | %-15s | %-30s | %-15s | %-15s |\n",
           "Name",              /*< Column header for Name. */
           "Date of Birth",     /*< Column header for Date of Birth. */
           "Account Number",    /*< Column header for Account Number. */
           "Address",           /*< Column header for Address. */
           "Phone Number",      /*< Column header for Phone Number. */
           "Balance");          /*< Column header for Balance. */
    set_color("LIGHTCYAN");/*function to set color you can find it in (MenuUiUi.h) file*/
}
/*---------------------------*end of file*-------------------------------------------*/


