#include <iostream>
#include <stack>

int64_t fib(int n){
    int64_t a = 1, b = 1;
    while(n - 2 > 0){
        a += b;
        b = a - b;
        n--;
    }
    return a;
}

int main(){
    int n;
    std::cin >> n;
    clock_t start = clock();
    for(int i = 0; i < n; i++){
        fib(i);
    }
    std::cout << clock() - start << std::endl;
    return 0;
}