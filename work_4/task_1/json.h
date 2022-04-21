//
// Created by Marina on 20.04.2022.
//

#ifndef HW_4_JSON_H
#define HW_4_JSON_H

#include <iostream>
#include "../json_main.hpp"
#include <fstream>
#include <utility>
#include "filesystem"
#include "map"

using nlohmann::json;

class Person {
public:
    std::string get_name() const{
        return name;
    }

    int get_age() const {
        return age;
    }

    void set_name(std::string new_name) {
        name = std::move(new_name);
    }

    void set_age(int new_age) {
        age = new_age;
    }

    void set_telephone(std::map<std::string, std::string> new_telephone) {
        telephone["home_phone"] = new_telephone["home_phone"];
        telephone["mobile_phone"] = new_telephone["mobile_phone"];
    }

    json create_json() {
        json j;
        j["age"] = age;
        j["name"] = name;
        j["telephone"]["home_phone"] = telephone["home_phone"];
        j["telephone"]["mobile_phone"] = telephone["mobile_phone"];

        return j;
    }

    void read_json(json j) {
        age = j["age"];
        name = j["name"];
        telephone["home_phone"] = j["telephone"]["home_phone"];
        telephone["mobile_phone"] = j["telephone"]["mobile_phone"];
    }

    friend std::ostream &operator<<(std::ostream &os, Person &person) {
        os << person.create_json();
        return os;
    };

    friend std::istream &operator>>(std::istream &is, Person &person) {
        json data;
        is >> data;
        person.read_json(data);
        return is;
    };


    ~Person() = default;

private:
    std::string name;
    int age;
    std::map<std::string, std::string> telephone;
};

#endif //HW_4_JSON_H
