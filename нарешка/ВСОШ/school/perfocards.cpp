#include <iostream>
#include <string>
#include <vector>
#define ll long long

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string name;
    cin >> name;
    vector<vector<int>>per = vector<vector<int>>();
    vector<vector<char>>sym = vector<vector<int>>();
    for (int i = 0; i < n; i++) {
        int k;
        vector<int>p1 = vector<int>();
        vector<char>s1 = vector<int>();
        for (int j = 0; j < k; j++) {
            int x;
            char s;
            cin >> x >> s;
            p1.push_back(x);
            s1.push_back(s);
        }
        per.push_back(p1);
        sym.push_back(s1);
    }
    return 0;
}