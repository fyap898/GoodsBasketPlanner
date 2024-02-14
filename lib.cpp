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
    int item_count;

    if (infile.is_open()) {
        
        while (infile >> item_count && item_count != 'E') {

            infile >> item[item_fill].item_index
                       >> item[item_fill].item_type
                       >> item[item_fill].item_weight
                       >> item[item_fill].item_size
                       >> item[item_fill].item_constraint;
            item_fill++;
            item_count--;

            if(item_count > 0)
            {
                for (int i = 0; i < item_count && item_fill < MAX_ITEM; i++) {
                    item[item_fill].item_index = item[item_fill - 1].item_index;
                    item[item_fill].item_type = item[item_fill - 1].item_type;
                    item[item_fill].item_weight = item[item_fill - 1].item_weight;
                    item[item_fill].item_size = item[item_fill - 1].item_size;
                    item[item_fill].item_constraint = item[item_fill - 1].item_constraint;
                    item_fill++;
                }
            }
        }

        infile.close();
    } else {
        cout << "Unable to open file: " << item_data_file << endl;
    }

    // if (infile.is_open()) {
    //     while (infile.eof()|| item_fill < MAX_ITEM)
    //     {
    //         infile >> basket_count >>
    //                     item[item_fill].item_index >> 
    //                     item[item_fill].item_type >>
    //                     item[item_fill].item_weight >>
    //                     item[item_fill].item_size >>
    //                     item[item_fill].item_constraint;
            
    //         if(basket_count > 1)
    //         {
    //             //decrement one bc of the first read in file
    //             basket_count--;
    //             while(basket_count > 0)
    //             {
    //                 item[item_fill + 1].item_index = item[item_fill].item_index;
    //                 item[item_fill + 1].item_type = item[item_fill].item_type;
    //                 item[item_fill + 1].item_weight = item[item_fill].item_weight;
    //                 item[item_fill + 1].item_size = item[item_fill].item_size;
    //                 item[item_fill + 1].item_constraint = item[item_fill].item_constraint;
    //                 basket_count--;
    //                 item_fill++;
    //             }
    //         } else 
    //         {
    //             item_fill++;
    //         }
    //     }
    //     infile.close();
    // } else {
    //     cout << "Unable to open file: " << item_data_file << endl;
    // }
    return;
}

void read_basket_datafile(g_basket basket[], int& basket_fill, string basket_data_file)
{
    ifstream infile(basket_data_file);
    int basket_count;
    
    infile.open(basket_data_file);

    if (infile.is_open()) {
        cout << "open\n";
        while (infile >> basket_count && basket_count != 'E') {
            cout << basket_count << endl;
            infile >> basket[basket_fill].basket_index
                       >> basket[basket_fill].basket_type
                       >> basket[basket_fill].basket_weight_limit
                       >> basket[basket_fill].basket_size_limit
                       >> basket[basket_fill].basket_constraints;  
            cout << basket[basket_fill].basket_type << endl;          
            basket[basket_fill].fillLvlItem = 0;
            basket_fill++;
            basket_count--;

            if(basket_count > 0)
            {
                for (int i = 0; i < basket_count && basket_fill < MAX_ITEM; i++) {
                    basket[basket_fill].basket_index = basket[basket_fill - 1].basket_index;
                    basket[basket_fill].basket_type = basket[basket_fill - 1].basket_type;
                    basket[basket_fill].basket_weight_limit = basket[basket_fill - 1].basket_weight_limit;
                    basket[basket_fill].basket_size_limit = basket[basket_fill - 1].basket_size_limit;
                    basket[basket_fill].basket_constraints = basket[basket_fill - 1].basket_constraints;
                    basket[basket_fill].fillLvlItem = basket[basket_fill - 1].fillLvlItem;
                    basket_fill++;
                }
            }
        }

        infile.close();
    } else {
        cout << "Unable to open file: " << basket_data_file << endl;
    }
    

}

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

void view_basket_content(g_basket basket[], int basketFill)
{
    cout << "\nDisplaying all basket's content...\n"
        << "-------------------------------------------------\n";

    for(int i = 0; i < basketFill; i++)
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

        for(int j = 0; j < basket[i].fillLvlItem; j++)
        {
            cout << basket[i].item_in_basket[j].item_index
                 << basket[i].item_in_basket[j].item_type
                 << basket[i].item_in_basket[j].item_weight
                 << basket[i].item_in_basket[j].item_size
                 << basket[i].item_in_basket[j].item_constraint << "\n";
        }
    }
}

void add_item(g_basket basket_array[], g_item item_array[], int& basket_fill, int& item_fill, int basket_index, int item_index)
{

    bool valid_item = false;
    int i = 0;

    if (basket_index < 0 || basket_index > basket_fill) {
        cout << "Invalid basket index" << endl;
        return;
    }
    if (item_index < 0 || item_index > item_fill) {
        cout << "Invalid item index" << endl;
        return;
    }

    while (i < basket_fill || valid_item == false) 
    {
        if (basket_array[i].basket_weight_limit == 0 || basket_array[i].basket_size_limit == 0) 
        {
            i++;
        }
        if (check_item_type(basket_array[i], item_array[i]) == false)
        {
            i++;
        }
        
        
    }



}

void remove_item(g_basket basket_array[], g_item item_array[], int& basket_fill, int& item_fill, int basket_index, int item_index)
{
    if (basket_index < 0 || basket_index > MAX_BASKET) {
        cout << "Invalid basket index" << endl;
        return;
    }
    if (item_index < 0 || item_index > MAX_ITEM) {
        cout << "Invalid item index" << endl;
        return;
    }
}

bool check_item_type(g_basket basket, g_item item)
{
    if ((basket.basket_constraints == "XD" && item.item_type == 'D')
        || (basket.basket_constraints == "XF" && item.item_type == 'F')
        || (basket.basket_constraints == "XM" && item.item_type == 'M')
        || (basket.basket_constraints == "XP" && item.item_type == 'P')) 
        {
            return false;
        } else {
            return true;
        }
}

bool check_item_conflict(g_basket basket, g_item item)
{
    int i = 0;

    while (i < basket.fillLvlItem)
    {
        if ((basket.item_in_basket[i].item_constraint == "XD" && item.item_type == 'D')
        || (basket.item_in_basket[i].item_constraint == "XF" && item.item_type == 'F')
        || (basket.item_in_basket[i].item_constraint == "XM" && item.item_type == 'M')
        || (basket.item_in_basket[i].item_constraint == "XP" && item.item_type == 'P')
        || (item.item_constraint == "XD" && basket.item_in_basket[i].item_type == 'D')
        || (item.item_constraint == "XF" && basket.item_in_basket[i].item_type == 'F')
        || (item.item_constraint == "XM" && basket.item_in_basket[i].item_type == 'M')
        || (item.item_constraint == "XP" && basket.item_in_basket[i].item_type == 'P'))
        {
            return false;
        } else {
            i++;
        }
        return true;
    }
    
}

void flush()
{
    char ch;

    do
    {
        cin.get(ch);
    } while (!cin.fail() && ch != '\n');

  return;
}
