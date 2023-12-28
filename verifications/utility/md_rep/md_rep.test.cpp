// verification-helper: UNITTEST
#include "utility/md_rep.hpp"
#include "utility/rng.hpp"
void test()
{
    const auto N  = 50;
    const auto xs = rng.vec<int>(N, -100, 100);
    const auto ys = rng.vec<int>(N, -100, 100);
    const auto zs = rng.vec<int>(N, -100, 100);
    int index     = 0;
    for (const auto& vs : mdRep<int>({xs, ys, zs})) {
        const int xi = index / (N * N), yi = (index / N) % N, zi = index % N;
        assert(vs[0] == xs[xi]);
        assert(vs[1] == ys[yi]);
        assert(vs[2] == zs[zi]);
        index++;
    }
}
int main()
{
    test();
    return 0;
}
