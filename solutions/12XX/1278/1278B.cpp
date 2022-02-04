#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void run() {
    int a, b;
    cin >> a >> b;

    int ans = 0;

    while (a != b) {
        if (a > b) {
            int c = a;
            a = b;
            b = c;
        }

        int d = b - a;
        if (d >= 2) {
            a += d / 2 * 2;
            ans += d / 2;
        } else {
            a += 1;
            ans += 1;
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