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

typedef struct 
{
    string item_name;
    char item_type;
    int item_weight;
    int item_size;
    int item_count;
    string item_constraint;
}g_item;

typedef struct 
{
    char bag_type;
    int bag_weight_limit;
    int bag_size_limit;
    int bag_count;
    string bag_constraints;
}g_bag;

#endif