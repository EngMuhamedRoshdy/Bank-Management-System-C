/*--------------------------------------------------------------------*/
/* [FILE NAME]:<Bank.h>
   [Author]:<Eng.Muhammad Ahmed Roshdy >
   [Date]: <25-9-2023>
   [Project]: <Bank Management system >
*/
/*---------------------------------------------------------------------*/
/*-------------------------*INCLUDES HERE*-----------------------------*/
#ifndef BANK_H
#define BANK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*--------------------------*STRUCTURE HERE*-----------------------------*/
/*------------------------------------------------------------------------
 * Structure representing a transaction. This defines a linked list node
 * for storing transaction information.
 */
typedef struct Transaction {
    char date[12];              /*< Date of the transaction. */
    double amount;              /*< Amount of the transaction. */
    struct Transaction* next;   /*< Pointer to the next transaction in the list. */
} Transaction;
/*----------------------------------------------------------------------- */
/*--------------------- Comment: Linked List Node ------------------------
 *
 * The structure 'Transaction' represents a single transaction. It contains
 * three fields:
 *
 * 1. 'date': An array of characters representing the date of the transaction.
 * 2. 'amount': A double representing the amount of the transaction.
 * 3. 'next': A pointer to the next transaction in the list, forming a linked list.
 *
 * In this linked list implementation, each 'Transaction' node contains its
 * own data and a pointer ('next') to the next transaction node. This allows
 * for the creation of a dynamic list where each transaction points to the
 * next one in the sequence. This is a common way to organize transaction data.
 *
 *----------------------------------------------------------------------- */
/*------------------------- End of Linked List Node ----------------------*/
/*-----------------------------------------------------------------------

 * Structure representing an account. This defines a node for storing
 * customer account information in a binary search tree.
 */
typedef struct Customer {
    char name[50];              /*< Name of the customer. */
    char dob[12];               /*< Date of birth of the customer. */
    int account_number;         /*< Account number. */
    char address[100];          /*< Address of the customer. */
    char phone_number[15];      /*< Phone number of the customer. */
    double balance;             /*< Current balance. */
    Transaction* transactions;  /*< Pointer to the first transaction in the list. */
    struct Customer* left;      /*< Pointer to left child node. */
    struct Customer* right;     /*< Pointer to right child node. */
} account;
/*----------------------------------------------------------------------- */
/*--------------------- Comment: Binary Search Tree Node -----------------
 *
 * The structure 'Customer' represents a single node in a binary search tree
 * for storing customer account information. Each node contains the following
 * fields:
 *
 * 1. 'name': An array of characters representing the name of the customer.
 * 2. 'dob': An array of characters representing the date of birth of the customer.
 * 3. 'account_number': An integer representing the account number.
 * 4. 'address': An array of characters representing the address of the customer.
 * 5. 'phone_number': An array of characters representing the phone number of the customer.
 * 6. 'balance': A double representing the current balance.
 * 7. 'transactions': A pointer to the first transaction in the list.
 * 8. 'left': A pointer to the left child node.
 * 9. 'right': A pointer to the right child node.
 *
 * This structure is designed for use in a binary search tree where each node
 * represents a customer account. The binary search tree property ensures that
 * at any node, the left child node will have an account number less
 * than the current node, and the right child node will have an account number
 * greater than the current node. This allows for efficient searching
 * and retrieval based on account numbers.
 *
 *----------------------------------------------------------------------- */
/*------------------End of Binary Search Tree Node -----------------------*/
/*------------------------------------------------------------------------*/
/*---------------------  Functions Prototypes ----------------------------*/
/**
 * Initializes a customer structure with default values.
 *
 * @param customer A pointer to the customer structure to be initialized.
 */
void initializeCustomer(account* customer);
/*---------------------------------------------------------------------------------------------*/
/**
 * Initialize a transaction node.
 *
 * @param transaction A pointer to the transaction node to be initialized.
 */
void initializeTransaction(Transaction* transaction);
/*---------------------------------------------------------------------------------------------*/
/**
 * Function to create a new customer account.
 *
 * @param root The root of the customer binary tree.
 * @return A pointer to the newly created customer account.
 */
/*---------------------------------------------------------------------------------------------*/
account* createCustomer(account* root);
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
account* insertCustomer(account* root, account* newCustomer);
/*---------------------------------------------------------------------------------------------*/
/**
 * "Wrapper" function to delete a customer by account number.
 *
 * @param root A pointer to the root of the customer binary tree.
 * @param account_number The account number of the customer to be deleted.
 */
account* Del_Cstmr(account* root, int account_number);
/*---------------------------------------------------------------------------------------------*/
/**
 * "Wrapper" function to delete a customer by account number.
 *
 * @param root A pointer to the root of the customer binary tree.
 * @param account_number The account number of the customer to be deleted.
 */
void Delete_Customer(account** root, int account_number);
/*---------------------------------------------------------------------------------------------*/
/**
 * Search for a customer node by account number.
 *
 * @param root The root of the customer binary tree.
 * @param account_number The account number to search for.
 * @return A pointer to the customer node if found, otherwise NULL.
 */
account* searchCustomer(account* root, int account_number);
/*---------------------------------------------------------------------------------------------*/
/**
 * Update customer information.
 *
 * @param customer A pointer to the customer to be updated.
 * @param account_to_edit The account number of the customer to be updated.
 * @param root The root of the customer binary tree.
 */
void updateCustomer(account* customer, int account_to_edit, account* root);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief "helper function" Compare function for sorting customers by names.
 *
 * @param x A pointer to the first customer.
 * @param y A pointer to the second customer.
 * @return An integer less than, equal to, or greater than zero if the first customer
 *         is found to be less than, equal to, or greater than the second customer.
 */
int compare(const void* x, const void* y);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Helper function to populate customers array and count (in-order traversal).
 *
 * @param root The root of the customer binary tree.
 * @param customers An array to store customer pointers.
 * @param count A pointer to the count of customers.
 */
void Customer_list_sort(account* root, account* customers[], int* count);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Function to display the customer list in ascending order by name.
 *
 * @param root The root of the customer binary tree.
 */
void CustomerDisplayList(account* root);
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
void addTransaction(Transaction** transactions, char* date, double amount);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Function to display the list of transactions for a given customer.
 *
 * @param customer A pointer to the customer node.
 */
void displayTransactions(account* customer);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Function to get the current date in YYYY-MM-DD format.
 *
 * @param date Pointer to a character array where the date will be stored.
 */
void getCurrentDate(char* date);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Function to perform a transaction (deposit or withdrawal).
 *
 * @param root The root of the customer binary tree.
 */
void performTransaction(account* root);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Function to view account transactions.
 *
 * @param root A pointer to the root of the customer binary tree.
 */
void viewAccountTransactions(account* root);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Function to get a positive double input with a specified prompt message.
 *
 * @param prompt The prompt message to display.
 * @return The positive double entered by the user.
 */
double getPositiveDouble(const char* prompt);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Function to get a string input with specified maximum length and prompt message.
 *
 * @param str Pointer to the string where the input will be stored.
 * @param maxLen Maximum length of the input string.
 * @param prompt The prompt message to display.
 */
 void getOnlyString(char* str, size_t maxLen, const char* prompt);
/*-----------------------------------------------------------------------*/
/**
 * @brief Function to get a positive integer input with a specified prompt message.
 *
 * @param prompt The prompt message to display.
 * @return The positive integer entered by the user.
 */
 int getPositiveInt(const char* prompt);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Function to free memory (called when exiting the program).
 *
 * @param root The root of the customer binary tree.
 */
void freeMemory(account* root);
/**
 * This function prints customer information in a formatted table.
 * It takes a pointer to a 'customer' structure as input and prints
 * their name, date of birth, account number, address, phone number, and balance.
 *
 * @param customer A pointer to a 'customer' structure.
 */
void printCustomerInfo(account *customer);
/**
 * This function prints the header of a table displaying customer information.
 * The table includes columns for Name, Date of Birth, Account Number, Address,
 * Phone Number, and Balance.
 */
void printTableHeader();
#endif /* BANK_H_INCLUDED*/
