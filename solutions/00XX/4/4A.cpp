#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
#include <unordered_map>
#include <set>

using namespace std;

struct Query {
    int l;
    int r;
    int k;
};

void run() {
    int w;
    cin >> w;
    bool ok = (w % 2 == 0) && w > 2; 
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        run();
    }
}