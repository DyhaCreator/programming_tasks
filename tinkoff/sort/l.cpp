#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

bool comp(string a, string b) {
    string c = a + b;
    string d = b + a;
    return c < d;
}

int main() {
    vector<string>v = vector<string>();
    string str = "";
    while (cin >> str) {
        v.push_back(str);
    }
    sort(v.begin(), v.end(), comp);
    reverse(v.begin(), v.end());
    for (auto x : v)
        cout << x;
    cout << endl;
    return 0;
}