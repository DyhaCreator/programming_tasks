#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void sort(vector<int>&a) {
    for (int i = 0; i < a.size(); i++) {
        for (auto x : a)
            cout << x << " ";
        cout << endl;
        int max_index = i;
        for (int j = i; j < a.size(); j++) {
            if (a[j] > a[max_index]) {
                max_index = j;
            }
        }
        int buffer = a[i];
        a[i] = a[max_index];
        a[max_index] = buffer;
    }
    reverse(a.begin(), a.end());
}

int main() {
    int n;
    cin >> n;
    vector<int>a = vector<int>(n);
    for (auto &x : a)
        cin >> x;
    sort(a);
    for (auto x : a)
        cout << x << " ";
    cout << endl;
    return 0;
}