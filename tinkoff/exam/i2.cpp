#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<vector<int>>c = vector<vector<int>>();
vector<vector<int>>p = vector<vector<int>>();

int maxS = 0;
int n, b;

void rec(int sum, int min, int size) {
    cout << sum << " " << min << " " << size << endl;
    if (size == n) {
        cout << "-----" << endl;
        if (sum <= b) {
            maxS = std::max(min, maxS);
        }
        return;
    }
    for (int i = 0; i < c[size].size(); i++) {
        rec(sum + c[size][i], std::min(min, p[size][i]), size + 1);
    }
}

int main() {
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        c.push_back(vector<int>(k));
        p.push_back(vector<int>(k));
        for (int j = 0; j < k; j++) {
            int c1, p1;
            cin >> c1 >> p1;
            c[i][j] = c1;
            p[i][j] = p1;
        }
    }
    rec(0, 1e9, 0);
    cout << maxS << endl;
    return 0;
}

/*

2 5
2
1 7
3 5
3
1 1
0 8
4 6

*/