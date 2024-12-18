#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void sort(vector<int>&a) {
    if (a.size() <= 1) {
        return;
    }
    vector<int>l = vector<int>();
    vector<int>r = vector<int>();
    int m = a.size() / 2;
    for (int i = 0; i < a.size(); i++) {
        if (i != m && a[i] <= a[m]) {
            l.push_back(a[i]);
        } else if (i != m && a[i] > a[m]) {
            r.push_back(a[i]);
        }
    }
    sort(l);
    sort(r); 
    l.push_back(a[m]);
    for (auto x : r)
        l.push_back(x);
    a = l;
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