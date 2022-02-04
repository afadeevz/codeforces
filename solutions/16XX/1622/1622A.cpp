#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool solve(int a, int b, int c) {
    if (a == b + c) {
        return true;
    }
    if (b == c && a % 2 == 0) {
        return true;
    }

    return false;
}

void run() {
    int a, b, c;
    cin >> a >> b >> c;
    if (solve(a, b, c) || solve(b, a, c) || solve(c, a, b)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // int t = 1;
    int t; cin >> t;
    while (t--) {
        run();
    }
}