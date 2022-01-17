#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void run() {
    int n, m;
    cin >> n;
    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;

    auto shoot = [&](int x, int y) {
        if (x > 0) {
            a[x - 1] += y - 1;
        }
        if (x < n - 1) {
            a[x + 1] += a[x] - y;
        }
        a[x] = 0;
    };

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        shoot(x, y);
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}

int main() {
    int t = 1;
    // int t; cin >> t;
    while (t--) {
        run();
    }
}