#include <iostream>
#include <algorithm>
#include <vector>
 
int main() {
    std::vector<int> vec = std::vector<int>();

    int num;
    while(true){
        std::cin >> num;
        if(num == 0){
            break;
        }
        vec.push_back(num);
    }

    std::sort(vec.begin(), vec.end());

    for(int i = vec.size() - 2; i > 0; i--){
        if(vec[i] == vec[i + 1]){
            vec[i + 1] = 0;
        }
    }

    std::sort(vec.begin(), vec.end());

    std::cout << vec[vec.size() - 2] << std::endl;
    return 0;
}