#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#define ll long long
using namespace std;

vector<int> right(vector<int>a) {
    reverse(a.begin(), a.end());
    stack<int>st;
    stack<int>index;
    st.push(-1);
    index.push(-1);
    vector<int>ans = vector<int>();
    for (int i = 0; i < n; i++) {
        while (st.top() >= a[i]) {
            st.pop();
            index.pop();
        }
        ans.push_back(index.top());
        st.push(a[i]);
        index.push(n - i - 1);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> left(vector<int>a) {
    stack<int>st;
    stack<int>index;
    st.push(-1);
    index.push(-1);
    vector<int>ans = vector<int>();
    for (int i = 0; i < n; i++) {
        while (st.top() >= a[i]) {
            st.pop();
            index.pop();
        }
        ans.push_back(index.top());
        st.push(a[i]);
        index.push(i);
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll>a = vector<ll>(n);
    for (auto &x : a)
        cin >> x;
    vector<ll>b = vector<ll>(n);
    for (int i = 0; i < n; i++) {
        if (a[i] < a[n - i - 1]) {
            b[i] = a[n - i - 1] - a[i];
        }
    }
    for (auto x : b)
        cout << x << " ";
    cout << endl;
    while (true) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            
        }
    }
    return 0;
}