#include <iostream>
#include <fstream>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ofstream out("test");
    int n = 50000;
    out << 1 << endl << n << endl;
    for (int i = 0; i < n; i++) {
        out << "1 2" << endl;
    }
    for (int i = 1; i < n; i++) {
        out << i << " " << i + 1 << endl;
    }
    return 0;
}