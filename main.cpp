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

    // g_basket testBasket[2];
    // testBasket[0].basket_index = 1;
    // testBasket[0].basket_type = 'P';
    // testBasket[0].basket_weight_limit = 10;
    // testBasket[0].basket_size_limit = 20;
    // testBasket[0].basket_constraints = "XD";
    // testBasket[0].fillLvlItem = 2;

    // testBasket[0].item_in_basket[0].item_index = 1;
    // testBasket[0].item_in_basket[0].item_type = 'P';
    // testBasket[0].item_in_basket[0].item_weight = 5;
    // testBasket[0].item_in_basket[0].item_size = 2;
    // testBasket[0].item_in_basket[0].item_constraint = "XF";

    // testBasket[0].item_in_basket[1].item_index = 2;
    // testBasket[0].item_in_basket[1].item_type = 'M';
    // testBasket[0].item_in_basket[1].item_weight = 4;
    // testBasket[0].item_in_basket[1].item_size = 6;
    // testBasket[0].item_in_basket[1].item_constraint = "XD";
    

    // view_basket_content(testBasket);


    switch (choice)
    {
    case 1:
        get_datafile(item_data_file, 'I');
        read_item_datafile(item_list, item_fill_lvl, item_data_file);

        get_datafile(basket_data_file, 'B');
        read_basket_datafile(basket_list, basket_fill_lvl, basket_data_file);
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

    for(int i = 0; i < basket_fill_lvl; i++)
    {
        cout << basket_list[i].basket_index << ' '
             << basket_list[i].basket_type << ' '
             << basket_list[i].basket_weight_limit << ' '
             << basket_list[i].basket_size_limit << ' '
             << basket_list[i].basket_constraints << '\n';
    }

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

