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
void read_item_datafile(g_item item[], int& itemFill, string item_data_file);

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
Description: Add single item to a basket
*/
void add_item(g_basket basket_array[], g_item item_array[], int& basket_fill, int& item_fill, int basket_index, int item_index);

/*
Description: Removes a single item from a basket
*/
void remove_item(g_basket basket_array[], g_item item_array[], int& basket_fill, int& item_fill, int basket_index, int item_index);

/*
Description: Checks if item is able to go in a basket based on constraints of the basket
*/
bool check_item_type(g_basket basket, g_item item);

/*
Description: Checks if any items already in basket already
*/
bool check_item_conflict(g_basket basket, g_item item);
/*
Description: Clears buffer
*/
void flush();


#endif
