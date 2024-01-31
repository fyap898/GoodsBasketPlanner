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
    }

    infile.close();
}

void read_datafile(g_item item[], g_basket basket[], string data_file)
{
    ifstream infile;
    int i = 0;

    infile.open(data_file);

    
        infile >> item[i].item_index;
        infile >> item[i].item_weight;
        infile >> item[i].item_type;
        infile >> item[i].item_size;
        infile >> item[i].item_count;
        infile >> item[i].item_constraint;
    
    return;
}

