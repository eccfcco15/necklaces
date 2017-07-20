#include "a.h"

vi N(int n);

l binom(l n, l k);

template <class T>
vector<vector<T> > nCr(vector<T> N, int k) {
    vector<vector<T> > ans;

    vi p(N.size(), 0);
    REP(i, k) p[i] = 1;
    sort(p.begin(), p.end());

    do {
        vector<T> next;
        next.reserve(k);
        REP(i, N.size())
            if (p[i])
                next.push_back(N[i]);
        ans.push_back(next);
    } while (next_permutation(p.begin(), p.end()));

    return ans;
}
