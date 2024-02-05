#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>
#include <fstream>
#include "types.h"

/*
Description: Collect input file from user
*/
void get_datafile(string& data_file);

/*
Description: Read data from the input file
*/
void read_datafile(g_item item[], int& itemFill, g_basket basket[], int& basketFill, string data_file);

/*
Description: clear input buffer
*/
void flush();

/*
void read_basket_file(string basket_file);
*/

/*
Description: Prints the main menu 
*/
void menu();

void view_basket_content(g_basket basket[], int index);


#endif
