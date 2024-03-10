#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<vector<int>> f(string s1, string s2) {
    int m = 7;
    int n = 6;
    vector<vector<int>> D(m + 1, vector<int>(n + 1));
    D[0][0] = 0;
    int j = 1;
    while (j <= n) {
        D[0][j] = D[0][j - 1] + 1;
        j++;
    }
    int i = 1;
    j = 1;
    while (i <= m) {
        D[i][0] = D[i - 1][0] + 1;
        while (j <= n) {
            if (s1[i - 1] != s2[j - 1]) {
                D[i][j] = min(min(D[i][j - 1] + 1, D[i - 1][j] + 1), D[i - 1][j - 1] + 1);
            } else {
                D[i][j] = D[i - 1][j - 1];
            }
            j++;
        }
        j = 1;
        i++;
    }
    /*for (auto &x : D) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << endl;
    }*/
    return D;
}

vector<vector<int>> b = {
    {0, 1, 2, 3, 4, 5, 6},
    {1, 1, 2, 2, 3, 4, 5},
    {2, 2, 2, 3, 2, 3, 4},
    {3, 3, 3, 3, 3, 2, 3},
    {4, 4, 4, 4, 3, 3, 2},
    {5, 5, 5, 5, 4, 4, 3},
    {6, 6, 6, 6, 5, 5, 4},
    {7, 7, 7, 7, 6, 6, 5}
};

void rec(string s1, int n)  {
    if (n == 6) {
        // cout << s1 << endl;
        string s2 = "monocle";
        vector<vector<int>> a = f(s2, s1);
        if (a == b) {
            cout << s1 << endl;        }
        return;
    }
    s1.push_back('a');
    for (int i = 0; i < 26; i++) {
        s1[s1.size() - 1] = i + 'a';
        rec(s1, n + 1);
    }
}

int main() {
    string s1 = "";
    rec(s1, 0);
    return 0;
}

/*



*/