#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void run() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a;
    a.resize(10);
    for (int i = 0; i < n; i++) {
        a[s[i] - '0']++;
    }

    auto ok = [&](int ans) {
        if (ans > a[8]) {
            return false;
        }
        int f = n - ans;
        if (f < 10 * ans) {
            return false;
        }
        return true;
    };
    int ans = 0;
    while (ok(ans + 1)) {
        ans++;
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