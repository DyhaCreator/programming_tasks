#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int f(string str) {
    string l = str.substr(0, str.size() / 2);
    string r = str.substr((str.size() + 1) / 2, str.size());
    reverse(r.begin(), r.end());
    cout << l << " " << r << endl;
    vector<vector<int>>a = vector<vector<int>>(l.size() + 1, vector<int>(r.size() + 1));
    for (int y = 1; y <= l.size(); y++) {
        for (int x = 1; x <= r.size(); x++) {
            if (l[y - 1] == r[x - 1]) {
                a[y][x] = a[y - 1][x - 1] + 1;
            } else {
                a[y][x] = max(a[y - 1][x], a[y][x - 1]);
            }
            //cout << a[y][x] << " ";
        }
        //cout << endl;
    }
    //cout << str.size() / 2 << " " << a[l.size()][r.size()] << endl;
    return a[l.size()][r.size()];
}

int main() {
    int n, k;
    cin >> n >> k;
    string str = "";
    cin >> str;
    //cout << str.size() << endl;
    clock_t tStart = clock();
    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        for (int j = 1; j < str.size() - i + 1; j++) {
            cout << str.substr(i, j) << " " << endl;
            if ((str.substr(i, j).size() / 2) - f(str.substr(i, j)) <= k) {
                ans++;
            }
        }
    }
    //printf("Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    cout << ans << endl;
    return 0;
}