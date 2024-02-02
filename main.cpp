#include <iostream>
#include <fstream>
#include <string>
#include "types.h"
#include "lib.h"
using namespace std;

//Description: Prompts menu
void start_message();

int main (){

    string data_file;
    g_item item[MAX_ITEM];
    int itemFillLvl = 0;
    g_basket basket[MAX_BASKET];
    int basketFillLvl = 0;

    start_message();
    get_datafile(data_file);
    read_datafile(item, itemFillLvl, basket, basketFillLvl, data_file);

    for(int i = 0; i < itemFillLvl; i++)
    {
        cout << item[i].item_index << ' '
             << item[i].item_weight << ' '
             << item[i].item_type << ' '
             << item[i].item_size << ' '
             << item[i].item_count << ' '
             << item[i].item_constraint << '\n';
    }

    for(int i = 0; i < basketFillLvl; i++)
    {
        cout << basket[i].basket_index << ' '
             << basket[i].basket_weight_limit << ' '
             << basket[i].basket_type << ' '
             << basket[i].basket_size_limit << ' '
             << basket[i].basket_count << ' '
             << basket[i].basket_constraints << '\n';
    }

    return 0;
}

void start_message()
{
    cout << GREEN << "\n\nWelcome to Goods Basket Planner\n\n" << WHITE;
    menu();
    return;
}

