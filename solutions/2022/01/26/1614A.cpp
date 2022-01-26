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
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    vector<int> a(n);
    READN(a, n);
    SORT(a);
    
    int i = 0;
    while (a[i] < l) {
        i++;
    }

    int ans = 0;
    LL s = 0;
    for (; i < n && a[i] <= r; i++) {
        if (s + a[i] > k) {
            break;
        }
        ans++;
        s += a[i];
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