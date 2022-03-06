#include "iostream"
#include "chrono"
#include "timer.h"
#include "random"
#include "algorithm"
#include "array"
#include "vector"
#include "deque"
#include "list"
#include "forward_list"

using namespace std::chrono;

double randomizer() {
    auto curr_time = steady_clock::now().time_since_epoch().count();
    auto generator = std::mt19937_64(curr_time);
    std::uniform_real_distribution<> distribution(0., 1'200.);

    return distribution(generator);
}

template<typename T>
void random_num(T container) {
    std::generate(std::begin(container), std::end(container), randomizer);
}

int main() {
    const int leghth = 1000;
    const int iter = 1000;
    Timer<milliseconds> t;

    std::array<double, leghth> arr{};
    t.Timer_go();
    for (int i = 0; i < iter; i++) {
        random_num(arr);
        std::sort(arr.begin(), arr.end());
    }
    t.Timer_pause();
    auto arr_time = t.Duration_to_int();
    std::cout << "Working time of array is  " << arr_time << std::endl;

    t.Timer_zero();

    std::vector<double> vec;
    t.Timer_go();
    for (int i = 0; i < iter; i++) {
        int b_size = leghth;
        vec.resize(b_size);
        random_num(vec);
        std::sort(vec.begin(), vec.end());
    }
    t.Timer_pause();
    auto vec_time = t.Duration_to_int();
    std::cout << "Working time of vector is  " << vec_time << std::endl;

    t.Timer_zero();

    t.Timer_go();
    std::deque<double> deq;
    int b_size = leghth;
    deq.resize(b_size);
    for (int i = 0; i < iter; i++) {
        random_num(deq);
        std::sort(deq.begin(), deq.end());}
    t.Timer_pause();
    auto deq_time = t.Duration_to_int();
    std::cout << "Working time of deque is  " << deq_time << std::endl;

    t.Timer_zero();

    t.Timer_go();
    std::list<double> lst;
    lst.resize(b_size);
    for (int i = 0; i < iter; i++) {
         random_num(lst);
         lst.sort();}
    t.Timer_pause();
    auto lst_time = t.Duration_to_int();
    std::cout << "Working time of list is  " << lst_time << std::endl;

    t.Timer_zero();

    t.Timer_go();
    std::forward_list<double> flst;
    flst.resize(b_size);
    for (int i = 0; i < iter; i++) {
        random_num(flst);
        flst.sort();}
    t.Timer_pause();
    auto flst_time = t.Duration_to_int();
    std::cout << "Working time of forward list is  " << flst_time << std::endl;
    return 0;
}