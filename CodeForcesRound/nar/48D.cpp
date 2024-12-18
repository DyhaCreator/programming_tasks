#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct int2{
    int x, index;
    int2() {}
    int2(int x, int index) {
        this->x = x;
        this->index = index;
    }
};

bool comp(int2 a, int2 b) {
    return a.x < b.x;
}

int main() {
    int n;
    cin >> n;
    vector<int2>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x;
        a[i].index = i;
    }
    sort(a.begin(), a.end(), comp);
    vector<int>mp(100010);
    for (auto &x : a) {
        mp[x.x - 1]++;
    }
    for (int i = 1; i < 100010; i++) {
        if (mp[i - 1] < mp[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    /*for (auto &x : a)
        cout << x.x << " ";
    cout << endl;*/
    vector<int>ans(n);

    int an = 1;
    ans[a[0].index] = an;
    //cout << an << " ";

    for (int i = 1; i < n; i++) {
        an++;
        if (a[i - 1].x != a[i].x) {
            an = 1;
        }
        ans[a[i].index] = an;
        //cout << an << " ";
    }
    //cout << endl;
    cout << mp[0] << endl;
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}