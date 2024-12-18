#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ifstream in("file");
    ifstream in2("file2");
    vector<int> a = {};
    int n;
    while (in >> n) a.push_back(n);
    while (in2 >> n) a.push_back(n);
    sort(a.begin(), a.end());
    ofstream out("out");
    for (auto &x : a)
        out << x << " ";
    out << endl;
    return 0;
}