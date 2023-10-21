#include <iostream>
#include <string>
#include <unordered_map>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<string, string>mp1;
    unordered_map<string, string>mp2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        mp1[s1] = s2;
        mp2[s2] = s1;
    }
    string str;
    cin >> str;
    if (mp1[str] == "") {
        cout << mp2[str] << endl;
    } else {
        cout << mp1[str] << endl;
    }
    return 0;
}