#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

ll n;

struct Node{
    ll num;
    ll colL = 0;
    ll colR = 0;
    ll c = 0;
    vector<Node*> vec = {};
    Node() {}
};

map<ll, Node*> col;

int gen(ll num, Node* root, int c) {
    root->num = num;
    cout << c << " " << num << endl;
    for (ll i = 2; i < 10; i++) {
        if (num * i < n) {
            if (col[num * i] == 0) {
                root->vec.push_back(new Node());
                gen(num * i, root->vec[root->vec.size() - 1], c ^ 0b1);

                col[num * i] = root->vec[root->vec.size() - 1];
            }

            if (col[num * i]->c == c) {
                root->colL += col[num * i]->colL;
                root->colR += col[num * i]->colR;
            } else {
                root->colR += col[num * i]->colL;
                root->colL += col[num * i]->colR;
            }
        } else {
            if (c == 0) {
                root->colL++;
            } else {
                root->colR++;
            }
        }
    }
    return 0;
}

/*int dfs(Node *root) {
    int win = 0;
    for (auto &x : root->vec) {
        dfs()
    }
    return win;
}*/


int main() {
    cin >> n;
    Node* root = new Node();
    gen(1, root, 0);
    cout << root->colL << " " << root->colR << endl;
    // dfs(root);
    return 0;
}