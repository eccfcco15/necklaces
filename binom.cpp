#include "binom.h"

vi N(int n) {
    vi ans(n, 0);
    REP(i,n) ans[i] = i+1;
    return ans;
}

l binom(l n, l k) {
    if (n == k || k == 0) return 1;
    if (n == 1) return 1;
    return binom(n-1, k-1) + binom(n-1, k);
}
