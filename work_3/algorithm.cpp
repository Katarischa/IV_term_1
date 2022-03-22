#include <numeric>
#include <algorithm>
#include <iostream>
#include "random"

template<typename T>
//выводим вектор в cout
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vector) {
    out << '[';
    std::copy(std::begin(vector), std::prev(std::end(vector)),
              std::ostream_iterator<T>(out, ", "));
    return out << *std::prev(std::end(vector)) << ']';
}

int add_numbers(){
    int number;
    std::cin>>number;
    return number;
}

bool is_odd(int elem){
    if (elem % 2 == 1){
        return true;
    }
    return false;
}

int main() {
    // 1. создаем последовательность от 1 до 10
    std::vector<int> p_1(10);
    std::iota(p_1.begin(), p_1.end(), 1);
    std::cout <<"Sequence: "<< p_1 << std::endl;

    // 2. добавим несколько значений в конец
    int n;
    std::cout << "Enter the quantity of number >>";
    std::cin >> n;
    p_1.resize(10 + n);
    std::generate_n(std::next(p_1.begin(), 10), n, add_numbers);
    std::cout << "Extended sequence: "<<p_1 << std::endl;

    // 3. перемешаем последовательность случайным образом
    std::mt19937 gen;
    std::ranges::shuffle(p_1, gen);
    std::cout <<"Shuffled Sequence: "<< p_1 << std::endl;

    // 4. удалим дубликаты из последовательности
    std::ranges::sort(p_1);
    auto [first, last] = std::ranges::unique(p_1.begin(), p_1.end());
    p_1.erase(first, last);
    std::cout <<"Sequence without Duplicates: "<< p_1 << std::endl;

    // 5. посчитаем количество нечетных чисел в последовательности
    std::cout <<"Amount of Odd: "<< std::count_if(p_1.begin(),p_1.end(),is_odd) << std::endl;

    // 6. найдем минимум и максимум в последовательности
    std::cout << "Min: "<< std::ranges::minmax(p_1).min << "; Max: " << std::ranges::minmax(p_1).max <<std::endl;

    // 7. найдем хотя бы одно простое число в последовательности

    return 0;
};