#include <iostream>
#include "json.hpp"
#include <fstream>
#include "filesystem"

using nlohmann::json;

void make_human_directory() {
    if (!std::filesystem::exists("../Person")) {
        std::filesystem::create_directory("../Person");
    }
}

int main() {
    std::cout << "Example:"<<std::endl;
    json person_ex;
    std::vector<long long>phone_number = {79035614823, 79195617826};
    person_ex["phone_number"] = phone_number;
    person_ex["address"]["street"] = json("Ploshchad revoluzii");
    person_ex["address"]["city"] = json("Krasnodar");
    person_ex["address"]["postal_code"] = json(103495);
    person_ex["name"]["first_name"] = json("Alex");
    person_ex["name"]["last_name"] = json("Ivanov");
    for (auto item = person_ex.begin(); item != person_ex.end(); ++item) {
        std::cout << item.key() << ": " << item.value() << std::endl;
    }
}
