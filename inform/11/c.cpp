#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

string f(string a) {
    int n = a.size();
    string b = "";
    n -= 2;
    int mn = n;
    for (int i = 0; i < n; i++) {
        vector<int> used(n);
        
    }
    return a[0] + b + a[n - 1];
}

int main() {
    setlocale(0, "");
    string s;
    while (getline(cin, s)) {
        cout << f(s) << endl;
    }
    return 0;
}