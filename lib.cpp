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
    int scanned;
    string line;

    getline(infile,line);

    if (infile.is_open()) {
        
        while (infile >> scanned && scanned != 'E') {

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

            curr->data.item_index = scanned;
            infile >> curr->data.item_type
                       >> curr->data.item_weight
                       >> curr->data.item_size
                       >> curr->data.item_constraint;
            curr->data.in_basket = false;

            item_fill++;
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
    int scanned;
    string line;

    getline(infile,line);
    
    if (infile.is_open()) {
        while (infile >> scanned && scanned != 'E') {
            basket[basket_fill].basket_index = scanned;
            infile >> basket[basket_fill].basket_weight_limit
                       >> basket[basket_fill].basket_size_limit
                       >> basket[basket_fill].basket_constraints; 
            basket[basket_fill].weight_remaining = basket[basket_fill].basket_weight_limit;
            basket[basket_fill].size_remaining = basket[basket_fill].basket_size_limit;
            basket[basket_fill].fill_lvl_item = 0;
            basket[basket_fill].item_in_basket = NULL;

            basket_fill++;
        }
        infile.close();
    } else {
        cout << "Unable to open file: " << basket_data_file << endl;
    }
    

}

// Needs to be changed if struct changes
void view_result(g_basket basket[], int basket_count, item_list* item)
{
    item_list* curr;

    cout << GREEN << "\nDisplaying all basket's content...\n" << WHITE
        << "---------------------------------------------------\n";

    for(int i = 0; i < basket_count; i++)
    {
        if(basket[i].basket_index != 0)
        {
            output_basket_info(basket[i]);

            if(basket[i].item_in_basket != NULL)
            {
        
                cout << "Items: \n"
                    << "No. | Type       | Weight | Size     | Constraint\n" 
                    << "---------------------------------------------------\n";

                curr = basket[i].item_in_basket;
                while (curr->next != NULL)
                {
                    cout << curr->data.item_index << "\t";
                    if(curr->data.item_type == Dairy)
                    {
                        cout << "Dairy\t\t";
                    } else if(curr->data.item_type == Frozen)
                    {
                        cout << "Frozen\t\t";
                    } else if(curr->data.item_type == Meat)
                    {
                        cout << "Meat\t\t";
                    } else if(curr->data.item_type == Produce)
                    {
                        cout << "Produce\t\t";
                    }
                    cout << curr->data.item_weight << "\t"
                        << curr->data.item_size << "\t";
                    if(curr->data.item_constraint == No_Dairy)
                    {
                        cout << "No Dairy\n";
                    } else if(curr->data.item_constraint == No_Frozen)
                    {
                        cout << "No Frozen\n";
                    } else if(curr->data.item_constraint == No_Meat)
                    {
                        cout << "No Meat\n";
                    } else if(curr->data.item_constraint == No_Produce)
                    {
                        cout << "No Produce\n";
                    }

                    curr = curr->next;
                }
                cout << curr->data.item_index << "\t";
                if(curr->data.item_type == Dairy)
                    {
                        cout << "Dairy\t\t";
                    } else if(curr->data.item_type == Frozen)
                    {
                        cout << "Frozen\t\t";
                    } else if(curr->data.item_type == Meat)
                    {
                        cout << "Meat\t\t";
                    } else if(curr->data.item_type == Produce)
                    {
                        cout << "Produce\t\t";
                    }
                cout << curr->data.item_weight << "\t"
                    << curr->data.item_size << "\t";
                if(curr->data.item_constraint == No_Dairy)
                {
                    cout << "No Dairy\n";
                } else if(curr->data.item_constraint == No_Frozen)
                {
                    cout << "No Frozen\n";
                } else if(curr->data.item_constraint == No_Meat)
                {
                    cout << "No Meat\n";
                } else if(curr->data.item_constraint == No_Produce)
                {
                    cout << "No Produce\n";
                }

                    cout <<"---------------------------------------------------\n"
                        << endl;
            } else {
                cout << "---------------------------------------------------\n\n"
                     << RED << "\t---No Item Added---\n\n" << WHITE
                     << "---------------------------------------------------\n\n";
            }
        }
    }

    output_item_not_in_basket(item);
}

void output_basket_info(g_basket basket)
{
    cout << BLUE << "Basket Index: " << WHITE << basket.basket_index << "\n"
            << BLUE << "Weight Limit: " << WHITE << basket.basket_weight_limit << "\n"
            << BLUE << "Size Limit: " << WHITE << basket.basket_size_limit << "\n"
            << BLUE << "Weight Remaining: " << WHITE << basket.weight_remaining << "\n"
            << BLUE << "Size Remaining: " << WHITE << basket.size_remaining << "\n";
    
    cout << BLUE << "Constraint: " << WHITE;
    if(basket.basket_constraints == No_Dairy)
    {
        cout << "No Dairy" << "\n\n";
    } else if(basket.basket_constraints == No_Frozen)
    {
        cout << "No Frozen" << "\n\n";
    } else if(basket.basket_constraints == No_Meat)
    {
        cout << "No Meat" << "\n\n";
    } else if(basket.basket_constraints == No_Produce)
    {
        cout << "No Produce" << "\n\n";
    }
    
}

void output_item_not_in_basket(item_list* item)
{
    item_list* curr = item;
    cout << endl << endl
         << RED << "Displaying items not added into baskets...\n" << WHITE
         << "---------------------------------------------------\n\n";
    
    cout << "Items: \n"
                    << "No. | Type       | Weight | Size     | Constraint\n" 
                    << "---------------------------------------------------\n";

    while(curr != NULL)
    {
        if(!curr->data.in_basket)
        {
            cout << curr->data.item_index << "\t";
            if(curr->data.item_type == Dairy)
            {
                cout << "Dairy\t\t";
            } else if(curr->data.item_type == Frozen)
            {
                cout << "Frozen\t\t";
            } else if(curr->data.item_type == Meat)
            {
                cout << "Meat\t\t";
            } else if(curr->data.item_type == Produce)
            {
                cout << "Produce\t\t";
            }                        
            cout << curr->data.item_weight << "\t"
                << curr->data.item_size << "\t";
            if(curr->data.item_constraint == No_Dairy)
            {
                cout << "No Dairy\n";
            } else if(curr->data.item_constraint == No_Frozen)
            {
                cout << "No Frozen\n";
            } else if(curr->data.item_constraint == No_Meat)
            {
                cout << "No Meat\n";
            } else if(curr->data.item_constraint == No_Produce)
            {
                cout << "No Produce\n";
            }
        }
        curr = curr->next;
    }
    cout << "---------------------------------------------------\n\n";
    return;

}

//
void knapsack(g_basket basket[], item_list* item, int basket_counter, int basket_fill, int item_fill)
{    
    if(item == NULL)
    {
        return;
    }
    if(item_fill == 0)
    {
        return;
    }
    if(basket_counter == basket_fill)
    {
        //no baskets suit the item
        return knapsack(basket, item->next, 0, basket_fill, --item_fill);
    }

    if(!item->data.in_basket)
    {
        if(!check_basket_item_conflict(basket[basket_counter],item->data) && !check_item_conflict(basket[basket_counter].item_in_basket,item->data))
        {
            if(basket[basket_counter].weight_remaining >= item->data.item_weight &&
               basket[basket_counter].size_remaining >= item->data.item_size)
               {
                    insertion(basket[basket_counter].item_in_basket, item->data);
                    item->data.in_basket = true;
                    basket[basket_counter].weight_remaining -= item->data.item_weight;
                    basket[basket_counter].size_remaining -= item->data.item_size;
                    return knapsack(basket, item->next, 0, basket_fill, --item_fill);
               } else
               {
                    return knapsack(basket, item, basket_counter + 1, basket_fill, item_fill);
               }
            
        } else
        {
            return knapsack(basket, item, basket_counter + 1, basket_fill, item_fill);
        }
    } else
    {
        return knapsack(basket, item->next, basket_counter, basket_fill, --item_fill);
    }
}

bool check_basket_item_conflict(g_basket basket, g_item item)
{
    if ((basket.basket_constraints == No_Dairy && item.item_type == Dairy) ||
        (basket.basket_constraints == No_Frozen && item.item_type == Frozen) ||
        (basket.basket_constraints == No_Meat && item.item_type == Meat) ||
        (basket.basket_constraints == No_Produce && item.item_type == Produce)) 
        {
            //conflict
            return true;
        } else {
            return false;
        }
}

bool check_item_conflict(item_list* head, g_item item)
{
    item_list* curr = head;
    if(curr == NULL) //Nothing in the list
    {
        return false;

    } else if(curr->next == NULL) //one item in the list
    {
        if((curr->data.item_constraint == No_Dairy && item.item_type == Dairy) ||
            (curr->data.item_constraint == No_Frozen && item.item_type == Frozen) ||
            (curr->data.item_constraint == No_Meat && item.item_type == Meat) ||
            (curr->data.item_constraint == No_Produce && item.item_type == Produce) ||
            (curr->data.item_type == Dairy && item.item_constraint == No_Dairy) ||
            (curr->data.item_type == Frozen && item.item_constraint == No_Frozen) ||
            (curr->data.item_type == Meat && item.item_constraint == No_Meat) ||
            (curr->data.item_type == Produce && item.item_constraint == No_Produce))
        {
            return true;
        } else {
            return false;
        }
    }
    while (curr != NULL)
    {
        if((curr->data.item_constraint == No_Dairy && item.item_type == Dairy) ||
            (curr->data.item_constraint == No_Frozen && item.item_type == Frozen) ||
            (curr->data.item_constraint == No_Meat && item.item_type == Meat) ||
            (curr->data.item_constraint == No_Produce && item.item_type == Produce) ||
            (curr->data.item_type == Dairy && item.item_constraint == No_Dairy) ||
            (curr->data.item_type == Frozen && item.item_constraint == No_Frozen) ||
            (curr->data.item_type == Meat && item.item_constraint == No_Meat) ||
            (curr->data.item_type == Produce && item.item_constraint == No_Produce))
        {
            return true;
        }

        curr = curr->next;
    }
    return false;
    
} 

void insertion(item_list*& head, g_item item)
{
    item_list* curr = head;
    item_list* pred = NULL;

    if (curr == NULL)
    {
        head = new item_list;
        curr = head;
        curr->data = item;
        curr->prev = NULL;
        curr->next = NULL;
    } else 
    {
        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = new item_list;
        pred = curr;
        curr = curr->next;
        curr->data = item;
        curr->prev = pred;
    }

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
