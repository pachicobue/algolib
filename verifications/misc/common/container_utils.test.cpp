#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../../src/common/container_util.hpp"

void minIndTest()
{
    std::vector<int> vs{2, 1, 1, 3, 3, 2};
    assert(minInd(vs) == 1);
}

void maxIndTest()
{
    std::vector<int> vs{2, 1, 1, 3, 3, 2};
    assert(maxInd(vs) == 3);
}

void lbIndTest()
{
    std::vector<int> vs{1, 1, 3, 3, 3, 5, 5};
    assert(lbInd(vs, 0) == 0);
    assert(lbInd(vs, 1) == 0);
    assert(lbInd(vs, 5) == 5);
    assert(lbInd(vs, 6) == 7);
}

void ubIndTest()
{
    std::vector<int> vs{1, 1, 3, 3, 3, 5, 5};
    assert(ubInd(vs, 0) == 0);
    assert(ubInd(vs, 1) == 2);
    assert(ubInd(vs, 5) == 7);
    assert(ubInd(vs, 6) == 7);
}

void genVecTest()
{
    int x = 1;
    auto gen = [&]() {
        const int y = x;
        x *= 2;
        return y;
    };
    auto vs = genVec<int>(5, gen);
    assert(vs == std::vector<int>({1, 2, 4, 8, 16}));
}

void iotaVecTest()
{
    auto vs = iotaVec(5, 2);
    assert(vs == std::vector<int>({2, 3, 4, 5, 6}));
}

int main()
{
    minIndTest();
    maxIndTest();
    lbIndTest();
    ubIndTest();
    genVecTest();
    iotaVecTest();

    std::cout << "Hello World\n";
    return 0;
}
