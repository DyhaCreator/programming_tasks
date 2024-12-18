#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int my_sort(int start, int end, vector<int> &a) {
    for (int i = start; i < end; i++) {
        for (int j = start + 1; j < end; j++) {
            if (a[j] < a[j - 1]) {
                int buffer = a[j];
                a[j] = a[j - 1];
                a[j - 1] = buffer;
            }
        }
    }
    return 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    int b = n - 1;
    while (k - b >= 0 && b >= 1) {
        k -= b;
        // cout << k << " " << b << endl;
        a.push_back(b + 1);
        b--;
    }
    int start_size = a.size();
    while (a.size() < n) {
        a.push_back(a.size() - start_size + 1);
    }
    /*for (auto &x : a)
        cout << x << " ";
    cout << endl;*/

    
    int buffer = a[n - k - 1];
    a[n - k - 1] = a[n - 1];
    a[n - 1] = buffer;

    my_sort(n - k, n, a);


    for (auto &x : a)
        cout << x << " ";
    cout << endl;

    return 0;
}