#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void run() {
    int t, x1, y1, x2, y2;
    string s;
    cin >> t >> x1 >> y1 >> x2 >> y2 >> s;

    auto dist = [&](int x, int y) {
        return abs(x - x2) + abs(y - y2);
    };

    for (int i = 0; i < t; i++) {
        int x = x1, y = y1;
        switch (s[i]) {
        case 'E':
            x++;
            break;
        case 'W':
            x--;
            break;
        case 'N':
            y++;
            break;
        case 'S':
            y--;
            break;
        }

        if (dist(x, y) < dist(x1, y1)) {
            x1 = x;
            y1 = y;
        }

        if (x1 == x2 && y1 == y2) {
            cout << i + 1 << endl;;
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    int t = 1;
    // int t; cin >> t;
    while (t--) {
        run();
    }
}