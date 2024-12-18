#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct member{
    int num, points;
    member() {}
    member(int num, int points) {
        this->num = num;
        this->points = points;
    }
};

bool comp(member a, member b) {
    if (a.points == b.points) {
        return a.num < b.num;
    }
    return a.points > b.points;
}

int main() {
    int n;
    cin >> n;
    vector<member>arr = vector<member>(n);
    for (auto &x : arr)
        cin >> x.num >> x.points;
    sort(arr.begin(), arr.end(), comp);
    for (auto x : arr)
        cout << x.num << " " << x.points << endl;
    return 0;
}