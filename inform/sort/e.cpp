#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

bool comp(const string &a, const string &b) {
    return a.size() < b.size();
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end(), comp);
    for (auto &x : a)
        cout << x << endl;
    return 0;
}