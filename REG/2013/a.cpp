#include <iostream>
#define ll long long
#define dot .
using namespace std;

int main() {
    int g;
    cin >> g;
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if (g == 2) {
        cout << min(n, min(min(a, b), c)) << endl;
    } else {
        if (a < b && a < c) {
            cout << min(n, (min(b, c) + a) - n) << endl;
        } else if (b < a && b < c) {
            cout << min(n, (min(a, c) + b) - n) << endl;
        } else if (c < b && c < a) {
            cout << min(n, (min(a, b) + c) - n) << endl;
        }
    }
    return 0;
}

// 75 21 826064 idi nahui kirill sedov shluha ebana ti pohosh na penis idi nahui