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
void view_basket_content(g_basket basket[]);

/*
Description: Add single item to a basket
*/
void add_item(g_basket basket_array[], g_item item_array[]);

/*
Description: Removes a single item from a basket
*/
void remove_item(g_basket basket_array[], g_item item_array[]);

/*
Description: Clears buffer
*/
void flush();


#endif
