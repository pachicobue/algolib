// verification-helper: UNITTEST
#include <algorithm>
#include <cassert>
#include "internal/seq_op.hpp"
#include "internal/type.hpp"
void test() {
    const auto vs = iotaVec(5, 10);
    const Vec<int> ans{10, 11, 12, 13, 14};
    assert(std::ranges::equal(vs, ans));
}
int main() {
    test();
    return 0;
}
