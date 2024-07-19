#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int qsort(vector<int> &vec) {
    for (auto &x : vec)
        cout << x << " ";
    cout << endl;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < vec.size() / 2; i++) {
        a.push_back(vec[i]);
    }
    for (int i = vec.size() / 2; i < vec.size(); i++) {
        b.push_back(vec[i]);
    }
    if (a.size() > 1) qsort(a);
    if (b.size() > 1) qsort(b);
    int indexA = 0;
    int indexB = 0;
    for (int i = 0; i < vec.size(); i++) {
        if ((a[indexA] < b[indexB] || indexB >= b.size()) && indexA < a.size()) {
            vec[i] = a[indexA];
            indexA++;
        } else {
            vec[i] = b[indexB];
            indexB++;
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    qsort(a);
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
    return 0;
}