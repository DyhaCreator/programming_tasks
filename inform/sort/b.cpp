#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

bool comp(const int &a, const int &b) {
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end(), comp);
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
    return 0;
}