#include <iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

int n;

bool isSorted(vector<int>k, vector<int>train, int ksize) {
    stack<int>stop;
    vector<int>ans;
    int pointer = 0;
    for (int i = 0; i < ksize; i += 2) {
        for (int j = 0; j < k[i]; j++) {
            stop.push(train[pointer]);
            pointer++;
        }
        for (int j = 0; j < k[i + 1]; j++) {
            ans.push_back(stop.top());
            stop.pop();
        }
    }
    return train.size() == ans.size();
}

int main() {
    vector<int>k = vector<int>();
    vector<int>train = vector<int>();
    stack<int>stop;
    stack<int>ans;
    int x, k1 = 0, k2 = 0;
    cin >> n;
    int th = 1;
    int ksize = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        train.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (train[i] == th) {
            stop.push(train[i]);
            k1++;
            while (!stop.empty() && stop.top() == th) {
                th++;
                ans.push(stop.top());
                k2++;
                stop.pop();
            }
            k.push_back(k1);
            k.push_back(k2);
            ksize += 2;
            k1 = 0;
            k2 = 0;
        } else {
            stop.push(train[i]);
            k1++;
        }
    }
    if (isSorted(k, train, ksize)) {
        cout << ksize << endl;
        for (int i = 0; i < ksize; i += 2) {
            cout << 1 << " " << k[i] << endl;
            cout << 2 << " " << k[i + 1] << endl;
        }
    } else {
        cout << 0 << endl;
    }
    return 0;
}