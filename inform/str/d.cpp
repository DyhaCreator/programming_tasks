#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string a;
    getline(cin, a);
    getline(cin, a);
    reverse(a.begin(), a.end());
    string b = "";
    for (int i = 0; i < min(n, int(a.size())); i++)
        b.push_back(a[i]);
    while (b.size() < n) b.push_back('.');
    reverse(b.begin(), b.end());
    cout << b << endl;
    return 0;
}