#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void sort(vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 1; j < a.size(); j++) {
            if (a[j] < a[j - 1]) {
                int buffer = a[j];
                a[j] = a[j - 1];
                a[j - 1] = buffer;
            }
        }
    }
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