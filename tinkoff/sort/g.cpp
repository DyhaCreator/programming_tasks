#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll>a = vector<ll>(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    for (auto x : a)
        cout << x << " ";
    cout << endl;
    return 0;
}