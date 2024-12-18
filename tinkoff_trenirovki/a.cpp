#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

struct int2{
    int x = 0, y = 0;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int>qvec = vector<int>(q);
    for (auto &x : qvec)
        cin >> x;
    vector<int2>ot = vector<int2>();
    ot.push_back(int2(1, n - 1));
    map<int, int>mp;
    for (auto x : qvec)
        mp[x] = 0;
    mp[1] = 1;
    mp[n] = 1;
    while (true) {
        bool b = true;
        
        if (b) break;
    }
    return 0;
}