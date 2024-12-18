#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n, s;

struct min_queue{
    vector<int>a = vector<int>(n);
    int min = 2e9 + 10;
    int min_index = -1;
    int start = 0;
    int end = 0;
    min_queue() {}
    int rMin() {
        return min;
    }
    void push(int x) {
        a[end] = x;
        if (x < min) {
            min = x;
        }
        end++;
    }
    void pop() {
        a[start] = 0;
        start++;
        min_index--;
        if (min_index < start) {
            min = 2e9 + 10;
            for (int i = start; i < end; i++) {
                if (a[i] < min) {
                    min = a[i];
                    min_index = i;
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio();
    cin.tie();
    cin >> n >> s;
    vector<int>a = vector<int>();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    min_queue b = min_queue();
    for (int i = 0; i < s; i++) {
        b.push(a[i]);
        /*for (int j = 0; j < b.end; j++) {
            cout << b.a[j] << " ";
        }
        cout << endl;*/
    }
    for (int i = s; i < n; i++) {
        /*for (int j = 0; j < b.end; j++) {
            cout << b.a[j] << " ";
        }
        cout << endl;*/
        cout << b.rMin() << " ";
        b.push(a[i]);
        b.pop();
    }
    cout << b.rMin() << endl;
    return 0;
}

/*
7 3
1 3 2 4 5 3 1
*/