#include <iostream>
#include "vigenere.h"
#include <cctype>
char shiftCharAlpha(char c, char rshiftAlpha)
{   
    int rshift = (int) rshiftAlpha % 97;
    int num = (int)c;
    if (num >= 65 && num < 97)
    {
        return (char)((c - 65 + rshift) % 26 + 65);
    }

    else if (num >= 97)
    {
        return (char)((c - 97 + rshift) % 26 + 97);
    }

    else
    {
        return c;
    }

    return ' ';
}

std::string encryptVigenere(std::string plaintext, std::string keyword){
    std::string return_string = "";
    int place = 0;
    for(int i = 0; i < plaintext.length();i++){

        if(isalpha(plaintext[i])){
            return_string += shiftCharAlpha(plaintext[i], keyword[place % keyword.length()]);
            place++; 
        }
        else{
            return_string += plaintext[i];
        }
    }

    return return_string;
}