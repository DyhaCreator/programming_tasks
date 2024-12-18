#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void rec(int n, vector<int>a) {
    if (n == 0) {
        for (auto x : a)
            cout << x;
        cout << endl;
        return;
    }
    a.push_back(0);
    rec(n - 1, a);
    a[a.size() - 1]++;
    rec(n - 1, a);
}

int main() {
    int n;
    cin >> n;
    rec(n, vector<int>());
    return 0;
}