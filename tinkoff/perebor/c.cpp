#include <iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

int nut, k;

int a[100] = {0};
int g = 0;
int d = 10000000;

void rec(int n, int pos, ll sum) {
    if (n == 0) {
        if (sum == k) {
            g++;
            /*for (int i = 0; i < nut; i++) {
                cout << a[i];
            }
            cout << endl;*/
        }
        if (g % d == 0) {
            for (int i = 0; i < nut; i++) {
                cout << a[i];
            }
            cout << endl;
        }
        return;
    }
    if (k - sum <= n - 1) {
        a[pos] = 0;
        rec(n - 1, pos + 1, sum);
    }
    if (sum < k) {
        a[pos] = 1;
        rec(n - 1, pos + 1, sum + 1);
    }
}

int main() {
    cin >> nut >> k;
    rec(nut, 0, 0);
    cout << g << endl;
    return 0;
}