#include <iostream>
#include <fstream>
#include "types.h"
#include "lib.h"
using namespace std;

//Description: Prompts menu
void start_message();

int main (){

    string data_file;
    g_item item[MAX_ITEM];
    g_basket basket[MAX_BASKET];

    start_message();
    get_datafile(data_file);
    read_datafile(item, basket, data_file);
    cout << item[0].item_constraint;

    return 0;
}

void start_message()
{
    cout << GREEN << "\n\nWelcome to Goods Basket Planner\n\n" << WHITE;
    menu();
    return;
}

