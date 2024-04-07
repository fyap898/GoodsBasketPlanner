#include "lib.h"

void get_datafile(string& data_file, char indicator)
{
    fstream infile;

    if(indicator == 'I')
    {
        cout << GREEN << "\nEnter Item Data File (file.txt)\n" << WHITE;
        cin >> data_file;

        infile.open(data_file.c_str());

        while(!infile.is_open())
        {
            cout << RED << "\t---ERROR FILE INPUT---\n\n";
            cout << GREEN << "Enter Item Data File (file.txt)\n" << WHITE;
            cin >> data_file;
            infile.open(data_file.c_str());
        }
    } else if (indicator == 'B')
    {
        cout << GREEN << "\nEnter Basket Data File (file.txt)\n" << WHITE;
        cin >> data_file;

        infile.open(data_file.c_str());

        while(!infile.is_open())
        {
            cout << RED << "\t---ERROR FILE INPUT---\n\n";
            cout << GREEN << "Enter Basket Data File (file.txt)\n" << WHITE;
            cin >> data_file;
            infile.open(data_file.c_str());
        }
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
    char iType;
    int iWeight;
    int iSize;
    string iConstraint;
    string line;

    getline(infile,line);

    if (infile.is_open()) {
        
        while (infile >> scanned && scanned != 'E') 
        {
            if((infile >> iType) && (iType == Dairy ||
                                    iType == Frozen ||
                                    iType == Meat ||
                                    iType == Produce))
            {
                if((infile >> iWeight) && (0 < iWeight) && (iWeight <= MAX_IWEIGHT))
                {
                    if((infile >> iSize) && (0 < iSize) && (iSize <= MAX_ISIZE))
                    {
                        if((infile >> iConstraint) && (iConstraint== No_Dairy ||
                                                        iConstraint == No_Frozen ||
                                                        iConstraint == No_Meat ||
                                                        iConstraint == No_Produce))
                        {
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
                            curr->data.item_type = iType;
                            curr->data.item_weight = iWeight;
                            curr->data.item_size = iSize;
                            curr->data.item_constraint = iConstraint;
                            curr->data.in_basket = false;

                            item_fill++;
                        }
                    }
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
    int scanned;
    int bWeightLim;
    int bSizeLim;
    string bConstraint;
    string line;

    getline(infile,line);
    
    if (infile.is_open()) {
        while (infile >> scanned && scanned != 'E') {
            basket[basket_fill].basket_index = scanned;
            if((infile >> bWeightLim) && (0 < bWeightLim) && (bWeightLim <= MAX_BWEIGHT))
            {
                if((infile >> bSizeLim) && (0 < bSizeLim) && (bSizeLim <= MAX_BSIZE))
                {
                    if((infile >> bConstraint) && (bConstraint == No_Dairy ||
                                                    bConstraint == No_Frozen ||
                                                    bConstraint == No_Meat ||
                                                    bConstraint == No_Produce))
                    {
                        basket[basket_fill].basket_weight_limit = bWeightLim;
                        basket[basket_fill].basket_size_limit = bSizeLim;
                        basket[basket_fill].basket_constraints = bConstraint; 
                        basket[basket_fill].weight_remaining = basket[basket_fill].basket_weight_limit;
                        basket[basket_fill].size_remaining = basket[basket_fill].basket_size_limit;
                        basket[basket_fill].fill_lvl_item = 0;
                        basket[basket_fill].item_in_basket = NULL;

                        basket_fill++;
                    }
                }
            }
            
        }
        infile.close();
    } else 
    {
        cout << "Unable to open file: " << basket_data_file << endl;
    }
    

}

// Needs to be changed if struct changes
void view_result(g_basket basket[], int basket_count, item_list* item)
{
    item_list* curr;

    if(basket_count == 0) //no basket
    {
        cout << "\n---------------------------------------------------\n\n"
             << RED << "\t---NO BASKET---\n\n" << WHITE
             << "---------------------------------------------------\n";
    } else 
    {
        cout << GREEN << "\n\nDisplaying all basket's content...\n" << WHITE
            << "---------------------------------------------------\n";

        for(int i = 0; i < basket_count; i++)
        {
            if(basket[i].basket_index != 0)
            {
                output_basket_info(basket[i]);

                if(basket[i].item_in_basket != NULL)
                {
            
                    cout << "Items: \n"
                        << "No. | Type       | Weight | Size | Constraint\n" 
                        << "---------------------------------------------------\n";

                    curr = basket[i].item_in_basket;
                    while (curr != NULL)
                    {
                        cout << left << setw(4) << curr->data.item_index << "| ";
                        if(curr->data.item_type == Dairy)
                        {
                            cout << left << setw(11) << "Dairy" << "| ";
                        } else if(curr->data.item_type == Frozen)
                        {
                            cout << left << setw(11) << "Frozen" << "| ";
                        } else if(curr->data.item_type == Meat)
                        {
                            cout << left << setw(11) << "Meat" << "| ";
                        } else if(curr->data.item_type == Produce)
                        {
                            cout << left << setw(11) << "Produce" << "| ";
                        }

                        cout << left << setw(7) << curr->data.item_weight << "| "
                            << left << setw(5) << curr->data.item_size << "| ";

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
                        cout <<"---------------------------------------------------\n\n\n";
                } else 
                {
                    cout << "---------------------------------------------------\n\n"
                        << RED << "\t---NO ITEM ADDED---\n\n" << WHITE
                        << "---------------------------------------------------\n";
                }
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
    bool hasNotAdded = false;
    if(curr == NULL)
    {
        cout << endl << endl
             << "---------------------------------------------------\n\n"
             << RED << "\t---NO ITEM---\n\n" << WHITE
             << "---------------------------------------------------\n";
    } else 
    {
        cout << endl << endl
            << RED << "Displaying items not added into baskets...\n" << WHITE
            << "---------------------------------------------------\n";
        
        while (curr != NULL) {
            if (!curr->data.in_basket) {
                hasNotAdded = true;
                break;
            }
            curr = curr->next;
        }

        curr = item; //rest pointer

        if(!hasNotAdded)
        {
            cout << RED << "\n\t---ALL ITEM HAS ADDED---\n\n" << WHITE;
        } else
        {
            cout << "Items: \n"
                        << "No. | Type       | Weight | Size | Constraint\n" 
                        << "---------------------------------------------------\n";

            while(curr != NULL)
            {
                if(!curr->data.in_basket)
                {
                    cout << left << setw(4) << curr->data.item_index << "| ";
                    if(curr->data.item_type == Dairy)
                    {
                        cout << left << setw(11) << "Dairy" << "| ";
                    } else if(curr->data.item_type == Frozen)
                    {
                        cout << left << setw(11) << "Frozen" << "| ";
                    } else if(curr->data.item_type == Meat)
                    {
                        cout << left << setw(11) << "Meat" << "| ";
                    } else if(curr->data.item_type == Produce)
                    {
                        cout << left << setw(11) << "Produce" << "| ";
                    }
                    
                    cout << left << setw(7) << curr->data.item_weight << "| "
                        << left << setw(5) << curr->data.item_size << "| ";

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
        }
        cout << "---------------------------------------------------\n\n";
    }
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
        } else
            return false;
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
        } else
            return false;
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
