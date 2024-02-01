#ifndef LIB_H
#define LIB_H

#include "types.h"

/*
Description: Collect input file from user
*/
void get_datafile(string& data_file);

/*
Description: Read data from the input file
*/
void read_datafile(g_item item[], g_basket basket[], string data_file);

/*
void read_basket_file(string basket_file);
*/

/*
Description: Prints the main menu 
*/
void menu();
#endif
