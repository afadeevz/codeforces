#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void run() {
    int n, l, r;
    cin >> n >> l >> r;
    int mn = (n - l + 1) + (1 << l) - 2;
    int mx = (1 << (r - 1)) * (n - r + 2) - 1;
    cout << mn << ' ' << mx << endl;
}

int main() {
    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        run();
    }
}