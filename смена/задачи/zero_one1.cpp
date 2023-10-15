#include <iostream>
#include <vector>

int ans = 0;

void m(std::vector<int>bin, int index){
    if(index == bin.size()){
        for(int i = 0; i < bin.size() - 1; i++){
            if(bin[i] == bin[i + 1] && bin[i] == 1){
                return;
            }
        }
        /*for(int i = 0; i < bin.size(); i++){
            std::cout << bin[i] << " ";
        }
        std::cout << std::endl;*/
        ans++;
    }else{
        m(bin, index + 1);
        bin[index] = 1;
        m(bin, index + 1);
    }
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int>bin = std::vector<int>(n);

    m(bin, 0);

    std::cout << ans << std::endl;

    return 0;
}