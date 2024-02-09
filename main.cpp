#include <iostream>
#include <fstream>
#include <string>
#include "types.h"
#include "lib.h"
using namespace std;

//Description: Prompts menu
int start_message();
//Flag indicating whether there is operation done
bool done = false;

int main (){

    string item_data_file, basket_data_file;
    g_item item_list[MAX_ITEM];
    int item_fill_lvl = 0;
    g_basket basket_list[MAX_BASKET];
    int basket_fill_lvl = 0;
    int choice;

    choice = start_message();

    switch (choice)
    {
    case 1:
        get_datafile(item_data_file);
        read_item_datafile(item_list, item_fill_lvl, item_data_file);

        // get_datafile(basket_data_file);
        // read_basket_datafile(basket_list, basket_fill_lvl, basket_data_file);
        break;
    
    case 2:

        break;

    default:
        break;
    }
    

    for(int i = 0; i < item_fill_lvl; i++)
    {
        cout << item_list[i].item_index << ' '
             << item_list[i].item_weight << ' '
             << item_list[i].item_type << ' '
             << item_list[i].item_size << ' '
             << item_list[i].item_constraint << '\n';
    }

    // for(int i = 0; i < basketFillLvl; i++)
    // {
    //     cout << basket[i].basket_index << ' '
    //          << basket[i].basket_weight_limit << ' '
    //          << basket[i].basket_type << ' '
    //          << basket[i].basket_size_limit << ' '
    //          << basket[i].basket_count << ' '1
    //          << basket[i].basket_constraints << '\n';
    // }

    return 0;
}

int start_message()
{
    cout << GREEN << "\n\nWelcome to Goods Basket Planner\n\n" << WHITE;
    
    if(done)
    {
        return menu();
    } else {
        return 1;
    }
}

