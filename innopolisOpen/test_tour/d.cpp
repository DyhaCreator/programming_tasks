#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>>a = vector<vector<int>>(n, vector<int>(n));
    for (auto &x : a)
        cin >> x;
    
    return 0;
}