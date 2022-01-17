#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
#include <unordered_map>
#include <set>

using namespace std;

void run() {
    int n;
    cin >> n;
    vector<int> a;
    a.resize(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }

    sort(a.rbegin(), a.rend());
    int k = a[0];
    long long ans = 0;
    for (int i = 0; i < n && k > 0; i++) {
        if (k > a[i]) {
            k = a[i];
        }
        ans += k;
        k--;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    // t = 1;
    while (t--) {
        run();
    }
}