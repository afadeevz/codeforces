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
    string s;
    cin >> s;

    int nm = 0, nt = 0;
    FOR(int, i, 0, n) {
        if (s[i] == 'T') {
            nt++;
        } else if (s[i] == 'M') {
            nm++;
            if (nm > nt) {
                cout << "NO\n";
                return;
            }
        }
    }
    if (nm * 3 != n) {
        cout << "NO\n";
        return;
    }
    nm = 0, nt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'T') {
            nt++;
        } else if (s[i] == 'M') {
            nm++;
            if (nm > nt) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main() {
    // int t = 1;
    int t; cin >> t;
    while (t--) {
        run();
    }
}