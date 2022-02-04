#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

using namespace std;

void run() {
    int n, l, r;
    cin >> n >> l >> r;
    array<int, 200001> al = {}, ar = {};
    for (int i = 0; i < l; i++) {
        int x;
        cin >> x;
        al[x]++;
    }
    for (int i = 0; i < r; i++) {
        int x;
        cin >> x;
        ar[x]++;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int x = min(al[i], ar[i]);
        al[i] -= x;
        ar[i] -= x;
        r -= x;
        l -= x;
    }

    for (int i = 1; i <= n && l != r; i++) {
        if (l > r && al[i] >= 2) {
            int x = min((l - r) / 2, al[i] / 2);
            ans += x;
            al[i] -= 2 * x;
            l -= 2 * x;
        } else if (r > l && ar[i] >= 2) {
            int x = min((r - l) / 2, ar[i] / 2);
            ans += x;
            ar[i] -= 2 * x;
            r -= 2 * x;
        }
    }

    int x = min(l, r);
    ans += x;
    l -= x;
    r -= x;
    x = max(l, r);
    ans += x;

    cout << ans << endl;
}

int main() {
    // int t = 1;
    int t; cin >> t;
    while (t--) {
        run();
    }
}