#include <fstream>
#define ll long long
using namespace std;

int main() {
    int n = 100000;
    ofstream out("test2");
    out << n << endl;
    int l = 0;
    int r = 2;
    for (int i = 0; i < n; i++) {
        out << l << " " << r << endl;
        l++;
        r++;
    }
    return 0;
}