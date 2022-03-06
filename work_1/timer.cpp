#include <iostream>
#include <chrono>

using namespace std::chrono;

template<typename T>

class Timer {
public:
    Timer() : start(steady_clock::now()), duration(steady_clock::duration()), flag(false) {}

    void Timer_pause() {
        if (not flag) {
            duration += steady_clock::now() - start;
            std::cout << "Timer paused. Duration is: " << duration_cast<T>(duration).count()
                      << std::endl;
        }
        flag = true;
    }


    void Timer_go() {
        if (flag) {
            start = steady_clock::now();
            std::cout << "Timer started. Time is: " << duration_cast<T>(duration).count() << std::endl;

        }
        flag = false;
    }


    ~Timer() {
        std::cout << "Duration is " <<
                  duration_cast<T>(steady_clock::now() - start).count()
                  << std::endl;
    }

private:
    steady_clock::time_point start;
    steady_clock::duration duration;
    bool flag;
};

