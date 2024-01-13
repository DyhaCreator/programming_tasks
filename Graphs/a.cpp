#include <iostream>
#include <vector>
#include <utility>
#define ll long long
using namespace std;

int main() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;
    vector<pair<int, int>>edges(edgeCount);
    for (auto &[a, b] : edges) {
        cin >> a >> b;
    }
    return 0;
}