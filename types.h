#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

//Code for goods constraints
#define XD No_Dairy
#define XF No_Frozen
#define XM No_Meat
#define XP No_Produce

//Code for goods' type
#define D Dairy
#define F Frozen
#define M Meat
#define P Produce

#define MAX_ITEM 50
#define MAX_BASKET 50

typedef struct 
{
    int item_index;
    char item_type;
    int item_weight;
    int item_size;
    // int item_count; could remove this
    string item_constraint;
}g_item;

typedef struct 
{
    int basket_index;
    char basket_type;
    int basket_weight_limit;
    int basket_size_limit;
    // int basket_count; // could remove this
    string basket_constraints;
    g_item item_in_basket[];
}g_basket;

#endif
