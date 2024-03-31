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

    start_message();
    cin >> choice;
    while(choice < 0 || choice > 1)
    {
        cout << endl << RED << "\t-----Invalid Input-----\n"
             << "\t   Please Try Again" << WHITE;
        start_message();
        cin >> choice;
    }

    while(choice != 0)
    {
        get_datafile(item_data_file, 'I');
        item_list_ptr = read_item_datafile(item_fill_lvl, item_data_file);

        get_datafile(basket_data_file, 'B');
        read_basket_datafile(basket_list, basket_fill_lvl, basket_data_file);

        //0 is the array index counter, starting from index 0
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

