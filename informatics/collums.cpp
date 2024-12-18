#include <iostream>

int main(){
    int a[100][100];
    int X, N;
    std::cin >> X >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> a[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        bool ans = false;
        for(int j = 0; j < N; j++){
            if(a[j][i] == X){
                ans = true;
                break;
            }
        }
        std::cout << (ans?"YES":"NO") << std::endl;
    }
    return 0;
}