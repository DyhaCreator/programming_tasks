#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct Node{
    int x;
    int mn = 0, mx = INF;
    Node* left = nullptr;
    Node* right = nullptr;
    Node() {}
    Node(int x, int mn, int mx) {
        this->x = x;
        this->mx = mx;
        this->mn = mn;
    }
};

int ind = 0;
vector<int> a;
int found = 0;
int n;

void gen(Node *root) {
    if (a[ind] < root->x) {
        if (a[ind] > root->mn) {
            root->left = new Node(a[ind], root->mn, root->x);
            ind++;
            if (ind < n) gen(root->left);
        } else {
            cout << "Impossible" << endl;
            exit(0);
        }
    } 
    if (a[ind] > root->x) {
        if (a[ind] < root->mx) {
            root->right = new Node(a[ind], root->x, root->mx);
            ind++;
            if (ind < n) gen(root->right);
        } else {
            return;
        }
    }
}

int main() {
    cin >> n;
    a = vector<int>(n);
    for (auto &x : a)
        cin >> x;
    Node *root = new Node(a[0], 0, INF);
    gen(root);
    cout << ind << endl;
    if (ind < n - 1) cout << "Imposiible" << endl;
    return 0;
}