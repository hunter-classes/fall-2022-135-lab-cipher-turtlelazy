#include <iostream>
#include "caesar.h"
#include <vector>
#include <cmath>
#include <algorithm> 
#include "decryption.h"

// add functions here
char shiftChar(char c, int rshift)
{
    int num = (int)c;
    if (num >= 65 && num < 97)
    {
        return (char)((c - 65 + rshift) % 26 + 65);
    }
    else if (num >= 97)
    {
        return (char)((c - 97 + rshift) % 26 + 97);
    }
    else{
        return c;
    }
    return ' ';
}

int alphabet_placement(char c){
    int num = (int)c;
    if (num >= 65 && num < 97)
    {
        return (char)((c - 65) % 26);
    }
    else if (num >= 97)
    {
        return (char)(c - 97) % 26;
    }
    return -1;
}

std::string encryptCaesar(std::string plaintext, int rshift){
    std::string return_string = "";
    for(int i = 0; i < plaintext.length();i++){
        return_string += shiftChar(plaintext[i],rshift);
    }
    return return_string;
}

std::vector<double> english_frequencies = {
    0.082,
    0.015,
    0.028,
    0.043,
    0.13,
    0.022,
    0.02,
    0.061,
    0.07,
    0.0015,
    0.0077,
    0.04,
    0.024,
    0.067,
    0.075,
    0.019,
    0.00095,
    0.06,
    0.063,
    0.091,
    0.028,
    0.0098,
    0.024,
    0.0015,
    0.02,
    0.0074
};
void print_vector(std::vector<double> vectors)
{
    std::string print_string = "";
    for (int i = 0; i < vectors.size(); i++)
    {
        print_string += std::to_string(vectors.at(i)) + " ";
    }
    std::cout << print_string << "\n";
}

double distance(std::vector<double> english_frequencies, std::vector<double> text_frequencies){
    double sum = 0;
    for(int i = 0; i < english_frequencies.size(); i++){
        double diff = english_frequencies.at(i) - text_frequencies.at(i);
        sum += std::pow(diff,2);
    }
    return std::sqrt(sum);
}

std::vector<double> text_frequencies(std::string encrypted_string){
    std::vector<double> frequencies(26,0);
    //print_vector(frequencies);
    int alpha_char = 0;
    for(int i = 0; i < encrypted_string.length();i++){
        int placement = alphabet_placement(encrypted_string[i]);
        if(placement != -1){
            frequencies.at(placement) += 1;
            alpha_char ++;
        }
    }
    for(int i = 0; i < frequencies.size();i++){
        frequencies.at(i) = frequencies.at(i) / (1.0 * alpha_char);
    }

    return frequencies;
}
void shifting_vector(std::vector<double> &frequency_vector){
    std::rotate(frequency_vector.begin(), frequency_vector.begin() + 1, frequency_vector.end());
}

std::string solve(std::string encrypted_string)
{
    std::string return_string = "";
    std::vector<double> string_frequencies = text_frequencies(encrypted_string);
    //print_vector(string_frequencies);
    int shift = 0;
    double smallest_distance = distance(string_frequencies,english_frequencies);
    //std::cout << smallest_distance << "\n";
    for(int i = 1;i< 26;i++){
        shifting_vector(string_frequencies);
        double current_distance = distance(string_frequencies,english_frequencies);
        if(current_distance < smallest_distance){
            shift = i;
            smallest_distance = current_distance;
        }
    }

    return decryptCaesar(encrypted_string,shift);
}
