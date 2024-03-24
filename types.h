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
#define No_Dairy "XD"
#define No_Frozen "XF"
#define No_Meat "XM"
#define No_Produce "XP"

//Code for goods' type
#define Dairy 'D'
#define Frozen 'F'
#define Meat 'M'
#define Produce 'P'

#define MAX_ITEM 50
#define MAX_BASKET 50

//Item struct
typedef struct
{
    int item_index;
    char item_type;
    int item_weight;
    int item_size;
    string item_constraint;
    bool in_basket;
}g_item;

//Nodes for doubly linked list
struct item_list
{
    item_list *next;
    item_list *prev;
    g_item data;
};

typedef struct 
{
    int basket_index;
    int basket_weight_limit;
    int weight_remaining;
    int basket_size_limit;
    int size_remaining;
    string basket_constraints;
    int fill_lvl_item;

    //pointing at head node
    item_list* item_in_basket;
}g_basket;



#endif
