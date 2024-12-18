#include <iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

int n;

vector<int> left(vector<int>a) {
    vector<int>ans = vector<int>(n);
    stack<int>st;
    st.push(-1);

    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

vector<int> right(vector<int>a) {
    vector<int>ans = vector<int>(n);
    stack<int>st;
    st.push(-1);

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

ll area(vector<int>l, vector<int>r) {
    ll s = 0;

}


int main() {
    cin >> n;
    vector<int>a = vector<int>(n);
    for (auto &x : a)
        cin >> x;
    
    vector<int>l = left(a);
    vector<int>r = right(a);

    for (auto x : l)
        cout << x << " ";
    cout << endl;
    for (auto x : r)
        cout << x << " ";
    cout << endl;

    for (int i = 0; i < n; i++) {

    }

    return 0;
}
/*

7
5 5 5 2 3 1 4

*/