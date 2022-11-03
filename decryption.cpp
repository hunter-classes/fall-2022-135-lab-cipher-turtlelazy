#include <iostream>
#include "decryption.h"
#include <cctype>

char shiftCharBack(char c, int rshift)
{
    int num = (int)c;

    if (num >= 65 && num < 97)
    {
        return (char) (25 - (25 - (c-65) + rshift) % 26 + 65);
        //return (char)((c - 65 + rshift) % 26 + 65);
    }

    else if (num >= 97)
    {
        return (char) (25 - (25 - (c - 97) + rshift) % 26 + 97);

        //return (char)((c - 97 + rshift) % 26 + 97);
    }

    else
    {
        return c;
    }

    return ' ';
}

char shiftCharAlphaBack(char c, char rshiftAlpha){
    int rshift = (int)rshiftAlpha % 97;
    return shiftCharBack(c,rshift);
}

std::string decryptCaesar(std::string ciphertext, int rshift)
{
    std::string return_string = "";
    for (int i = 0; i < ciphertext.length(); i++)
    {
        return_string += shiftCharBack(ciphertext[i], rshift);
    }

    return return_string;
}

std::string decryptVigenere(std::string plaintext, std::string keyword){
    std::string return_string = "";
    int place = 0;
    for (int i = 0; i < plaintext.length(); i++)
    {

        if (isalpha(plaintext[i]))
        {
            return_string += shiftCharAlphaBack(plaintext[i], keyword[place % keyword.length()]);
            place++;
        }
        else
        {
            return_string += plaintext[i];
        }
    }

    return return_string;
}
