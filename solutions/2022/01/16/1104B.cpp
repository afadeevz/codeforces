#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

using namespace std;

void run() {
    string s;
    cin >> s;
    vector<char> v;
    int moves = 0;
    for (auto c : s) {
        v.push_back(c);
        if (v.size() < 2) {
            continue;
        }

        if (v.back() == *(v.end() - 2)) {
            v.pop_back();
            v.pop_back();
            moves++;
        }
    }

    cout << ((moves % 2) ? "YES" : "NO") << '\n';
}

int main() {
    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        run();
    }
}