#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int nut, k;

int a[100] = {0};

void rec(int n, int pos) {
    if (n == 0) {
        for (int i = 0; i < nut; i++) {
            cout << a[i] << " ";
        } 
        cout << endl;
        return;
    }
    if (pos > 0) {
        for (int i = n; i < a[pos - 1]; i++) {
            a[pos] = i;
            rec(n - 1, pos + 1);
        }
    } else {
        for (int i = n; i <= k; i++) {
            a[pos] = i;
            rec(n - 1, pos + 1);
        }
    }
}

int main() {
    cin >> k >> nut;
    rec(nut, 0);
    return 0;
}