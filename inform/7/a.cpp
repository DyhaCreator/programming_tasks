#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int sum(int n) {
    int ans = 0;
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

bool comp(int a, int b) {
    return sum(a) < sum(b);
}

int main() {
    ifstream in("file");
    vector<int> a = {};
    int n;
    while (in >> n) a.push_back(n);
    sort(a.begin(), a.end(), comp);
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
    return 0;
}