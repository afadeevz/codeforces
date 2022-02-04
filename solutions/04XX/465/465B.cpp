#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x;
    for (int i = 0; i < n; i++) {
        int xi;
        cin >> xi;
        x.push_back(xi);
    }

    int g = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 && x[i]) {
            g++;
        }
        if (i != 0 && !x[i - 1] && x[i]) {
            g++;
        }
        if (x[i]) {
            c++;
        }
    }

    if (c == 0) {
        cout << 0 << endl;
    } else {
        cout << c + g - 1 << endl;
    }
}