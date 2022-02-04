#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        int d = y - x;
        if (d % (a + b) == 0) {
            cout << d / (a + b) << endl;
        } else {
            cout << "-1\n";
        }
    }
}