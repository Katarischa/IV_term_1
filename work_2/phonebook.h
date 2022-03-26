//
// Created by Marina on 06.03.2022.
//

#ifndef IV_TERM_1_PHONEBOOK_H
#define IV_TERM_1_PHONEBOOK_H

#include <iostream>
#include "chrono"
#include <map>
#include "random"

class Phonebook{
public:
    Phonebook() = default;

    void New_number(long long number, std::string surname){
        phonebook.emplace(surname, number);
    };

    long long Search_number(std::string surname){
        try {
            return phonebook.at(surname);
        }
        catch ( const std::out_of_range& e){
            std::cerr << e.what() <<" Surname "<< surname<<" isn't in phonebook, please, try again" <<  std::endl;
            return 0;
        }
    };

    auto Get_index_number(int no){
        return *std::next(phonebook.begin(), no);
    };

    auto Random_number(){
        auto curr_time = std::chrono::steady_clock::now().time_since_epoch().count();
        auto generator = std::mt19937_64(curr_time);
        std::uniform_int_distribution<> distribution;
        int a = distribution(generator);
        a %= std::size(phonebook);
        return Get_index_number(a);
    };

    ~Phonebook() = default;
private:
    std::map<std::string, long long> phonebook;

};




#endif //IV_TERM_1_PHONEBOOK_H
