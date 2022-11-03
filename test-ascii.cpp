#include <iostream>

int main(){
    std::string s;
    std::cout << "Input: ";
    std::getline(std::cin , s);
    for(int i = 0; i < s.length();i++){
        char c = s[i];
        std::cout << c << " " << int(c) << std::endl;
    }
}