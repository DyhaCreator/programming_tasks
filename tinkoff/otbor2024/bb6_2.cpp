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
    Node* first = new Node();
    Node* end = first;
    int size = 0;
    for (int i = 1; i < 2 * n; i++) {
        Node* node = new Node(i);
        end->next = node;
        node->last = end;
        end = node;
        size++;
    }
    end->next = first;
    first->last = end;
    auto node = first;
    while (node != end) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << node->val << endl;
    int k = 2 * n;
    int last_k = -1;
    while (last_k != k) {
        last_k = k;
        auto node = first;
        while (node != end) {
            // cout << node->val << " ";
            if (g[node->val] == node->next->val) {
                if (node == end) {
                    first
                    end = node->last;
                    node->last->next = first;
                }
                node->last->next = node->next->next;
                k -= 2;
                node = node->next->next;
            } else {
                node = node->next;
            }
        }
        // cout << node->val << endl;
        node = first;
        while (node != end) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << node->val << endl;
    }

    return 0;
}