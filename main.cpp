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
    std::string strings = "A set of words that is complete in itself, typically containing a subject and predicate, conveying a statement, question, exclamation, or command, and consisting of a main clause and sometimes one or more subordinate clauses";
    // for(int i = 0; i < strings.length(); i++){
    //     std::cout << strings[i] << " " << alphabet_placement(strings[i]) << "\n";
    // }
    strings = encryptCaesar(strings,10);
    std::cout << strings << " ------>\n\n";

    strings = solve(strings);
    std::cout << strings << "\n";
    return 0;
}