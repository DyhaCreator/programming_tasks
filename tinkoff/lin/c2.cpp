#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    vector<vector< int >> a = vector<vector< int >> (n, vector<int>(m));
    for (auto x : a)
        for (auto y : x)
            cin >> y;
    
    return 0;
}