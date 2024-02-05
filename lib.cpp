#include "lib.h"

void get_datafile(string& data_file)
{
    fstream infile;
    cout << GREEN << "Enter Info (file.txt)\n" << WHITE;
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

void read_item_datafile(g_item item[], int& itemFill, string item_data_file)
{
    ifstream infile;
    char scanned = '\0';
    // int i = 0;
    bool done_read = false;

    infile.open(item_data_file);

    while (infile >> item[i].item_index >> 
                 item[i].item_type >>
                 item[i].item_weight >>
                 item[i].item_size >>
                 item[i].item_count >>
                 item[i].item_constraint)
    {
        itemFill++;
    }

        // infile >> item[i].item_index;
        // infile >> item[i].item_weight;
        // infile >> item[i].item_type;
        // infile >> item[i].item_size;
        // infile >> item[i].item_count;
        // infile >> item[i].item_constraint;
    
    infile.close();
    return;
}

// void read_basket_file(g_basket basket[], int& basketFill, string basket_data_file);
// {
//     ifstream infile;
//     int i = 0;

//     infile.open(basket_file);

//     while (in >> baskets[i].basket_index >> 
//                  baskets[i].basket_type >>
//                  baskets[i].basket_weight_limit >>
//                  baskets[i].basket_size_limit >>
//                  baskets[i].basket_count >>
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
    cout << "3. Quit\n" << WHITE;

    cin >> choice;

    return choice;
} 


void put_good_in_basket()
