#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

struct Node{
    int x;
    int index;
    int lg = -1, rg = -1;
    Node *l = nullptr;
    Node *r = nullptr;

    Node() {}
    Node(int x, int lg, int rg, Node *l, Node *r) {
        this->x = x;
        this->lg = lg;
        this->rg = rg;
        this->l = l;
        this->r = r;
    }
};

pair<int, int> init(Node *node, vector<int> &vec, int leftBound, int rightBound) {
    node->lg = leftBound;
    node->rg = rightBound;
    
    if (node->rg - node->lg == 1) {
        node->x = vec[node->lg];
        node->index = node->lg;
        return {node->x, node->index};
    }
    
    node->l = new Node();
    node->r = new Node();

    int mid = (leftBound + rightBound) / 2;
    pair<int, int> a = init(node->l, vec, leftBound, mid);
    pair<int, int> b = init(node->r, vec, mid, rightBound);
    
    if (a.first > b.first) {
        node->x = a.first;
        node->index = a.second;
    } else {
        node->x = b.first;
        node->index = b.second;
    }

    return {node->x, node->index};
}

pair<int, int> getMax(Node *node, int l, int r) {
    if (node->lg >= l && node->rg <= r) {
        return {node->x, node->index};
    }
    int ans = -1;
    int ansIndex = 0;
    if (node->l != nullptr) {
        if (node->l->rg >= l) {
            pair<int, int> a = getMax(node->l, l, r);
            
            if (a.first >= ans) {
                ans = a.first;
                ansIndex = a.second;
            }
        }
    }
    if (node->r != nullptr) {
        if (node->r->lg <= r) {
            pair<int, int> a = getMax(node->r, l, r);
            
            if (a.first >= ans) {
                ans = a.first;
                ansIndex = a.second;
            }
            // ans = max(getMax(node->r, l, r), ans);
        }
    }
    return {ans, ansIndex};
}

void print(Node *node) {
    cout << node->lg << " " << node-> rg << " " << node->x << endl;
    if (node->l != nullptr) {
        print(node->l);
    }
    if (node->r != nullptr) {
        print(node->r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &x : vec)
        cin >> x;

    Node *tree = new Node();

    pair<int, int> a = init(tree, vec, 0, n);

    tree->x = a.first;
    tree->index = a.second;

    // print(tree);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        // cout << l << " " << r << endl;
        cout << getMax(tree, l, r).second + 1 << endl;
    }
    return 0;
}