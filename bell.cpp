#include "bell.h"

void printPart(ostream &out, vi p) {
    int numPartitions = *max_element(p.begin(), p.end());

    REP(q, numPartitions + 1) {
        REP(i, p.size())
			if (p[i] == q)
			{
				out << i << " ";
                cout << i << " ";
			}
		out << "| ";
        cout << "| ";
	}
	out << endl;
    cout << endl;

}

bool next(vi &p, vi &m) {
    int n = p.size();
	int i = 0;
	p[i]++;
	while ((i < n - 1) && (p[i] > m[i] + 1)) {
		p[i] = 0;
		i++;
		p[i]++;
	}

	if (i == n - 1) return false;

    int max = p[i];
    if (m[i] > max) max = m[i];
    REP(j, i) m[j] = max;

	return true;
}

//int solve(int n, int k, int m) {
//    vi p(n, 0); // p is the actual partition
//    vi max(n, 0); // m[i] is max_{i <= j <= n-1} p[j]
//
//    int tot = 1;
//    while (next(p, max))
//        tot++;
//    return tot;
//}
