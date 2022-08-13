#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../../src/graph/tree/la.hpp"

void Test()
{
    Graph g(10);
    g.addEdge(1, 2, true);
    g.addEdge(2, 0, true);
    g.addEdge(2, 3, true);
    g.addEdge(1, 9, true);
    g.addEdge(1, 4, true);
    g.addEdge(4, 5, true);
    g.addEdge(4, 8, true);
    g.addEdge(5, 6, true);
    g.addEdge(5, 7, true);
    LevelAncestor la(g, 1);
    assert(la(0, 0) == 0);
    assert(la(0, 1) == 2);
    assert(la(0, 2) == 1);

    assert(la(1, 0) == 1);

    assert(la(2, 0) == 2);
    assert(la(2, 1) == 1);

    assert(la(3, 0) == 3);
    assert(la(3, 1) == 2);
    assert(la(3, 2) == 1);

    assert(la(4, 0) == 4);
    assert(la(4, 1) == 1);

    assert(la(5, 0) == 5);
    assert(la(5, 1) == 4);
    assert(la(5, 2) == 1);

    assert(la(6, 0) == 6);
    assert(la(6, 1) == 5);
    assert(la(6, 2) == 4);
    assert(la(6, 3) == 1);

    assert(la(7, 0) == 7);
    assert(la(7, 1) == 5);
    assert(la(7, 2) == 4);
    assert(la(7, 3) == 1);

    assert(la(8, 0) == 8);
    assert(la(8, 1) == 4);
    assert(la(8, 2) == 1);

    assert(la(9, 0) == 9);
    assert(la(9, 1) == 1);
}
int main()
{
    Test();
    std::cout << "Hello World\n";
    return 0;
}
