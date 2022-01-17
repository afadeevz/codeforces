#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve(int a, int b, int c) {
    cout << max(0, max(b - a + 1, c - a + 1)) << ' ';
}

void run() {
    int a, b, c;
    cin >> a >> b >> c;
    solve(a, b, c);
    solve(b, a, c);
    solve(c, b, a);
    cout << endl;
}

int main() {
    // int t = 1;
    int t; cin >> t;
    while (t--) {
        run();
    }
}