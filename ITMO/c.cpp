#include <iostream>
#include <vector>
#define ll long long
using namespace std;

bool f(int a, string ab) {
    if (ab == "AB" && a & 0b1000 == 0) return true;
    if (ab == "BC" && a & 0b11 == 0b10) return true;
    if (ab == "CD" && a & 0b111 == 111) return true;
    
}

int main() {

    return 0;
}