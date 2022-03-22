#include <iostream>
#include <chrono>

using namespace std::chrono;

template<typename T>

class Timer {
public:
    Timer() : start(steady_clock::now()), duration(steady_clock::duration()), flag(false) {}

    void Timer_pause() {
        int a;
        if (not flag) {
            duration += steady_clock::now() - start;
        }
        flag = true;
    }


    void Timer_go() {
        if (flag) {
            start = steady_clock::now();
        }
        flag = false;
    }

//    void Timer_duration_in_count(int a) {
//        duration += steady_clock::now() - start;
//        a = duration_cast<T>(steady_clock::now() - duration).count();
//    }

    auto Duration_to_int() {
        return duration_cast<T>(duration).count();
    }

    void Timer_zero(){
        duration = steady_clock::duration(0);
    }

    ~Timer() = default;



private:
    steady_clock::time_point start;
    steady_clock::duration duration;
    bool flag;
};


