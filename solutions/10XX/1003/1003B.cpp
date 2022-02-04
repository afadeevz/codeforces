#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
#include <unordered_map>
#include <set>

using namespace std;

void run() {
    int a, b, x;
    cin >> a >> b >> x;

    string s;
    s.reserve(a + b + 1);
    bool c = b > a;

    auto push = [&]() {
        if (c) {
            s.push_back('1');
            b--;
        } else {
            s.push_back('0');
            a--;
        }
    };

    for (int k = 0; k < x - 1; k++) {
        push();
        c ^= 1;
    }

    while (a && b) {
        push();
    }
    c ^= 1;
    while (a || b) {
        push();
    }

    cout << s << endl;
}

int main() {
    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        run();
    }
}