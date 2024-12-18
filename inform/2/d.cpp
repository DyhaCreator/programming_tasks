#pragma ("Ofast")
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        a[x - 1]--;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) cout << "no" << endl;
        else cout << "yes" << endl;
    }
    return 0;
}