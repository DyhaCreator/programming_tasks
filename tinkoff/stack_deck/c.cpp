#include <iostream>
#include <stack>
#define ll long long

using namespace std;

int main() {
    stack<int>st;
    stack<int>count;
    st.push(-1);
    count.push(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == st.top()) {
            int a = count.top();
            count.pop();
            count.push(a + 1);
        } else {
            if (count.top() >= 3) {
                ans += count.top();
                count.pop();
                st.pop();
                if (x == st.top()) {
                    int a = count.top();
                    count.pop();
                    count.push(a + 1);
                } else {
                    count.push(1);
                    st.push(x);
                }
            } else {
                count.push(1);
                st.push(x);
            }
        }
    }
    if (count.top() >= 3) {
        ans += count.top();
    }
    cout << ans << endl;
    return 0;
}