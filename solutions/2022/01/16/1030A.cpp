#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x) {
            cout << "HARD\n";
            return 0;
        }
    }
    
    cout << "EASY\n";
    return 0;
}