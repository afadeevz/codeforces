#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int h, w, w1, h1, w2, h2;

    cin >> w >> h >> w1 >> h1 >> w2 >> h2;

    while (h) {
        w += h;
        if (h == h1) {
            w -= w1;
        }
        if (h == h2) {
            w -= w2;
        }
        w = max(w, 0);
        h--;
    }

    cout << w << endl; 
    return 0;
}