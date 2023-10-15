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

    int col = 1;

    for(int i = 0; i < vec.size(); i++){
        if(vec[i] != vec[i + 1]){
            std::cout << vec[i] << " " << col << std::endl;
            col = 1;
        }
        else{
            col++;
        }
    }

    std::sort(vec.begin(), vec.end());
    return 0;
}