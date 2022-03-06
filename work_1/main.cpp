#include <iostream>
#include "timer.h"

int main() {
    auto result = 0.;
    {
        Timer<milliseconds> t;
        for (auto i = 0u; i < 1'000'000u; i++) {
            result += sin(i) * cos(i);
        }
        t.Timer_pause();
        for (auto i = 0u; i < 11'000'000u; i++) {
            result += sin(i) * cos(i);
        }
        t.Timer_go();
        for (auto i = 0u; i < 12'000'000u; i++) {
            result += sin(i) * cos(i);
        }
        t.Timer_pause();
    }
    std::cout << "Result is " << result << std::endl;
    return 0;
}
