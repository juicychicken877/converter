#include <iostream>
#include <windows.h>
#include <conio.h>
#include "convert.hpp"
using namespace std;

void show_menu()
{
    cout << "---------------------------" << endl
         << "CONVERT :"                   << endl
         << "1. DECIMAL NUMBER"           << endl
         << "2. BINARY NUMBER"            << endl
         << "3. HEXADECIMAL NUMBER"       << endl
         << "4. OCTAL NUMBER"             << endl
         << "5. EXIT"                     << endl
         << "Your option: ";
}

int main()
{
    char main_menu_option; 
    char continue_option;
    string string_num;  unsigned long long int_num; //nums to convert
    string container;

    while (main_menu_option != 5)
    {
        system("CLS");

        show_menu();

        main_menu_option = getch(); //input
        cout << main_menu_option << endl;

        main_menu_option = (int)(main_menu_option-48); //in case if someone try to enter a character instead of number

        if (main_menu_option >= 1 && main_menu_option <= 5)
        { 
            Convert convert; //converting object

            switch (main_menu_option)
            {
                case 1: //dec to all
                    cout << "(10) : "; cin >> int_num;
                    container = convert.dec_to_bin(int_num);
                        
                    cout << "(2)  : " << container << endl;                     //dec to bin
                    cout << "(8)  : " << convert.bin_to_oct(container) << endl; //converted bin from dec to oct
                    cout << "(16) : " << convert.bin_to_hex(container) << endl; //converted bin from dec to hex
                break; 
                case 2: //bin to all
                    cout << "(2)  : "; cin >> string_num;
                    cout << "(8)  : " << convert.bin_to_oct(string_num) << endl;
                    cout << "(10) : " << convert.bin_to_dec(string_num) << endl;
                    convert.reset();
                    cout << "(16) : " << convert.bin_to_hex(string_num) << endl;
                break;
                case 3: //hex to all
                    cout << "(16) : "; cin >> string_num;
                    container = convert.hex_to_bin(string_num);

                    cout << "(2)  : " << container << endl;
                    cout << "(8)  : " << convert.bin_to_oct(container) << endl;
                    cout << "(10) : " << convert.bin_to_dec(container) << endl;
                break;
                case 4: //oct to all
                    cout << "(8)  : "; cin >> string_num;
                    container = convert.oct_to_bin(string_num);

                    cout << "(2)  : " << container << endl
                         << "(10) : " << convert.bin_to_dec(container) << endl;
                    convert.reset();
                    cout << "(16) : " << convert.bin_to_hex(container) << endl;
                break;
                case 5: exit(0); break;
            }

            cout << "---------------------------" << endl
                 << "Continue? y/n : "; cin >> continue_option;
        
            if (continue_option =='n') 
                exit(0);
            else 
                continue;
        }
        else 
        {
            cout << "!!! Please choose option 1 - 5 !!!" << endl;
            Sleep(2000);
        }

    }
}
}
