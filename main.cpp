#include <iostream>
#include <fstream>
#include <string>
#include "types.h"
#include "lib.h"
using namespace std;

//Description: Prompts menu
int start_message();

int main (){

    string string_data_file, basket_data_file;
    g_item item_list[MAX_ITEM];
    int item_fill_lvl = 0;
    g_basket basket[MAX_BASKET];
    int basket_fill_lvl = 0;
    int choice

    choice = start_message();
    get_datafile(string_data_file);
    read_item_datafile(item_list, item_fill_lvl, string_data_file);

    for(int i = 0; i < item_fill_lvl; i++)
    {
        cout << item[i].item_index << ' '
             << item[i].item_weight << ' '
             << item[i].item_type << ' '
             << item[i].item_size << ' '
             << item[i].item_constraint << '\n';
    }

    // for(int i = 0; i < basketFillLvl; i++)
    // {
    //     cout << basket[i].basket_index << ' '
    //          << basket[i].basket_weight_limit << ' '
    //          << basket[i].basket_type << ' '
    //          << basket[i].basket_size_limit << ' '
    //          << basket[i].basket_count << ' '
    //          << basket[i].basket_constraints << '\n';
    // }

    return 0;
}

int start_message()
{
    cout << GREEN << "\n\nWelcome to Goods Basket Planner\n\n" << WHITE;
    return menu();
}

