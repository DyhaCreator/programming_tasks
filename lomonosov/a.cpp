#include <iostream>
#include <vector>
#include <string>
#define ll long long
#define ull unsigned long long
using namespace std;

struct Node{
    char n;
    Node* top_left = nullptr;
    Node* top_right = nullptr;
    Node* down_left = nullptr;
    Node* down_right = nullptr;
    Node() {}
    Node(char n) {
        this->n = n;
    }
};

void print_tree(Node *root) {
    if (root != nullptr) {
        cout << root->n;
        print_tree(root->top_left);
        print_tree(root->top_right);
        print_tree(root->down_left);
        print_tree(root->down_right);
    }
}

bool add(Node* &root, char c) {
    if (root == nullptr) {
        root = new Node(c);
        return true;
    } else if (root->n == 'Q') {
        if (add(root->top_left, c) == true) {
            return true;
        }
        if (add(root->top_right, c) == true) {
            return true;
        }
        if (add(root->down_left, c) == true) {
            return true;
        }
        if (add(root->down_right, c) == true) {
            return true;
        }
    }
    return false;
}

ull pow2(int n) {
    ull ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= 2;
    }
    return ans;
}

float rec(Node *root, char c, int n) {
    if (root->n == 'Q') {
        return rec(root->top_left, c, n + 1) + rec(root->top_right, c, n + 1) + rec(root->down_left, c, n + 1) + rec(root->down_right, c, n + 1);
    } else if (root->n == c) {
        ull a = pow2(n);
        return 1.0 / (float)(a * a);
    }
    return 0;
}

int main() {
    string str;
    cin >> str;
    char c;
    cin >> c;
    //cout << str << endl;
    //cout << c << endl;
    Node* root = nullptr;
    for (int i = 0; i < str.size(); i++) {
        add(root, str[i]);
    }
    float a = rec(root, c, 0);
    //cout << a << endl;
    string num = (int(a) % 2 == 0)?"0.":"1.";
    a -= int(a);
    do {
        a *= 2.0;
        num += to_string(int(a));
        a -= int(a);
    } while (a != 0.0);
    cout << num << endl;
    return 0;
}