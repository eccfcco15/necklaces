#include "a.h"
#include "binom.h"
#include "bell.h"

bool verify(const vector<string> &pieces, const vi &p, int k) {
    int numPartitions = *max_element(p.begin(), p.end()) + 1;
    if (k != numPartitions) return false;

    vector<string> counts(k);
    REP(i, p.size())
        counts[p[i]].append(pieces[i]);

    REP(i, counts.size())
        sort(counts[i].begin(), counts[i].end());

    for (int i = 1; i < counts.size(); i++)
        if (counts[i-1] != counts[i])
            return false;

    cout << "pieces\n";
    REP(i, pieces.size()) cout << pieces[i] << " ";
    cout << endl;

    printPart(p);
    return true;
}

bool solve(const string &necklace, int n, int k) {
    int l = necklace.size();
    cerr << "trying " << n << " cuts...\n";
    vvi allCuttings = nCr(N(l-1), n);

    for (vi cutting : allCuttings) {
        vector<string> pieces;
        pieces.reserve(cutting.size() + 1);
        int start = 0;
        for (int i : cutting) {
            pieces.push_back(necklace.substr(start, i-start));
            start = i;
        }
        pieces.push_back(necklace.substr(start));

        vi p(n+1, 0);
        vi max(n+1, 0);

        if (verify(pieces, p, k)) {
            cout << "found!!!\n";
            return true;
        }
        while (next(p, max))
            if (verify(pieces, p, k)) {
                cout << "found!!!\n";
                return true;
            }
    }

    return false;
}

int main() {
    random_device rd;
    mt19937 g(rd());

    while (1) {
        cout << "> ";
        int k; cin >> k;
        if (k == 0) return 0;
        string necklace;
        cin >> necklace;
        
        int n = 0;
        do {
            n++;
        } while (!solve(necklace, n, k));
        cout << n << " cuts required\n";
    }
}
