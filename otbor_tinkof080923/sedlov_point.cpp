#include <iostream>

int main(){
    int a[750][750];
    int n, m, ans = 0;
    std::cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int min = 0;
            for(int k = 0; k < n; k++){
                if(a[j][k] < a[j][min]){
                    min = k;
                }
            }
            bool x = false;
            for(int k = 0; k < n; k++){
                if(a[j][k] == a[j][min] && k == i){
                    x = true;
                    break;
                }
            }
            if(!x)break;
            int max = 0;
            for(int k = 0; k < m; k++){
                if(a[k][i] > a[max][i]){
                    max = k;
                }
            }
            bool y = false;
            for(int k = 0; k < m; k++){
                if(a[k][i] == a[max][i] && k == j){
                    y = true;
                    break;
                }
            }
            if(x && y)ans++;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}