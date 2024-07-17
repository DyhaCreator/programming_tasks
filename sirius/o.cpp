#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (b[j] > b[j - 1]) {
                int bufferA = a[j];
                int bufferB = b[j];
                a[j] = a[j - 1];
                b[j] = b[j - 1];
                a[j - 1] = bufferA;
                b[j - 1] = bufferB;
            } else if (b[j] == b[j - 1]) {
                if (a[j] < a[j - 1]) {
                    int bufferA = a[j];
                    int bufferB = b[j];
                    a[j] = a[j - 1];
                    b[j] = b[j - 1];
                    a[j - 1] = bufferA;
                    b[j - 1] = bufferB;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " " << b[i] << endl;
    return 0;
}