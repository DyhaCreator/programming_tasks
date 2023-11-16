#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

int n;

vector<ll> right(vector<ll>a) {
    reverse(a.begin(), a.end());
    stack<ll>st;
    stack<ll>index;
    st.push(-1);
    index.push(-1);
    vector<ll>ans = vector<ll>();
    for (ll i = 0; i < n; i++) {
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

vector<ll> left(vector<ll>a) {
    stack<ll>st;
    stack<ll>index;
    st.push(-1);
    index.push(-1);
    vector<ll>ans = vector<ll>();
    for (ll i = 0; i < n; i++) {
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
    vector<ll>a = vector<ll>(n);
    for (auto &x : a)
        cin >> x;
    vector<ll>l = left(a);
    vector<ll>r = right(a);
    vector<ll>ansl = vector<ll>(n, 0);
    for (ll i = 0; i < n; i++) {
        if (l[i] == -1) {
            ansl[i] += (i + 1) * a[i];
        } else {
            ansl[i] += ansl[l[i]] + (i - l[i]) * a[i];
        }
    }
    vector<ll>ansr = vector<ll>(n, 0);
    for (ll i = n - 1; i >= 0; i--) {
        if (r[i] == -1) {
            ansr[i] += (n - i) * a[i];
        } else {
            ansr[i] += ansr[r[i]] + (r[i] - i) * a[i];
        }
    }
    int max_index = 0;
    for (int i = 0; i < n; i++) {
        if (ansl[i] + ansr[i] - a[i] > ansl[max_index] + ansr[max_index] - a[max_index]) {
            max_index = i;
        }
    }
    vector<ll>h = vector<ll>(n, 0);
    h[max_index] = a[max_index];
    for (ll j = max_index + 1; j < n; j++) {
        h[j] = min(a[j], h[j - 1]);
    }
    h[max_index] = a[max_index];
    for (int j = max_index - 1; j >= 0; j--) {
        h[j] = min(a[j], h[j + 1]);
    }
    for (int i = 0; i < n; i++) {
        cout << h[i] << " ";
    }
    cout << endl;
    return 0;
}