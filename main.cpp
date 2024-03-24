#include <iostream>
#include <fstream>
#include <string>
#include "types.h"
#include "lib.h"
using namespace std;

//Description: Prompts menu
void start_message();

//Description: Prompts exit message
void exit_message();

int main ()
{
    string item_data_file, basket_data_file;
    item_list* item_list_ptr;
    item_list* item_head_ptr;
    int item_fill_lvl = 0;
    g_basket basket_list[MAX_BASKET];
    item_list* basket_item_headptr;
    int basket_fill_lvl = 0;
    int choice;

    g_basket testBasket[1];

    testBasket[0].basket_index = 1;
    testBasket[0].basket_weight_limit = 10;
    testBasket[0].basket_size_limit = 20;
    testBasket[0].basket_constraints = "XM";
    testBasket[0].fill_lvl_item = 3;
    testBasket[0].item_in_basket = new item_list;
    
    item_list* test = new item_list;
    item_list* curr = test;

    curr->data.item_index = 0;
    curr->data.item_type = 'P';
    curr->data.item_weight = 5;
    curr->data.item_size = 2;
    curr->data.item_constraint = "XD";
    curr->next = new item_list;
    curr = curr->next;

    curr->data.item_index = 1;
    curr->data.item_type = 'M';
    curr->data.item_weight = 4;
    curr->data.item_size = 6;
    curr->data.item_constraint = "XF";
    curr->next = new item_list;
    curr = curr->next;

    curr->data.item_index = 2;
    curr->data.item_type = 'F';
    curr->data.item_weight = 10;
    curr->data.item_size = 10;
    curr->data.item_constraint = "XM";
    curr->next = new item_list;
    curr = curr->next;

    curr->data.item_index = 3;
    curr->data.item_type = 'D';
    curr->data.item_weight = 2;
    curr->data.item_size = 4;
    curr->data.item_constraint = "XP";
    curr->next = NULL;

    item_list* test2 = new item_list;
    test2->data.item_index = 100;
    test2->data.item_type = 'D';
    test2->data.item_weight = 10;
    test2->data.item_size = 10;
    test2->data.item_constraint = "XP";

    item_list* test3 = NULL;
    g_item item;
    item.item_index = 1000;
    item.item_type = Frozen;
    item.item_constraint = No_Produce;


    cout << test3 << endl;
    insertion(test3,item);
    cout << test3->data.in_basket << endl;
    cout << test3 << endl;
    insertion(test3, item);
    cout << test3 << endl;

    cout << test3->data.item_index << ' '
    << test3->data.item_type << ' '
    << test3->data.item_constraint << endl;

    cout << test3 << endl;
    if(check_basket_item_conflict(testBasket[0], test2->data))
    {
        cout << "conflict\n";
    } else {
        cout << "no\n";
    }

    start_message();
    cin >> choice;

    while(choice != 0)
    {
        get_datafile(item_data_file, 'I');
        item_list_ptr = read_item_datafile(item_fill_lvl, item_data_file);

        get_datafile(basket_data_file, 'B');
        read_basket_datafile(basket_list, basket_fill_lvl, basket_data_file);

        //0 is the array index, starting from index 0
        knapsack(basket_list, item_list_ptr, 0, basket_fill_lvl, item_fill_lvl);

        view_result(basket_list, basket_fill_lvl, item_list_ptr);

        start_message();
        cin >> choice;
    }

    

    exit_message();


    return 0;
}

void start_message()
{
    cout << MAGENTA << "\n\nWelcome to Goods Basket Planner\n\n" 
         << "(1) Start the program\n"
         << "(0) Exit\n\n"
         << WHITE << "Choice: ";
}

void exit_message()
{
    cout << "\nThank you for using Goods and Baskets Planner\n\n";
}

