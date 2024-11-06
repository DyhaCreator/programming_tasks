#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ifstream in("file");
    vector<int> a = {};
    int n;
    while (in >> n) a.push_back(n);
    int ans1 = -1;
    int ans2 = INF;
    for (auto &x : a) {
        if ((x & 1) == 0 && x > 0) {
            ans1 = max(ans1, x);
            ans2 = min(ans2, x);
        }
    }
    ofstream out("out");
    if (ans1 != -1)
        out << ans1 << " " << ans2 << endl;
    return 0;
}