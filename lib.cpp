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

    infile.open(data_file.c_str());

    while(!infile.is_open())
    {
        cout << RED << "\t---ERROR FILE INPUT---\n\n";
        cout << GREEN << "Enter Info (file.txt)\n" << WHITE;
        cin >> data_file;
        infile.open(data_file.c_str());
    }

    infile.close();
}

item_list* read_item_datafile(int& item_fill, string item_data_file)
{
    ifstream infile(item_data_file.c_str());
    item_list* head = NULL;
    item_list* curr;
    item_list* pred;
    int item_count;

    if (infile.is_open()) {
        
        while (infile >> item_count && item_count != 'E') {

            if(head == NULL)
            {
                head = new item_list;
                curr = head;
                curr->next = NULL;
                curr->prev = NULL;
            } else {
                pred = curr;
                curr->next = new item_list;
                curr = curr->next;
                curr->next = NULL;
                curr->prev = pred;
            }

            infile >> curr->data.item_index
                       >> curr->data.item_type
                       >> curr->data.item_weight
                       >> curr->data.item_size
                       >> curr->data.item_constraint;
            curr->data.in_basket = false;

            item_fill++;
            item_count--;

            if(item_count > 0)
            {
                for (int i = 0; i < item_count && item_fill < MAX_ITEM; i++) {
                    pred = curr;
                    curr->next = new item_list;
                    curr = curr->next;
                    curr->next = NULL;
                    curr->prev = pred;

                    curr->data.item_index = pred->data.item_index;
                    curr->data.item_type = pred->data.item_type;
                    curr->data.item_weight = pred->data.item_weight;
                    curr->data.item_size = pred->data.item_size;
                    curr->data.item_constraint = pred->data.item_constraint;
                    curr->data.in_basket = false;
                    item_fill++;
                }
            }
        }

        infile.close();
        return head;
    } else {
        cout << "Unable to open file: " << item_data_file << endl;
        return NULL;
    }
}

void read_basket_datafile(g_basket basket[], int& basket_fill, string basket_data_file)
{
    ifstream infile(basket_data_file.c_str());
    int basket_count;
    
    if (infile.is_open()) {
        while (infile >> basket_count && basket_count != 'E') {
            infile >> basket[basket_fill].basket_index
                       >> basket[basket_fill].basket_type
                       >> basket[basket_fill].basket_weight_limit
                       >> basket[basket_fill].basket_size_limit
                       >> basket[basket_fill].basket_constraints;  
            basket[basket_fill].fill_lvl_item = 0;
            basket[basket_fill].item_in_basket = NULL;
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
                    basket[basket_fill].fill_lvl_item = basket[basket_fill - 1].fill_lvl_item;
                    basket[basket_fill].item_in_basket = NULL;
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
void view_basket_content(g_basket basket[], int basket_count)
{
    item_list* curr;

    cout << "\nDisplaying all basket's content...\n"
        << "-------------------------------------------------\n";

    for(int i = 0; i < basket_count; i++)
    {
        if(basket[i].basket_index != 0)
        {
            output_basket_info(basket[i]);
        
            cout << "Items: \n"
                << "No. | Type   | Weight     | Size     | Constraint\n" 
                << "-------------------------------------------------\n";

            curr = basket[i].item_in_basket;
            
            while (curr->next != NULL)
            {
                cout << curr->data.item_index << "\t"
                    << curr->data.item_type << "\t\t"
                    << curr->data.item_weight << "\t\t\t"
                    << curr->data.item_size << "\t\t"
                    << curr->data.item_constraint << "\n";
                
                curr = curr->next;
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

void add_item(g_basket basket, int& basket_fill, int& item_fill, item_list* item)
{
    if (basket.basket_size_limit == 0 || basket.basket_weight_limit == 0)
    {
        cout << "Basket Full" << endl;
        return;
    }
    if (check_item_type(basket, item) || check_item_conflict(basket.item_in_basket, item))
    {
        cout << "Item Conflict" << endl;
        return;
    }
    if (item->data.in_basket == true)
    {
        cout << "Item already in bag" << endl;
        return;
    }
    insertion(basket.item_in_basket, item);

    basket.basket_size_limit -= item->data.item_size;
    basket.basket_weight_limit -= item->data.item_weight;
    item_fill--;
    if (basket.basket_size_limit == 0 || basket.basket_weight_limit == 0)
    {
        basket_fill--;
    }
    return;
}

void remove_item(g_basket basket, int& basket_fill, int& item_fill, item_list* item) 
{

    // int i = 0;
    // // item_list* head_pointer = basket_array[basket_index]->item_in_basket;

    // if (basket_index < 0 || basket_index > MAX_BASKET) {
    //     cout << "Invalid basket index" << endl;
    //     return;
    // }
    // if (item_index < 0 || item_index > MAX_ITEM) {
    //     cout << "Invalid item index" << endl;
    //     return;
    // }

    // // If a full basket has an item removed, it becomes available to be in use again.
    // if (basket_array[basket_index].basket_weight_limit == 0 || basket_array[basket_index].basket_size_limit == 0)
    // {
    //     basket_fill++;
    // }
    // // if (basket_array[basket_index].item_list) 
    // // {
    // //     /* code */
    // // }
    

    // // item_fill++;

}

bool check_item_type(g_basket basket, item_list* item)
{
    if ((basket.basket_constraints == "XD" && item->data.item_type == 'D')
        || (basket.basket_constraints == "XF" && item->data.item_type == 'F')
        || (basket.basket_constraints == "XM" && item->data.item_type == 'M')
        || (basket.basket_constraints == "XP" && item->data.item_type == 'P')) 
        {
            return true;
        } else {
            return false;
        }
}

bool check_item_conflict(item_list* head, item_list* item)
{
    item_list* curr = head;

    while (curr->next != NULL)
    {
        if ((curr->data.item_constraint == "XD" && item->data.item_type == 'D')
            || (curr->data.item_constraint == "XF" && item->data.item_type == 'F')
            || (curr->data.item_constraint == "XM" && item->data.item_type == 'M')
            || (curr->data.item_constraint == "XP" && item->data.item_type == 'P')
            || (curr->data.item_type == 'D' && item->data.item_constraint == "XD")
            || (curr->data.item_type == 'F' && item->data.item_constraint == "XF")
            || (curr->data.item_type == 'M' && item->data.item_constraint == "XM")
            || (curr->data.item_type == 'P' && item->data.item_constraint == "XP")) 
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
    
} 

void insertion(item_list*& head, item_list*& item)
{
    item_list* curr = head;
    // item_list* pred = NULL;
    item_list* new_item = new item_list;

    new_item->data = item->data;
    new_item->next = NULL;

    if (head == NULL)
    {
        new_item->prev = NULL;
        head = new_item;
        return;
    }

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = new_item;
    new_item->prev = curr;
    item->data.in_basket = true;

    return;

}

void deletion(item_list*& basket, item_list*& item)
{
    
    if (basket == NULL)
    {
	return;
    }

    item_list* curr = basket;
    while (curr != NULL)
    {
	if (curr->data.item_index == item->data.item_index)
	{
	    if (curr == basket)
	    {
		basket = curr->next;
	    }

	    if (curr->prev != NULL)
	    {
		curr->prev->next = curr->next;
	    }

	    if (curr->next != NULL)
	    {
		curr->next->prev = curr->prev;
	    }

	    delete curr;
	    return;
	}
	curr = curr->next;
    }
    

}


void flush()
{
    char ch;

    do
    {
        cin.get(ch);
    } while (!cin.fail() && ch != '\n');

}
