#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct Node{
    int val = 0;
    Node *next;
    Node *last;
    Node() {}
    Node(int val) {
        this->val = val;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> g(2 * n);
    unsigned int start_time =  clock();
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1] = b - 1;
        g[b - 1] = a - 1;
    }
    vector<int> vec(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        vec[i] = i;
    }
    /*for (auto &x : vec)
        cout << x << " ";
    cout  << endl;*/
    int k = 2 * n;
    int last_k = -1;
    while (last_k != k) {
        last_k = k;
        for (int i = 0; i < vec.size() - 1 && vec.size() > 0;) {
            if (g[vec[i]] == vec[i + 1]) {
                // cout << vec[i] << " " << vec[i + 1] << endl;
                vec.erase(vec.begin() + i);
                vec.erase(vec.begin() + i);
                k -= 2;
            } else {
                i++;
            }
            /*for (auto &x : vec)
                cout << x << " ";
            cout  << endl;*/
        }
        if (g[vec[0]] == vec[vec.size() - 1]) {
            vec.erase(vec.begin());
            vec.erase(vec.end() - 1);
            k -= 2;
        }
    }
    // cout << k << endl;
    if (k > 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    unsigned int end_time = clock();
    // cout << (double)(end_time - start_time) / CLOCKS_PER_SEC * 10 << endl;
    return 0;
}