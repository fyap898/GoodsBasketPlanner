#include "lib.h"

void get_datafile(string& data_file)
{
    fstream infile;
    cout << GREEN << "\nEnter Info (file.txt)\n" << WHITE;
    cin >> data_file;

    infile.open(data_file);

    while(!infile.is_open())
    {
        cout << RED << "\t---ERROR FILE INPUT---\n\n";
        cout << GREEN << "Enter Info (file.txt)\n" << WHITE;
        cin >> data_file;
        infile.open(data_file);
    }

    infile.close();
}

void read_item_datafile(g_item item[], int& item_fill, string item_data_file)
{
    ifstream infile(item_data_file);
    char scanned = '\0';
    // int i = 0;
    bool done_read = false;

    infile.open(item_data_file);

    if (infile.is_open()) {
        while (infile >> item[item_fill].item_index >> 
                        item[item_fill].item_type >>
                        item[item_fill].item_weight >>
                        item[item_fill].item_size >>
                        item[item_fill].item_constraint)
        {
            item_fill++;
        }
    }
    infile.close();
    return;
}

// void read_basket_datafile(g_basket basket[], int& basket_fill, string basket_data_file)
// {
//     ifstream infile;
//     int i = 0;

//     infile.open(basket_file);

//     while (in >> baskets[i].basket_index >> 
//                  baskets[i].basket_type >>
//                  baskets[i].basket_weight_limit >>
//                  baskets[i].basket_size_limit >>
//                  baskets[i].basket_constraints)
//     {
//         basketFill++;
//     }

// }



int menu()
{
    int choice;

    cout << GREEN << "Enter a number to make a choice\n";
    cout << "1. Plan organization of goods in basket(s)\n";
    cout << "2. View current basket(s) organization\n";
    cout << "3. Quit\n\n" << WHITE;

    cin >> choice;

    return choice;
} 

void view_basket_content(g_basket basket[], int index)
{

}

// void put_good_in_basket()
