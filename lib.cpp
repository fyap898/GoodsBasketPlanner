#include "lib.h"

void get_datafile(string& data_file, char indicator)
{
    fstream infile;

    if(indicator == 'I')
    {
        cout << GREEN << "\nEnter Item Data File (file.txt)\n" << WHITE;
    } else if (indicator == 'B')
    {
        cout << GREEN << "\nEnter Basket Data File (file.txt)\n" << WHITE;
    }
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



    if (infile.is_open()) {
        while (infile >> item[item_fill].item_index >> 
                        item[item_fill].item_type >>
                        item[item_fill].item_weight >>
                        item[item_fill].item_size >>
                        item[item_fill].item_constraint || item_fill > MAX_ITEM)
        {
            cout << "1\n";
            item_fill++;
        }
        infile.close();
    } else {
        cout << "Unable to open file: " << item_data_file << endl;
    }
    return;
}

// void read_basket_datafile(g_basket basket[], int& basket_fill, string basket_data_file)
// {
//     ifstream infile;
//     
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

void view_basket_content(g_basket basket[])
{
    cout << "\nDisplaying all basket's content...\n"
        << "-------------------------------------------------\n";

    for(int i = 0; i < basket[i].fillLvl; i++)
    {
        cout << "Basket Index: " << basket[i].basket_index << "\n"
             << "Weight Limit: " << basket[i].basket_weight_limit << "\n"
             << "Size Limit: " << basket[i].basket_size_limit << "\n";

        if(basket[i].basket_type == 'D')
        {
            cout << "Type: Dairy\n";
        } else if(basket[i].basket_type == 'F')
        {
            cout << "Type: Frozen\n";
        } else if(basket[i].basket_type == 'M')
        {
            cout << "Type: Meat\n";
        } else if(basket[i].basket_type == 'P')
        {
            cout << "Type: Produce\n";
        }
        
        if(basket[i].basket_constraints == "XD")
        {
            cout << "Constraint: " << basket[i].basket_constraints << "\n\n";
        } else if(basket[i].basket_constraints == "XF")
        {
            cout << "Constraint: " << basket[i].basket_constraints << "\n\n";
        } else if(basket[i].basket_constraints == "XM")
        {
            cout << "Constraint: " << basket[i].basket_constraints << "\n\n";
        } else if(basket[i].basket_constraints == "XP")
        {
            cout << "Constraint: " << basket[i].basket_constraints << "\n\n";
        }
    
        cout << "Items: \n"
             << "No. | Type\t| Weight | Size | Constraint\n" 
             << "-------------------------------------------------\n";

        for(int j = 0; j < basket[i].fillLvl; j++)
        {
            cout << basket[i].item_in_basket[j].item_index
                 << basket[i].item_in_basket[j].item_type
                 << basket[i].item_in_basket[j].item_weight
                 << basket[i].item_in_basket[j].item_size
                 << basket[i].item_in_basket[j].item_constraint << "\n";
        }
    }
}

void add_item(g_basket basket_array[], g_item item_array[])
{

}

void remove_item(g_basket basket_array[], g_item item_array[])
{

}

