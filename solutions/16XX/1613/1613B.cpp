#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define LL long long
#define FOR(T, i, l, r) for (T i = l; i < r; i++)
#define SORT(x) sort(x.begin(), x.end())
#define RSORT(x) sort(x.rbegin(), x.rend())
#define READN(x, n) FOR(size_t, i, 0, n) {cin >> x[i];}

void run() {
    int n;
    cin >> n;
    vector<unsigned> a(n);
    READN(a, n);
    SORT(a);

    
    vector<pair<unsigned, unsigned>> ans;
    vector<unsigned> ds;
    for (int d = 2; d < 1000000; d++) {
        for (auto dsi : ds) {
            if (d % dsi == 0) {
                goto next;
            }
        }
        ds.push_back(d);

        vector<unsigned> b;
        for (auto x : a) {
            if (x % d == 0) {
                continue;
            }

            b.push_back(x);
        }

        for (int i = 0; i < b.size(); i++) {
            for (int j = i + 1; j < b.size(); j++) {
                if (i > j) {
                    ans.emplace_back(i, j);
                } else {
                    ans.emplace_back(j, i);
                }
                if (ans.size() >= n / 2) {
                    for (auto x : ans) {
                        cout << x.first << ' ' << x.second << endl;
                    }
                    return;
                }
            }
        }

        next:
    }

/*
    set<unsigned> a;
    FOR(int, i, 0, n) {
        int x;
        cin >> x;
        a.insert(x);
    }
    vector<pair<unsigned, unsigned>> ans;
    for (auto i = a.begin(); i != a.end(); ++i) {
        for (auto j = a.begin(); j != i; ++j) {
            auto r = *i % *j;
            if (a.find(r) != a.end()) {
                continue;
            }
            ans.push_back({*i, *j});
            if (ans.size() >= n / 2) {
                for (auto x : ans) {
                    cout << x.first << ' ' << x.second << endl;
                }
                return;
            }
        }
    }
    */
}

int main() {
    // int t = 1;
    int t; cin >> t;
    while (t--) {
        run();
    }
}