#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*

*/

void run() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    
    int sa = 0, sb = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            sa++;
        } else {
            sa--;
        }
        if (b[i] == '1') {
            sb++;
        } else {
            sb--;
        }

        if (abs(sa) != abs(sb)) {
            cout << "NO\n";
            return;
        }
    }
    if (sa != 0 && a.back() != b.back()) {
            cout << "NO\n";
            return;
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