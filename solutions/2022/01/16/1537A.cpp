#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a;
        a.resize(n);
        int s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }

        if (s == n) {
            cout << "0\n";
            continue;
        }

        if (s > n) {
            // n + k == s + 0*k
            cout << s - n << endl;
        }

        if (s < n) {
            // n + 1 == s + x
            cout << "1\n";
        }
    }
}