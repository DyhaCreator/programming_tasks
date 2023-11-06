#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

int n;

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
    cin >> n;
    vector<int>a = vector<int>();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    vector<int>ansR = right(a);
    vector<int>ansL = left(a);
    ll max = 0;
    for (int i = 0; i < n; i++) {
        ll L = 0;
        if (ansR[i] == -1) {
            L += n - i - 1;
        } else {
            L += ansR[i] - i - 1;
        }
        if (ansL[i] == -1) {
            L += i + 1;
        } else {
            L += i - ansL[i];
        }
        if (L * a[i] > max) {
            max = L * a[i];
        }
    }
    cout << endl << max << endl;
    return 0;
}