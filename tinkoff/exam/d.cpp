#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct st{
    vector<int>data;
    int pointer = 0;
    int minA = 1e9;
    int minIndex = 0;
    st() {}
    st(int n) {
        data = vector<int>(n);
    }
    void push(int n) {
        if (n < minA) {
            minA = n;
            minIndex = pointer;
        }
        data[pointer] = n;
        pointer++;
    }
    void pop() {
        pointer--;
        if (minIndex == pointer) {
            minA = 1e9;
            minIndex = 0;
            for (int i = 0; i < pointer; i++) {
                if (data[i] < minA) {
                    minA = data[i];
                    minIndex = i;
                }
            }
        }
    }
    int min() {
        return minA;
    }
};

int main() {
    int t, N;
    cin >> t >> N;
    st s = st(t);
    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int n;
            cin >> n;
            s.push(n);
        } else if (a == 2) {
            s.pop();
        } else {
            cout << s.min() << "\n";
        }
    }
    return 0;
}

/*

11 100
1 4
1 3
1 2
1 1
3
2
3
2
2
3
1 50

*/