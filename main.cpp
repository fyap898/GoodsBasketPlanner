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
    item_list* item_list_ptr;
    item_list* item_head_ptr;
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
    // testBasket[0].fill_lvl_item = 2;

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

    // testBasket[0].item_in_basket[0] = testBasket[0].item_in_basket[1];
    

    // view_basket_content(testBasket, testBasket[0].fill_lvl_item);

    // const int fillTest = 10;
    // int test[fillTest];

    // for(int i = 0; i < fillTest; i++)
    // {
    //     test[i] = i + 1;
    // }

    // shift_for_remove(test, 5, fillTest);

    // int newFill = fillTest;

    // for(int i = 0; i < newFill; i++)
    // {
    //     cout << test[i] << endl;
    // }

    switch (choice)
    {
    case 1:
        get_datafile(item_data_file, 'I');
        item_list_ptr = read_item_datafile(item_fill_lvl, item_data_file);
        item_head_ptr = item_list_ptr;

        get_datafile(basket_data_file, 'B');
        read_basket_datafile(basket_list, basket_fill_lvl, basket_data_file);
        break;
    
    case 2:

        break;

    default:
        break;
    }

    // for(int i = 0; i < item_fill_lvl && item_head_ptr != nullptr; i++)
    // {
    //     cout << item_head_ptr->data.item_index << ' '
    //          << item_head_ptr->data.item_weight << ' '
    //          << item_head_ptr->data.item_type << ' '
    //          << item_head_ptr->data.item_size << ' '
    //          << item_head_ptr->data.item_constraint << '\n';
        
    //     item_head_ptr = item_head_ptr->next;

    // }

    for(int i = 0; i < basket_fill_lvl; i++)
    {
        cout << basket_list[i].basket_index << ' '
             << basket_list[i].basket_type << ' '
             << basket_list[i].basket_weight_limit << ' '
             << basket_list[i].basket_size_limit << ' '
             << basket_list[i].basket_constraints << ' '
             << basket_list[i].item_in_basket << '\n';
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

