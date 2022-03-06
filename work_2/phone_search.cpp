#include <iostream>
#include "phonebook.h"
#include "phonebook.cpp"


int main(){
    long long number = 89018315613;
    std::string surname = "Nikelson";
    Phonebook phonebook;

    phonebook.New_number(number,surname);
    phonebook.New_number(89114039478, "Abramovich");

    std::cout << phonebook.Search_number("Nikelson")<< std::endl;
    std::cout << phonebook.Search_number("Mikelson")<< std::endl;

    auto a = phonebook.No_number(0);
    std::cout << a.first <<" "<< a.second << std::endl;

    auto t = phonebook.Random_number();
    std::cout << t.first <<" "<< t.second << std::endl;

    return 0;
}