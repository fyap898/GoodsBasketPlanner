#include <iostream>
#include <fstream>
#include "types.h"
#include "lib.h"
using namespace std;

//Description: Prompts menu
void start_message();

int main (){

    string* data_file = NULL;
    start_message();
    get_data(data_file);

    return 0;
}

void start_message()
{
    cout << GREEN << "\n\nWelcome to Goods Basket Planner\n\n" << WHITE;
    return;
}

