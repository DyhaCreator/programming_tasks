#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>>dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for (int y = 1; y <= s1.size(); y++) {
        for (int x = 1; x <= s2.size(); x++) {
            if (s1[y - 1] != s2[x - 1]) {}
        }
    }
    return 0;
}