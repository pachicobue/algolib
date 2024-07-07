// verification-helper: UNITTEST
#include <cassert>
#include <chrono>
#include <cmath>
#include <thread>
#include "internal.hpp"
#include "utility/stopwatch.hpp"
void test() {
    constexpr int DELTA = 10;
    constexpr int ERR = 1;
    StopWatch sw;
    LOOP (10) {
        std::this_thread::sleep_for(std::chrono::milliseconds(DELTA));
        assert(std::abs(sw.get<std::chrono::milliseconds>() - DELTA) <= ERR);
        assert(std::abs(sw.rap<std::chrono::milliseconds>() - DELTA) <= ERR);
    }
    assert(std::abs(sw.total<std::chrono::milliseconds>() - DELTA * 10) <= ERR * 10);
}
int main() { test(); }
