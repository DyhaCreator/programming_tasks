#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a = vector<int>();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
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
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}