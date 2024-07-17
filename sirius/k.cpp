#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (int i = 0; i < k; i++) {
        int min_index = i;
        for (int j = i; j < n; j++) {
            if (a[j] > a[min_index]) {
                min_index = j;
            }
        }
        int buffer = a[min_index];
        a[min_index] = a[i];
        a[i] = buffer;
        /*for (auto &x : a)
            cout << x << " ";
        cout << endl;*/
    }
    cout << a[k - 1] << endl;
    return 0;
}