// verification-helper: UNITTEST
#include <algorithm>
#include <cassert>
#include "internal/seq_op.hpp"
#include "internal/type.hpp"
void test() {
    int v = 0;
    auto gen = [&]() { return v += 10; };
    const auto vs = genVec<int>(5, gen);
    const Vec<int> ans{10, 20, 30, 40, 50};
    assert(std::ranges::equal(vs, ans));
}
int main() {
    test();
    return 0;
}
