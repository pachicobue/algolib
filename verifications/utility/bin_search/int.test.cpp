// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/bin_search.hpp"
#include "utility/rng.hpp"
void lowerTest() {
    const auto N = rng.val<i64>(2, 1000000000);
    const auto R = binSearch(N, 0, [&](i64 i) {
        return i * i <= N;
    });
    assert(R * R <= N);
    assert((R + 1) * (R + 1) > N);
}
void upperTest() {
    const auto N = rng.val<i64>(2, 1000000000);
    const auto R = binSearch(0, N, [&](i64 i) {
        return i * i >= N;
    });
    assert(R * R >= N);
    assert((R - 1) * (R - 1) < N);
}
int main() {
    lowerTest();
    upperTest();
    return 0;
}
