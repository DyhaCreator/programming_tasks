#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<int> g;
int n;

int f(vector<int> &vec) {
    // int i = l;
    // cout << l << " " << r << endl;
    // cout << i << endl;
    /*for (auto &x : vec)
        cout << x << " ";
    cout << endl;*/
    /*for (int j = l; j < r; j++) {
        if (j > i && j < g[i]) {
            // cout << j << " " << g[j] << endl;
            if (g[j] > g[i]) {
                cout << "YES" << endl;
                exit(0);
            }
        }
    }*/
    int i = vec[0];
    for (auto &x : vec)
        if (abs(g[i] - i) < abs(g[x] - x)) {
            i = x;
        }
    if (abs(g[i] - i) == 1) return 0;
    for (auto &j : vec) {
        if (j > i && j < g[i]) {
            // cout << j << " " << g[j] << endl;
            if (g[j] > g[i]) {
                cout << "YES" << endl;
                exit(0);
            }
        }
    }
    vector<int> vec1 = {};
    vector<int> vec2 = {};
    for (auto &x : vec) {
        if (x > vec[0] && x < g[vec[0]]) {
            vec1.push_back(x);
        } else if (x < vec[0] || x > g[vec[0]]) {
            vec2.push_back(x);
        }
    }
    if (vec1.size() > 0)
        f(vec1);
    if (vec2.size() > 0)
        f(vec2);
    /*for (auto &x : vec1)
        cout << x << " ";
    cout << endl;
    for (auto &x : vec2)
        cout << x << " ";
    cout << endl;*/
    /*int l1 = l + 1;
    int r1 = g[i] - 1;
    int l2 = g[i] + 1;
    int r2 = r;
    if (r1 - l1 > 0)
        f(l1, r1);
    if (n < 100000 && r2 - l2 > 0)
        f(l2, r2);*/
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    g = vector<int> (2 * n);
    unsigned int start_time =  clock();
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1] = b - 1;
        g[b - 1] = a - 1;
    }
    vector<int> vec(2 * n);
    for (int i = 0; i < 2 * n; i++) vec[i] = i;
    // f(0, 2 * n - 1);
    f(vec);
    cout << "NO" << endl;
    return 0;
}