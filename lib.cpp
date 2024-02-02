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

void read_datafile(g_item item[], int& itemFill, g_basket basket[], int& basketFill, string data_file)
{
    ifstream infile;
    char scanned = '\0';
    int i = 0;
    bool done_read = false;

    infile.open(data_file);

    while(!done_read)
    { 
        infile >> item[i].item_index;
        infile >> item[i].item_weight;
        infile >> item[i].item_type;
        infile >> item[i].item_size;
        infile >> item[i].item_count;
        infile >> item[i].item_constraint;
        itemFill++;
        i++;

        //clear white space
        infile.get(scanned);

        //peek for bookmark that indicate end for reading items
        scanned = static_cast<char>(infile.peek());
        if(scanned == 'B')
        {
            infile >> scanned;
            cout << scanned;
            done_read = true;
            i = 0;
        } 
    }

    done_read = false;

    while(!done_read)
    {
        infile >> basket[i].basket_index;
        infile >> basket[i].basket_weight_limit;
        infile >> basket[i].basket_type;
        infile >> basket[i].basket_size_limit;
        infile >> basket[i].basket_count;
        infile >> basket[i].basket_constraints;
        basketFill++;
        i++;

        if(infile.eof())
        {
            cout << "entered" << '\n';
            done_read = true;
        }
    }
    
    infile.close();
    return;
}

void flush()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

