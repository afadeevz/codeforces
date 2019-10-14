#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    if (2 * m < n) {
        cout << m;
    } else if (2 * n < m) {
        cout << n;
    } else {
        cout << (m + n) / 3;
    }
    cout << endl;
}