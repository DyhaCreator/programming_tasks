#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll min(ll a, ll b) {
    if (a < b) {
        return a;
    }
    return b;
}

int main() {
    int n;
    cin >> n;
    vector<int>a = vector<int>();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    ll max_sum = -1;
    ll max_index = 0;
    for (int i = 0; i < n; i++) {
        ll h = a[i];
        ll sum = h;
        for (int j = i + 1; j < n; j++) {
            h = min(a[j], h);
            sum += h;
        }
        h = a[i];
        for (int j = i - 1; j >= 0; j--) {
            h = min(a[j], h);
            sum += h;
        }
        if (sum > max_sum) {
            max_sum = sum;
            max_index = i;
        }
    }

    vector<int>h = vector<int>(n, 0);
    h[max_index] = a[max_index];
    for (int j = max_index + 1; j < n; j++) {
        h[j] = min(a[j], h[j - 1]);
    }
    h[max_index] = a[max_index];
    for (int j = max_index - 1; j >= 0; j--) {
        h[j] = min(a[j], h[j + 1]);
    }
    for (int i = 0; i < n; i++) {
        cout << h[i] << " ";
    }
    cout << endl;
    return 0;
}