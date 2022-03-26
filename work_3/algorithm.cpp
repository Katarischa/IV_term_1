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

int add_numbers() {
    int number;
    std::cin >> number;
    return number;
}

bool is_odd(int elem) {
    if (elem % 2 == 1) {
        return true;
    }
    return false;
}

int is_prime(int elem) {
    if (elem <= 1)
        return false;
    for (auto i = 2u; i < std::sqrt(elem); i++)
        if (elem % i == 0)
            return false;
    return true;
}

void Square(int &elem) {
    elem *= elem;
}

void replace_with_zeros(int &elem) {
    if (elem < 0) {
        elem = 0;
    }
}


int main() {
    // 1. создаем последовательность от 1 до 10
    std::vector<int> p_1(10);
    std::iota(p_1.begin(), p_1.end(), 1);
    std::cout << "Sequence: " << p_1 << std::endl;

    // 2. добавим несколько значений в конец
    int n;
    std::cout << "Enter the quantity of number >>";
    std::cin >> n;
    p_1.resize(10 + n);
    std::generate_n(std::next(p_1.begin(), 10), n, add_numbers);
    std::cout << "Extended sequence: " << p_1 << std::endl;

    // 3. перемешаем последовательность случайным образом
    std::mt19937 gen;
    std::ranges::shuffle(p_1, gen);
    std::cout << "Shuffled Sequence: " << p_1 << std::endl;

    // 4. удалим дубликаты из последовательности
    std::ranges::sort(p_1);
    auto[first, last] = std::ranges::unique(p_1.begin(), p_1.end());
    p_1.erase(first, last);
    std::cout << "Sequence without Duplicates: " << p_1 << std::endl;

    // 5. посчитаем количество нечетных чисел в последовательности
    std::cout << "Amount of Odd: " << std::count_if(p_1.begin(), p_1.end(), is_odd) << std::endl;

    // 6. найдем минимум и максимум в последовательности
    std::cout << "Min: " << std::ranges::minmax(p_1).min << "; Max: " << std::ranges::minmax(p_1).max << std::endl;

    // 7. найдем хотя бы одно простое число в последовательности
    auto result = std::find_if(p_1.begin(), p_1.end(), is_prime);
    if (result == p_1.end()) {
        std::cout << "There are not any prime number in sequence" << std::endl;
    } else {
        std::cout << "Prime number: " << *result << std::endl;
    }

    // 8. заменим числа в последовательности их квадратами
    std::ranges::for_each(p_1.begin(), p_1.end(), Square);
    std::cout << "Square of Number" << p_1 << std::endl;

    // 9. создадим последовательность из N случайных чисел
    int a;
    std::cout << "Enter the quantity of number >>";
    std::cin >> a;
    std::vector<int> p_2(a);
    std::mt19937 rng;
    std::generate_n(p_2.begin(), a, std::ref(rng));
    std::cout << "Random Sequence: " << p_2 << std::endl;

    // 10. вычислим сумму последовательности p2
    int sum = std::accumulate(p_2.begin(), p_2.end(), 0);
    std::cout << "Sequence Sum: " << sum << std::endl;

    // 11. заменим первые несколько членов р2 числом 1
    std::cout << "Amount of 1" << std::endl;
    int k;
    std::cin >> k;
    if (k < p_2.size()) {
        std::fill(p_2.begin(), std::next(p_2.begin(), k), 1);
        std::cout << "Sequence with 1: " << p_2 << std::endl;
    } else {
        std::cerr << "Number too large";
    }

    // 12. создадим последовательность р3 как разность между р1 и р2
    if (p_1.size() > p_2.size()) {
        p_2.resize(p_1.size());
    } else if (p_1.size() < p_2.size()) {
        p_1.resize(p_2.size());
    }
    std::vector<int> p_3;
    std::transform(p_1.begin(), p_1.end(), p_2.begin(), std::back_inserter(p_3),
                   [](auto lhs, auto rhs) { return lhs - rhs; });
    std::cout << "Sequence p_3: " << p_3 << std::endl;

    // 13. заменим отрицательные значения в последовательности р3 нулями
    std::ranges::for_each(p_3.begin(), p_3.end(), replace_with_zeros);
    std::cout << "Square with Replaced Zero: " << p_3 << std::endl;

    // 14. удалим все нули из р3
    auto[first_1, last_1] = std::ranges::remove_if(p_3.begin(), p_3.end(), [](auto x) { return x == 0; });
    p_3.erase(first_1, last_1);
    std::cout << "Square without Zero: " << p_3 << std::endl;

    // 15. изменим порядок в последовательности р3 на обратный
    std::ranges::reverse(p_3.begin(), p_3.end());
    std::cout << "Reversed sequence: " << p_3 << std::endl;

    // 16. топ-3 наибольших элементов в р3
    std::nth_element(p_3.begin(), std::next(p_3.begin(), 2), p_3.end(), std::greater{});
    std::nth_element(p_3.begin(), std::next(p_3.begin(), 1), p_3.end(), std::greater{});
    std::cout << "Top 3 Larges Elements in p3: " << p_3.at(0) << ", " << p_3.at(1) << ", "
              << p_3.at(2) << std::endl;

    // 17. отсортируем массивы р1 и р2
    std::ranges::sort(p_1.begin(), p_1.end());
    std::ranges::sort(p_2.begin(), p_2.end());
    std::cout << "Sorted Sequence: " << p_1 << ", " << p_2 << std::endl;

    // 18. создадим массив р4 как слияние р1 и р2
    std::vector<int> p_4;
    std::ranges::merge(p_1, p_2, std::back_inserter(p_4));
    std::cout << "Sequence p_4: " << p_4 << std::endl;

    // 19.
    auto lower = std::ranges::lower_bound(p_4.begin(), p_4.end(), 1);
    auto upper = std::ranges::upper_bound(p_4.begin(), p_4.end(), 1);
    std::cout << "Value 1 can be between " << std::distance(p_4.begin(), lower) <<" and "<< std::distance(p_4.begin(), upper) << std::endl;

    // 20. выведем все итоговые последовательности
    std::cout << "p1 " << p_1 << "\n" << "p2 " << p_2 << "\n" << "p3 " << p_3 << "\n" << "p4 " << p_4;

    return 0;
};