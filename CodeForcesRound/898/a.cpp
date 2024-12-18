#include <iostream>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        if (a1 == 'a') {
            cout << "YES" << endl;
        } else if (a1 == 'b') {
            if (a2 == 'a') {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            if (a2 == 'a') {
                cout << "NO" << endl;
            } else {
                cout << " YES" << endl;
            }
        }
    }
    return 0;
}