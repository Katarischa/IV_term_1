//
// Created by Marina on 21.04.2022.
//

#ifndef HW_4_FILESYSTEM_JSON_H
#define HW_4_FILESYSTEM_JSON_H

#include "json.h"

namespace fs = std::filesystem;
using nlohmann::json;

void make_person_directory() {
    if (!fs::exists("../Person")) {
        fs::create_directory("../Person");
    }
}

void make_Person_file(Person person) {
    make_person_directory();
    fs::path person_path("../Person");
    person_path = person_path / (person.get_name() + ".json");
    std::fstream fout(person_path, std::ios::out);
    fout << person.create_json();
    fout.close();
}

void delete_person_file(const Person &person) {
    make_person_directory();
    fs::path person_path("../Person");
    person_path = person_path / (person.get_name() + ".json");
    fs::remove(person_path);

}

std::vector<Person> read_person_files() {
    std::vector<Person> output;

    fs::path person_path("../Person");
    fs::directory_iterator begin(person_path);
    fs::directory_iterator end;

    for (auto it = begin; it != end; it++) {
        auto path = it->path();
        Person read_person;
        std::fstream fin(path, std::ios::in);
        fin >> read_person;
        fin.close();
        output.push_back(read_person);
    }

    return output;
}


#endif //HW_4_FILESYSTEM_JSON_H
