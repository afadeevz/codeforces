#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void run() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    auto get = [&](int i) {
        if (i == 0) {
            return false;
        }
        if (i > n) {
            return false;
        }
        return a[i-1] == '1';
    };

    auto erase = [&](int i) {
        if (i == 0) {
            return;
        }
        if (i > n) {
            return;
        }
        a[i-1] = '0';
    };

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i - 1] == '0') {
            continue;
        }

        if (!get(i)) {
            ans++;
        } else {
            if (get(i-1)) {
                ans++;
                erase(i-1);
            } else if (get(i+1)) {
                ans++;
                erase(i+1);
            }
        }
    }

    cout << ans << endl;
}

int main() {
    // int t = 1;
    int t; cin >> t;
    while (t--) {
        run();
    }
}