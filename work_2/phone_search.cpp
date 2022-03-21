#include <iostream>
#include "phonebook.h"


int main(){
    long long number = 89018315613;
    std::string surname = "Nikelson";
    Phonebook phonebook;

    // adding new numbers
    phonebook.New_number(number,surname);
    phonebook.New_number(89114039478, "Abramovich");
    phonebook.New_number(80677822893, "Sunny");
    phonebook.New_number(86060309021, "Elly");
    phonebook.New_number(84317571434, "Donald");
    phonebook.New_number(85363805564, "Ivanov");
    phonebook.New_number(82162939183, "Zendy");
    phonebook.New_number(85641003468, "Kennedy");
    phonebook.New_number(83672678589, "Obama");
    phonebook.New_number(87568921564, "Hilton");

    std::cout << "-----------------Search Number in Phonebook-----------------------" << std::endl;

    std::cout << phonebook.Search_number("Nikelson")<< std::endl;
    std::cout << phonebook.Search_number("Mikelson")<< std::endl;
    std::cout << phonebook.Search_number("Kennedy")<< std::endl;

    std::cout << "-----------------Get Number by Index------------------------------" << std::endl;

    for (auto i = 0u; i < 10u; i++) {
        auto get = phonebook.Get_index_number(i);
        std::cout << get.first <<" "<< get.second << std::endl;}

    std::cout << "------------------Output Random Numbers----------------------------" << std::endl;

    for (auto i = 0u; i < 10u; i++) {
        auto random = phonebook.Random_number();
        std::cout << random.first <<" "<< random.second << std::endl;}

    std::cout << "-------------------------------------------------------------------" << std::endl;

    return 0;
}