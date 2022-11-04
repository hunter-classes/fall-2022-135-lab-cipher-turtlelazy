#include <iostream>
#include "caesar.h"
#include "vigenere.h"
#include "decryption.h"
#include <vector>
#include <string>
#include <algorithm>
void print_vector(std::vector<double> vectors);

int main()
{
    std::vector<double> vectors = {0,1,2,3,4,5,6};
    print_vector(vectors);
    shifting_vector(vectors);
    print_vector(vectors);
    shifting_vector(vectors);
    print_vector(vectors);
    shifting_vector(vectors);
    return 0;
}

void print_vector(std::vector<double> vectors){
    std::string print_string = "";
    for(int i = 0; i < vectors.size();i++){
        print_string += std::to_string(vectors.at(i)) + " ";
    }
    std::cout << print_string << "\n";
}