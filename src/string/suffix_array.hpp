#pragma once
#include "../common.hpp"

template<typename V> Vec<int> suffixArray(const V& vs)
{
    const int N = (int)std::size(vs);
    const int B = maxAll(vs) + 1;
    auto val    = [&](int i) { return (i == N ? 0 : vs[i] + 1); };
    Vec<bool> is_s(N + 1, true);
    for (int i : per(N)) { is_s[i] = val(i) == val(i + 1) ? is_s[i + 1] : val(i) < val(i + 1); }
    auto isS           = [&](int i) { return is_s[i]; };
    auto isL           = [&](int i) { return not isS(i); };
    auto isLms         = [&](int i) { return i > 0 and isL(i - 1) and isS(i); };
    auto sameLmsSubstr = [&](int i, int j) {
        if (val(i++) != val(j++)) { return false; }
        while (i <= N and j <= N) {
            if (val(i) != val(j)) { return false; }
            if (isLms(i)) { i = N; }
            if (isLms(j)) { j = N; }
            i++, j++;
        }
        return i >= N and j >= N;
    };
    Vec<int> poss = Vec<int>(B + 2, 0);
    for (int i : rep(N + 1)) { poss[val(i) + 1]++; }
    for (int b : rep(B + 1)) { poss[b + 1] += poss[b]; }

    Vec<int> sa(N + 1, -1);
    auto inducedSort = [&](const Vec<int>& lmss) {
        fillAll(sa, -1);
        Vec<int> inds = Vec<int>(B + 1, 0);
        auto pushL    = [&](int i) {
            if (i >= 0 and isL(i)) { sa[inds[val(i)]++] = i; }
        };
        auto pushS = [&](int i) {
            if (i >= 0 and isS(i)) { sa[--inds[val(i)]] = i; }
        };
        // 下からLMSを詰める
        for (int b : rep(B + 1)) { inds[b] = poss[b + 1]; }
        std::for_each(std::rbegin(lmss), std::rend(lmss), [&](int lms) { pushS(lms); });
        // 上からLを詰める
        for (int b : rep(B + 1)) { inds[b] = poss[b]; }
        for (int i : rep(N + 1)) { pushL(sa[i] - 1); }
        // 下からSを詰める
        for (int b : irange(1, B + 1)) { inds[b] = poss[b + 1]; }
        for (int i : per(N + 1)) { pushS(sa[i] - 1); }
    };

    Vec<int> lmss;  // LMSを登場順に詰めたもの
    for (int i : rep(N + 1)) {
        if (isLms(i)) { lmss.push_back(i); }
    }
    const int LMS = lmss.size();
    inducedSort(lmss);  // テキトーに一回IS
    if (LMS > 1) {
        Vec<int> nlmss;  // LMS Substrの中身でソートしたLMS
        for (int i : rep(N + 1)) {
            if (isLms(sa[i])) { nlmss.push_back(sa[i]); }
        }
        Vec<int> kinds(N + 1, 0);
        for (int ii : irange(1, LMS)) {
            const int lms = nlmss[ii], plms = nlmss[ii - 1];
            kinds[lms] = kinds[plms] + 1;
            if (sameLmsSubstr(plms, lms)) { kinds[lms]--; }
        }
        Vec<int> sub_vs(LMS);
        for (int i : rep(LMS)) { sub_vs[i] = kinds[lmss[i]]; }
        // LMSをソートする
        const auto lmss_ords = suffixArray(sub_vs);
        for (int i : rep(LMS)) { nlmss[i] = lmss[lmss_ords[i]]; }
        // 正しいLMS順でIS
        inducedSort(nlmss);
    }
    return Vec<int>(std::begin(sa) + 1, std::end(sa));
}
