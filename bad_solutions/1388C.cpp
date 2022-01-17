#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

using namespace std;

void run() {
    int n, m;
    cin >> n >> m;
    vector<int> p, h;
    p.resize(n + 1);
    h.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    struct City {
        vector<int> e;
    };
    vector<City> c;
    c.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        c[x].e.push_back(y);
        c[y].e.push_back(x);
    }

    vector<char> v;
    v.resize(n + 1);

    bool ok = true;

    auto dfs = [&](int i, int pr, auto&& dfs) -> void {
        v[i] = true;
        h[pr] -= h[i];

        for (int j = 0; j < c[i].e.size(); j++) {
            int k = c[i].e[j];
            if (v[k]) {
                continue;
            }

            dfs(k, i, dfs);
        }

        if ((p[i] + h[i]) % 2) {
            ok = false;
        }

        if (p[i] < abs(h[i])) {
            ok = false;
        }
    };

    dfs(1, 0, dfs);

    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    // int t = 1;
    int t; cin >> t;
    while (t--) {
        run();
    }
    return 0;
}