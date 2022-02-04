#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void run() {
    int m, n;
    cin >> m >> n;
    vector<int> row, col;
    row.resize(m * n + 1);
    col.resize(m * n + 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            col[x] = j;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            row[x] = j;
        }
    }
    vector<vector<int>> a;
    a.resize(m);
    for (auto& r : a) {
        r.resize(n);
    }

    for (int i = 1; i <= m * n; i++) {
        a[row[i]][col[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    // int t = 1;
    int t; cin >> t;
    while (t--) {
        run();
    }
}