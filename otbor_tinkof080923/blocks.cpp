#include <iostream>
#include <vector>
#include <cmath>

int p(int k){
    int ans = 1 << k;
    return ans;
}

int div_up(int a, int b){
    return (a + b - 1) / b;
}

int main(){
    int k[100000];
    int N, K, Q;
    std::cin >> N >> K >> Q;
    for(int i = 0; i < K; i++){
        int a;
        std::cin >> a;
        k[i] = p(a);
    }
    for(int i = 0; i < Q; i++){
        int index;
        std::cin >> index;
        for(int j = 0; j < K; j++){
            int a = div_up(index, k[j]);
            if((a & 1) == 0){
                index -= k[j];
            }
            else{
                index += k[j];
            }
        }
        std::cout << index << " ";
    }
    return 0;
}