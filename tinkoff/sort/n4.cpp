#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int ans = 0;

struct skier{
    int time, kilo = 0;
    skier() {}
};

bool comp(skier a, skier b) {
    return a.kilo > b.kilo;
}

int main() {
    int n, l;
    cin >> n >> l;
    vector<skier>a = vector<skier>(n);
    for (auto &x : a)
        cin >> x.time;
    return 0;
}