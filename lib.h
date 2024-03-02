/*
    Group Members: Andrew Phan, Felix Yap
    Course: COMP 3649: Programming Paradigms
    File Name: lib.h
    Instructor's Name: Marc Schroeder
    Due Date: April 5, 2024

    Description: File contains all main functions used in main program such as add and subtract operations, 
    I/O operations, etc.

    Details: Currently reading of files, addition of nodes, and type checks are all working.
             Main sorting function does not work yet.
             Might not use remove_item
*/

#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>
#include <fstream>
#include "types.h"

/*
Description: Collect input file from user
*/
void get_datafile(string& data_file, char indicator);

/*
Description: Read data from the item's input file
*/
item_list* read_item_datafile(int& itemFill, string item_data_file);

/*
Description: Read data from the basket's input file
*/
void read_basket_datafile(g_basket basket[], int& basketFill, string basket_data_file);

/*
Description: Prints the main menu 
*/
int menu();

/*
Description: Display basket's content
*/
void view_basket_content(g_basket basket[], int basketFill);

/*
Description: Output basket's info
*/
void output_basket_info(g_basket basket);

/*
Description: Add single item to a basket
*/
void add_item(g_basket basket, int& basket_fill, int& item_fill, item_list* item);

/*
Description: Removes a single item from a basket
*/
void remove_item(g_basket basket_array[], g_item item_array[], int& basket_fill, int& item_fill, int basket_index, int item_index);

/*
Description: Checks if item is able to go in a basket based on constraints of the basket
*/
bool check_item_type(g_basket basket, item_list* item);

/*
Description: Checks if any items already in basket already
*/
bool check_item_conflict(item_list* head, item_list* item);

/*
Description: Insert item into the end of the list
*/
void insertion(item_list*& head, item_list*& item);

/*
Description: Delete item from anywhere in the list
*/
void deletion(item_list*& basket, item_list*& item);

/*
Description: Clears buffer
*/
void flush();


#endif
