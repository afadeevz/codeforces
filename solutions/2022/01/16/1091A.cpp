#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void run() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 3 * min(a, min(b - 1, c - 2)) + 3;
    cout << ans << endl;
}

int main() {
    int t = 1;
    // int t; cin >> t;
    while (t--) {
        run();
    }
}