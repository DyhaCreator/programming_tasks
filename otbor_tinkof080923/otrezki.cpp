#include <iostream>
#include <vector>
#include <string>

std::vector<std::string>matrix = std::vector<std::string>();
std::vector<std::pair<int, int>>l = std::vector<std::pair<int, int>>();

int size(int x, int y){
    //std::cout << x << " " << y << " " << matrix[y][x] << std::endl;
    if(matrix[y][x] == '|'){
        l.push_back({x, y});
        if(matrix[y + 1][x] == '|'){
            return size(x, y + 1) + 1;
        }
        else{
            return 1;
        }
    }
    if(matrix[y][x] == '-'){
        l.push_back({x, y});
        if(matrix[y][x + 1] == '-'){
            return size(x + 1, y) + 1;
        }
        else{
            return 1;
        }
    }
    if(matrix[y][x] == '/'){
        l.push_back({x, y});
        if(matrix[y + 1][x - 1] == '/'){
            return size(x - 1, y + 1) + 1;
        }
        else{
            return 1;
        }
    }
    if(matrix[y][x] == '\\'){
        l.push_back({x, y});
        if(matrix[y + 1][x + 1] == '\\'){
            return size(x + 1, y + 1) + 1;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int main(){
    int n, m;
    std::cin >> n >> m;
    for(int i = 0; i < n; i++){
        std::string ma;
        std::cin >> ma;
        ma = '.' + ma + '.';
        matrix.push_back(ma);
    }
    std::string ma = "";
    for(int i = 0; i < m + 2; i++){
        ma += '.';
    }
    matrix.push_back(ma);

    /*for(int i = 0; i < matrix.size(); i++){
        std::cout << matrix[i] << std::endl;
    }*/

    int ans = 0;
    for(int y = 0; y < n; y++){
        for(int x = 1; x < m + 1; x++){
            bool b = false;
            for(int i = 0; i < l.size(); i++){
                if(x == l[i].first && y == l[i].second){
                    b = true;
                    break;
                }
            }
            if(b == false && size(x, y) > 0){
                ans++;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

/*

4 5
..|/.
--|..
./|./
/.|/.

*/