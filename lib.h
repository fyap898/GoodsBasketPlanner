#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "types.h"

/*
Description: Collect input file from user
*/
void get_datafile(string& data_file, char indicator);

/*
Description: Read data from the item's input file
*/
item_list* read_item_datafile(int& item_fill, string item_data_file);

/*
Description: Read data from the basket's input file
*/
void read_basket_datafile(g_basket basket[], int& basket_fill, string basket_data_file);

/*
Description: Display basket's content
*/
void view_result(g_basket basket[], int basketFill, item_list* item);

/*
Description: Output basket's info
*/
void output_basket_info(g_basket basket);

/*
Description: Display items that are not added / doesnt fit to baskets
*/
void output_item_not_in_basket(item_list* item);

/*
Description: Add single item to a basket
*/
void knapsack(g_basket basket[], item_list* item, int basket_counter, int basket_fill, int item_fill);

/*
Description: Checks if item is able to go in a basket based on constraints of the basket
*/
bool check_basket_item_conflict(g_basket basket, g_item item);

/*
Description: Checks if any items already in basket already
*/
bool check_item_conflict(item_list* head, g_item item);

/*
Description: Insert item into the end of the list
*/
void insertion(item_list*& head, g_item item);

/*
Description: Delete item from anywhere in the list
*/
void deletion(item_list*& basket, item_list*& item);

/*
Description: Clears buffer
*/
void flush();


#endif
