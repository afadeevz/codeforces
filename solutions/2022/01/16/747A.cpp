#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

using namespace std;

void run() {
    int n;
    cin >> n;

    int ans = 1;
    for (int a = 2; a * a <= n; a++) {
        if (n % a == 0) {
            ans = a;
        }
    }

    cout << ans << ' ' << n / ans << endl;
}

int main() {
    int t = 1;
    // int t; cin >> t;
    while (t--) {
        run();
    }
}