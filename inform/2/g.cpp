#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for (int i = 0; i < k; i++) {
        int id, nnn;
        cin >> id >> nnn;
        id--;
        if (nnn == 8) {
            if (a[id].size() > 0) a[id].pop_back();
        } else {
            a[id].push_back(char(nnn));
        }
    }
    for (auto &x : a) {
        for (auto &y : x) if(y == 13) cout << "//";
        else cout << y;
        cout << endl;
    }
    return 0;
}