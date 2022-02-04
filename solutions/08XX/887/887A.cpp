#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void run() {
    string s;
    cin >> s;

    int n = s.length();
    int i;
    for (i = 0; i < n && s[i] != '1'; i++) {}

    int k = 0;
    for (; i < n; i++) {
        if (s[i] == '0') {
            k++;
        }
    }
    cout << (k >= 6 ? "yes\n" : "no\n");
}

int main() {
    int t = 1;
    // int t; cin >> t;
    while (t--) {
        run();
    }
}