#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
#include <unordered_map>
#include <set>

using namespace std;

void run() {
    string g = "ACTG";
    int n;
    string s;
    cin >> n >> s;

    auto dist = [&](char a, char b) {
        if (a == b) {
            return 0;
        } else if (a > b) {
            if (a - b <= 13) {
                return a - b;
            } else {
                return 26 - a + b;
            }
        } else {
            if (b - a <= 13) {
                return b - a;
            } else {
                return 26 - b + a;
            }
        }
    };

    auto solve = [&](int i) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += dist(s[i + j], g[j]);
        }
        return sum;
    };

    int ans = 999;
    for (int i = 0; i <= n - 4; i++) {
        ans = min(ans, solve(i));
    }

    cout << ans << endl;
}

int main() {
    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        run();
    }
}