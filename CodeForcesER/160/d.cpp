#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#define ll long long
using namespace std;

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

int num = 0;

unordered_set<vector<int>, VectorHash>us;

vector<int> f(vector<int>a, int l, int r) {
    vector<int>lv = vector<int>();
    lv.insert(lv.end(), a.begin(), a.begin() + l);
    vector<int>rv = vector<int>();
    rv.insert(rv.end(), a.begin() + r + 1, a.end());
    int min = 1e9;
    for (int i = l; i <= r; i++) {
        min = std::min(min, a[i]);
    }
    vector<int>ans = vector<int>();
    ans.insert(ans.end(), lv.begin(), lv.end());
    ans.push_back(min);
    ans.insert(ans.end(), rv.begin(), rv.end());
    return ans;
} 

void rec(vector<int>a) {
    us.insert(a);
    for (int i = 1; i < a.size(); i++) {
        for (int j = 0; j < i; j++) {
            rec(f(a, j, i));
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int>a = vector<int>(n);
        for (auto &x : a)
            cin >> x;
        num = 0;
        us = unordered_set<vector<int>, VectorHash>();
        rec(a);
        cout << us.size() << endl;
    }
    /*for (auto x : us) {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }*/
    return 0;
}