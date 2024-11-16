#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void get_password(void) {
    char s[100] = "cieoserrhlutncj ";
    int key;
    int step;
    int size = strlen(s);
    printf("Enter key number: ");
    scanf("%d", &key);
    printf("Enter step: ");
    scanf("%d", &step);
    for (int i = 0; i < key * step; i += step, step++)
        printf("%c", s[i % size]);
}

int main() {
    
}