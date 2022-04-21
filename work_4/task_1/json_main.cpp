#include "../json_main.hpp"
#include "json.h"
#include "filesystem_json.h"

using nlohmann::json;

int main() {

    Person person_one;
    Person read_person;
    Person write_person;

    person_one.set_age(12);
    person_one.set_name("Alex");
    person_one.set_telephone({{"home_phone",   "44237"},
                              {"mobile_phone", "89241486037"}});
    json json_person = person_one.create_json();
    read_person.read_json(json_person);

    std::cout << json_person << std::endl;
    std::cout << read_person << std::endl;

    std::cout << "Enter age, name and telephone(home, mobile) >>" << std::endl;
    std::cin >> write_person;
    std::cout << write_person << std::endl;

    make_Person_file(write_person);

    return 0;
}
