#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for (auto &x : a)
        cin >> x;
    int min_ind = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] < a[min_ind]) {
            min_ind = i;
        }
    }
    for (int i = 0; i + k < n + 1; i++) {
        if (a[i + k] < a[min_ind]) {
            min_ind = i + k - 1;
        }
        if (min_ind < i) {
            min_ind = i;
            for (int j = i; j < i + k; j++) {
                if (a[j] < a[min_ind]) {
                    min_ind = j;
                }
            }
        }
        cout << a[min_ind] << endl;
    }
    return 0;
}