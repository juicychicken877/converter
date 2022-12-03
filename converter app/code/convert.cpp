#include <iostream>
#include "convert.hpp"
using namespace std;

void Convert::reset()
{
    byte_sum = 0;
    binary = "";
    bit = 1;
}

//----------------------------------------------------
string Convert::dec_to_bin(unsigned long long dec)
{
    if (dec == 0) return "0";

    while (dec != 0)
    {
        if (dec % 2 != 0) 
        {
            binary = '1' + binary; 
            dec--;
        }
        else 
            binary = '0' + binary;

        dec = dec / 2;
    }
    return binary;
}
//----------------------------------------------------
unsigned long long Convert::bin_to_dec(string bin)
{
    length = bin.length();
    for (int i=length-1;i>=0;i--)
    {
        if (bin[i] == '1') 
            decimal += bit;

        bit *= 2;
    }
    return decimal;
}
//----------------------------------------------------
string Convert::hex_to_bin(string hex)
{
    string hex_binary;
    length = hex.length();
    byte_sum = 0;

    for(int i=length-1;i>=0;i--)
    {
        if (hex[i] >= 48 && hex[i] <= 57) //case for numbers 0-9 ascii
            byte_sum = (int)hex[i]-48; 
        else if (hex[i] >= 65 && hex[i] <= 70) //case for uppercase letters ascii
            byte_sum = (int)hex[i]-55; 
        else if (hex[i] >= 97 && hex[i] <= 102) //lowercase letters
            byte_sum = (int)hex[i]-87;

        hex_binary = dec_to_bin(byte_sum) + hex_binary;

        if (hex_binary.length() % 4 != 0) //get missing 0's in front
        {
            for (int j=0;j<(hex_binary.length()%4);j++)
                hex_binary = '0' + hex_binary;
        }   

        reset(); //reset values
                              
    }

    return hex_binary;
}
//----------------------------------------------------
string Convert::oct_to_bin(string oct)
{
    string oct_binary;
    length = oct.length();

    for (int i=length-1;i>=0;i--)
    {
        byte_sum = (int)oct[i] - 48; //ascii code
        oct_binary = dec_to_bin(byte_sum) + oct_binary;

        if (oct_binary.length() % 3 != 0) //get missing 0's in front
        {
            for (int j=0;j<(oct_binary.length()%3);j++)
                oct_binary = '0' + oct_binary;
        }  
        
        reset();
    }

    return oct_binary;
}
//----------------------------------------------------
string Convert::bin_to_hex(string bin)
{
    length = bin.length();

    if (length % 4 != 0) //get missing 0's
    {
        for (int j=0;j<(bin.length()%4);j++)
            bin = '0' + bin;
    }

    length = bin.length(); //new length

    for (int i=length-1;i>=0;i--)
    {
        if (bin[i]=='1') 
            byte_sum += bit;
        bit *= 2;
        if (bit == 16)
        {
            if (byte_sum >= 0 && byte_sum <= 9)
                hexadecimal = ((char)(byte_sum+48)) + hexadecimal;
            else if (byte_sum >= 10 && byte_sum <= 15)
                hexadecimal = ((char)(byte_sum+55)) + hexadecimal; //65 (A) - 10 = 55
            reset();
        }
    }
    return hexadecimal;
}
//----------------------------------------------------
string Convert::bin_to_oct(string bin)
{
    length = bin.length();
   
    if (length % 3 != 0) //get missing 0's
    {
        for (int j=0;j<(bin.length()%3);j++)
            bin = '0' + bin;
    }

    length = bin.length(); //new length

    for (int i=length-1;i>=0;i--)
    {
        if (bin[i] =='1') 
            byte_sum += bit;
        bit *= 2;
        if (bit == 8)
        {
            octal = ((char)(byte_sum+48)) + octal;
            reset();
        }
    }

    return octal;
}