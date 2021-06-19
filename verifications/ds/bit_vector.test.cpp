#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../src/ds/bit_vector.hpp"

void Test()
{
    const int N = 1000;
    std::mt19937 mt{std::random_device{}()};
    std::uniform_int_distribution<int> dist(0, N - 1);

    BitVector bvec(N);
    for (int t : rep(200)) {
        USE(t);
        const int i = dist(mt);
        bvec.set(i);
    }
    for (int t : rep(50)) {
        USE(t);
        const int i = dist(mt);
        bvec.reset(i);
    }
}

void rankTest()
{
    const int N = 1000;
    std::mt19937 mt{std::random_device{}()};
    std::uniform_int_distribution<int> dist(0, N - 1);

    BitVector bvec(N);
    Vec<int> bs(N, 0);
    for (int t : rep(200)) {
        USE(t);
        const int i = dist(mt);
        bvec.set(i);
        bs[i] = 1;
    }

    auto rank0 = [&](int i) {
        int ans = 0;
        for (int j : rep(i)) {
            if (bs[j] == 0) { ans++; }
        }
        return ans;
    };
    auto rank1 = [&](int i) {
        int ans = 0;
        for (int j : rep(i)) {
            if (bs[j] == 1) { ans++; }
        }
        return ans;
    };
    for (int t : rep(200)) {
        USE(t);
        const int i = dist(mt);
        assert(rank0(i) == bvec.rank0(i));
    }
    for (int t : rep(200)) {
        USE(t);
        const int i = dist(mt);
        assert(rank1(i) == bvec.rank1(i));
    }
    assert(rank0(N) == bvec.zero());
    assert(rank1(N) == bvec.one());
}

void selectTest()
{
    const int N = 1000;
    std::mt19937 mt{std::random_device{}()};
    std::uniform_int_distribution<int> dist(0, N - 1);

    BitVector bvec(N);
    for (int t : rep(200)) {
        USE(t);
        const int i = dist(mt);
        bvec.set(i);
    }

    for (int t : rep(200)) {
        USE(t);
        const int k = dist(mt);
        const int i = bvec.select0(k);
        if (i == N) {
            assert(bvec.zero() <= k);
        } else {
            assert(bvec.rank0(i) == k);
        }
    }
    for (int t : rep(200)) {
        USE(t);
        const int k = dist(mt);
        const int i = bvec.select1(k);
        if (i == N) {
            assert(bvec.one() <= k);
        } else {
            assert(bvec.rank1(i) == k);
        }
    }
}

int main()
{
    Test();
    rankTest();
    selectTest();
    std::cout << "Hello World\n";
    return 0;
}
