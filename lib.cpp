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

void read_item_datafile(itemList*& item, int& item_fill, string item_data_file)
{
    ifstream infile(item_data_file);
    itemList *head = item;
    itemList *curr = head;
    itemList *pred = nullptr;
    curr->next = nullptr;
    curr->prev = nullptr;
    int item_count;

    if (infile.is_open()) {
        
        while (infile >> item_count && item_count != 'E') {

            cout << item_count << endl;
            infile >> curr->data.item_index
                       >> curr->data.item_type
                       >> curr->data.item_weight
                       >> curr->data.item_size
                       >> curr->data.item_constraint;
            item_fill++;
            item_count--;
            
            pred = curr;
            curr = curr->next;
            curr = new itemList;
            curr->next = nullptr;
            curr->prev = pred;

            if(item_count > 0)
            {
                for (int i = 0; i < item_count && item_fill < MAX_ITEM; i++) {
                    cout << "dup\n";
                    curr->data.item_index = pred->data.item_index;
                    curr->data.item_type = pred->data.item_type;
                    curr->data.item_weight = pred->data.item_weight;
                    curr->data.item_size = pred->data.item_size;
                    curr->data.item_constraint = pred->data.item_constraint;
                    item_fill++;

                    pred = curr;
                    curr = curr->next;
                    curr = new itemList;
                    curr->next = nullptr;
                    curr->prev = pred;
                }
            }
        }

        infile.close();
    } else {
        cout << "Unable to open file: " << item_data_file << endl;
    }

    return;
}

void read_basket_datafile(g_basket basket[], int& basket_fill, string basket_data_file)
{
    ifstream infile(basket_data_file);
    int basket_count;
    
    if (infile.is_open()) {
        while (infile >> basket_count && basket_count != 'E') {
            infile >> basket[basket_fill].basket_index
                       >> basket[basket_fill].basket_type
                       >> basket[basket_fill].basket_weight_limit
                       >> basket[basket_fill].basket_size_limit
                       >> basket[basket_fill].basket_constraints;  
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

// Needs to be changed if struct changes
void view_basket_content(g_basket basket[], int basketFill)
{
    cout << "\nDisplaying all basket's content...\n"
        << "-------------------------------------------------\n";

    for(int i = 0; i < basketFill; i++)
    {
        if(basket[i].basket_index != 0)
        {
            output_basket_info(basket[i]);
        
            cout << "Items: \n"
                << "No. | Type   | Weight     | Size     | Constraint\n" 
                << "-------------------------------------------------\n";

            for(int j = 0; j < basket[i].fillLvlItem; j++)
            {
                cout << basket[i].item_in_basket[j].item_index << "\t"
                    << basket[i].item_in_basket[j].item_type << "\t\t"
                    << basket[i].item_in_basket[j].item_weight << "\t\t\t"
                    << basket[i].item_in_basket[j].item_size << "\t\t"
                    << basket[i].item_in_basket[j].item_constraint << "\n";
            }
            cout <<"-------------------------------------------------\n"
                << endl;
        }
    }
}

void output_basket_info(g_basket basket)
{
    cout << "Basket Index: " << basket.basket_index << "\n"
            << "Weight Limit: " << basket.basket_weight_limit << "\n"
            << "Size Limit: " << basket.basket_size_limit << "\n";

    cout << "Type: ";
    if(basket.basket_type == 'D')
    {
        cout << "Dairy\n";
    } else if(basket.basket_type == 'F')
    {
        cout << "Frozen\n";
    } else if(basket.basket_type == 'M')
    {
        cout << "Meat\n";
    } else if(basket.basket_type == 'P')
    {
        cout << "Produce\n";
    }
    
    cout << "Constraint: ";
    if(basket.basket_constraints == "XD")
    {
        cout << basket.basket_constraints << "\n\n";
    } else if(basket.basket_constraints == "XF")
    {
        cout << basket.basket_constraints << "\n\n";
    } else if(basket.basket_constraints == "XM")
    {
        cout << basket.basket_constraints << "\n\n";
    } else if(basket.basket_constraints == "XP")
    {
        cout << basket.basket_constraints << "\n\n";
    }
    
}

void add_item(g_basket basket_array[], g_item item_array[], int& basket_fill, int& item_fill, int basket_index, int item_index)
{

    int i = 0;

    if (basket_index < 0 || basket_index > basket_fill) {
        cout << "Invalid basket index" << endl;
        return;
    }
    if (item_index < 0 || item_index > item_fill) {
        cout << "Invalid item index" << endl;
        return;
    }
    if (basket_array[basket_index].basket_weight_limit == 0 || basket_array[basket_index].basket_size_limit == 0)
    {
        cout << "Basket is Full" << endl;
        return;
    }
    if (!check_item_conflict(basket_array[basket_index], item_array[item_index]) 
        || !check_item_type(basket_array[basket_index], item_array[item_index]))
    {
        cout << "Item Conflict" << endl;
        return;
    }

}


void remove_item(g_basket basket_array[], g_item item_array[], int& basket_fill, int& item_fill, int basket_index, int item_index) 
{

    int i = 0;
    item_list* head_pointer = basket_array[basket_index]->item_in_basket;

    if (basket_index < 0 || basket_index > MAX_BASKET) {
        cout << "Invalid basket index" << endl;
        return;
    }
    if (item_index < 0 || item_index > MAX_ITEM) {
        cout << "Invalid item index" << endl;
        return;
    }

    // If a full basket has an item removed, it becomes available to be in use again.
    if (basket_array[basket_index].basket_weight_limit == 0 || basket_array[basket_index].basket_size_limit == 0)
    {
        basket_fill++;
    }
    if (basket_array[basket_index].item_list) 
    {
        /* code */
    }
    

    // item_fill++;

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

// bool check_item_conflict(g_basket basket, g_item item)
// {
//     int i = 0;

//     while (i < basket.fillLvlItem)
//     {
//         if ((basket.item_in_basket[i].item_constraint == "XD" && item.item_type == 'D')
//         || (basket.item_in_basket[i].item_constraint == "XF" && item.item_type == 'F')
//         || (basket.item_in_basket[i].item_constraint == "XM" && item.item_type == 'M')
//         || (basket.item_in_basket[i].item_constraint == "XP" && item.item_type == 'P')
//         || (item.item_constraint == "XD" && basket.item_in_basket[i].item_type == 'D')
//         || (item.item_constraint == "XF" && basket.item_in_basket[i].item_type == 'F')
//         || (item.item_constraint == "XM" && basket.item_in_basket[i].item_type == 'M')
//         || (item.item_constraint == "XP" && basket.item_in_basket[i].item_type == 'P'))
//         {
//             return false;
//         } else {
//             i++;
//         }
//     }
//     return true;
    
// } Needs to be changed

void flush()
{
    char ch;

    do
    {
        cin.get(ch);
    } while (!cin.fail() && ch != '\n');

}
