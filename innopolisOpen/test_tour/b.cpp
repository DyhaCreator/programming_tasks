#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a = vector<int>(n);
    for (auto &x : a)
        cin >> x;
    reverse(a.begin(), a.end());
    return 0;
}