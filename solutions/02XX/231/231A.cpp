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
    int n;
    cin >> n;

    int ans = 0;

    FOR(int, i, 0, n) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c >= 2) {
            ans++;
        }
    }

    cout << ans;
}

int main() {
    int t = 1;
    // int t; cin >> t;
    while (t--) {
        run();
    }
}