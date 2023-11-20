#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct int2{
    int x, y;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

struct polygon{
    int num, n;
    vector<int2>v = vector<int2>();
    polygon() {}
    polygon(int num, int n, vector<int2>v) {
        this->num = num;
        this->n = n;
        this->v = v;
    }
};

int main() {
    int n;
    cin >> n;
    vector<polygon>v = vector<polygon>();
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vector<int2>p = vector<int2>(a);
        for (int j = 0; j < a; j++) {
            
        }
        polygon b();
    }
    return 0;
}