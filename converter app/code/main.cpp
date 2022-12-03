#include <iostream>
#include "convert.hpp"
#include <windows.h>
using namespace std;

void show_menu()
{
    cout << "------------------" << endl;
    cout << "1. DEC to BIN" << endl;
    cout << "2. HEX to BIN" << endl;
    cout << "3. OCT to BIN" << endl;
    cout << "4. BIN to DEC" << endl;
    cout << "5. BIN to HEX" << endl;
    cout << "6. BIN to OCT" << endl;
    cout << "7. EXIT" << endl;
    cout << "Your option: ";
}
//----------------------------------------------------
int main()
{
    int main_menu_option; 
    char continue_option;
    string string_num;  unsigned long long int_num; //nums to convert

    while (main_menu_option != 7)
    {
        system("CLS");

        show_menu();

        cin >> main_menu_option;

        Convert convert; //converting object

        convert.reset(); //reset all of the values

        cout << "Type a number: ";

        if (main_menu_option == 1)  //depending on option, read the right variable (int or string);
            cin >> int_num;
        else if (main_menu_option > 1 && main_menu_option < 7)
            cin >> string_num;

        switch (main_menu_option)
        {
            case 1: 
                cout << "dec to bin: " << convert.dec_to_bin(int_num) << endl;
            break; 
            case 2: 
                cout << "hex to bin: " << convert.hex_to_bin(string_num) << endl;
            break;
            case 3:
                cout << "oct to bin: " << convert.oct_to_bin(string_num) << endl; 
            break;
            case 4:
                cout << "bin to dec: " << convert.bin_to_dec(string_num) << endl;
            break;
            case 5: 
                cout << "bin to hex: " << convert.bin_to_hex(string_num) << endl;
            break;
            case 6:
                cout << "bin to oct: " << convert.bin_to_oct(string_num) << endl;
            break;
            case 7: 
                exit(0); 
            break;
        }
        cout << "------------------" << endl;
        cout << "Continue? y/n : "; cin >> continue_option;
        
        switch (continue_option) 
        {
            case 'y': 
                continue; 
            break;
            case 'n': 
                exit(0); 
            break;
            default: 
                continue; 
            break;
        }
    }
}