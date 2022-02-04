#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void run() {
    string w, s;
    int x;
    cin >> s >> x;
    int n = s.length();
    w.resize(n);
    for (int i = 0; i < n; i++) {
        if (i + x < n && s[i + x] == '1') {
            w[i] = '1';
        } else if (i - x >= 0 && s[i - x] == '1') {
            w[i] = '1';
        } else {
            w[i] = '0';
        }
    }

    for (int i = 0; i < n; i++) {
        if (i + x < n && s[i] == '0' && w[i + x] == '1') {
            cout << "-1\n";
            return;
        }
        if (i - x >= 0 && s[i] == '0' && w[i - x] == '1') {
            cout << "-1\n";
            return;
        }
        if (i + x < n && i - x >= 0 && s[i] == '1' && w[i - x] == '0' && w[i + x] == '0') {
            cout << "-1\n";
            return;
        }
    }

    cout << w << endl;
}

int main() {
    int t;
    cin >> t;
    // t = 1;
    while (t--) {
        run();
    }
}