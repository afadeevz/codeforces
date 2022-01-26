#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define LL long long
#define FOR(T, i, l, r) for (T i = l; i < r; i++)
#define SORT(x) sort(x.begin(), x.end())
#define RSORT(x) sort(x.rbegin(), x.rend())
#define READN(x, n) FOR(size_t, i, 0, n) {cin >> x[i];}

void run() {
    int n, m;
    cin >> n >> m;
    vector<vector<unsigned>> a(n + 1);
    for (int i = 0; i <= n; i++) {
        a[i].resize(1 << i);
    }
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[n][i];
    }

    auto calc = [&](bool b, int i, int j) {
        if (b) {
            a[i][j] = a[i + 1][j * 2] | a[i + 1][j * 2 + 1];
        } else {
            a[i][j] = a[i + 1][j * 2] ^ a[i + 1][j * 2 + 1];
        }
    };

    bool b = true;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < (1 << i); j++) {
            calc(b, i, j);
        }
        b = !b;
    }

    auto update = [&](int j, int x) {
        a[n][j] = x;
        bool b = true;
        for (int i = n - 1; i >= 0; i--) {
            j /= 2;
            calc(b, i, j);
            b = !b;
        }
    };

    for (int i = 0; i < m; i++) {
        int j, x;
        cin >> j >> x;
        update(j - 1, x);
        cout << a[0][0] << endl;
    }

}

int main() {
    int t = 1;
    // int t; cin >> t;
    while (t--) {
        run();
    }
}