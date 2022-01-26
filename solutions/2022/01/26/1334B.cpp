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
    LL n, x;
    cin >> n >> x;
    vector<LL> a(n);
    for (size_t i = 0; i < n; i++) {cin >> a[i];};
    sort(a.rbegin(), a.rend());

    LL sum = 0;
    FOR(int, k, 0, n) {
        if ((sum + a[k]) / (k + 1) < x) {
            cout << k << endl;
            return;
        }
        sum += a[k];
    }
    cout << n << endl;
}

int main() {
    // int t = 1;
    int t; cin >> t;
    while (t--) {
        run();
    }
}