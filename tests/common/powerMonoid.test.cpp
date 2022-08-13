#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_A"
#include "../../src/common/power.hpp"

struct M
{
    friend M operator*(const M& m1, const M& m2)
    {
        M m;
        m.vss[0][0] = m.vss[0][1] = m.vss[1][0] = m.vss[1][1] = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) { m.vss[i][j] += m1.vss[i][k] * m2.vss[k][j]; }
            }
        }
        return m;
    }
    friend M& operator*=(M& m1, const M& m2) { return m1 = (m1 * m2); }
    static M I()
    {
        M m;
        m.vss[0][0] = m.vss[1][1] = 1;
        m.vss[0][1] = m.vss[1][0] = 0;
        return m;
    }
    Arr<Arr<i64, 2>, 2> vss;
};

int main()
{
    int N;
    std::cin >> N;
    M mat;
    mat.vss[0][0] = mat.vss[0][1] = mat.vss[1][0] = 1;
    mat.vss[1][1] = 0;
    const M ans = powerMonoid(mat, N, M::I());
    std::cout << ans.vss[1][0] + ans.vss[1][1] << "\n";
    return 0;
}
