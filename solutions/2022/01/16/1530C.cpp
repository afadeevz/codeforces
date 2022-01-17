#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

using namespace std;

void run() {
    int n;
    cin >> n;
    vector<int> a, b;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    vector<int> sa, sb;
    sa.resize(n + 1);
    sb.resize(n + 1);
    sa[0] = sb[0] = 0;
    for (int i = 0; i < n; i++) {
        sa[i + 1] = sa[i] + a[i];
        sb[i + 1] = sb[i] + b[i];
    }

    auto ok = [&](int m) {
        int q = (m + n) - (m + n) / 4;
        
        int pa = 100 * m + sa[max(q - m, 0)];
        int pb = sb[min(q, n)]; 
        return pa >= pb;
    };

    int l = 0, r = 10 * n;
    while (l != r) {
        int m = (l + r) / 2;
        if (!ok(m)) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    cout << l << endl;
}

int main() {
    int t;
    cin >> t;
    // t = 1;
    while (t--) {
        run();
    }
}