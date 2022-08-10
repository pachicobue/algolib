#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../src/utility/stopwatch.hpp"

void Test()
{
    const int us = 100;
    const int loop = 10;
    StopWatch sw;
    for (int i = 0; i < loop; i++) {
        auto start = std::chrono::system_clock::now();
        while (true) {
            auto now = std::chrono::system_clock::now();
            if (std::chrono::duration_cast<USec>(now - start).count() >= us) {
                break;
            }
        }
        const int rap = sw.rap<USec>();
        assert(us <= rap and rap < us + 100);
    }
    const int total = sw.total<USec>();
    assert(us * loop <= total and total < (us + 100) * loop);
}

int main()
{
    Test();
    std::cout << "Hello World\n";
    return 0;
}
