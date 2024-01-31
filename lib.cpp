#include "lib.h"

void get_data(string* data_file)
{
    fstream infile;
    string input_file;
    cout << GREEN << "Enter Info (file.txt)\n" << WHITE;
    cin >> input_file;

    while(!infile.is_open())
    {
        cout << RED << "\t---ERROR FILE INPUT---\n\n";
        cout << GREEN << "Enter Info (file.txt)\n" << WHITE;
        cin >> input_file;
    }
}