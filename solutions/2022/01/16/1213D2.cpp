#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

using namespace std;

void run() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    a.resize(n);

    vector<vector<int>> s;
    s.resize(200001);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int x = a[i];
        s[x].push_back(0);
        int d = 0;
        do {
            x /= 2;
            d++;
            s[x].push_back(d);
        } while (x > 0);
    }

    for (int i = 0; i <= 200000; i++) {
        sort(s[i].begin(), s[i].end());
    }

    auto calc = [&](int i) {
        if (s[i].size() < k) {
            return k * 100;
        }
        int sum = 0;
        for (int j = 0; j < k; j++) {
            sum += s[i][j];
        }
        return sum;
    };

    int ans = calc(0);
    for (int i = 1; i <= 200000; i++) {
        ans = min(ans, calc(i));
    }

    cout << ans << endl;
}

int main() {
    int t = 1;
    // int t; cin >> t;
    while (t--) {
        run();
    }
}