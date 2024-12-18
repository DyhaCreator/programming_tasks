#include <iostream>
#include <vector>
#include <cmath>

struct vec{
    int x, y;
    vec(){}
    vec(int x, int y){
        this->x = x;
        this->y = y;
    }
    vec(int x1, int y1, int x2, int y2){
        x = x2 - x1;
        y = y2 - y1;
    }
    vec(vec a, vec b){
        x = a.x - b.x;
        y = a.y - b.y;
    }
    int operator*(vec const &a){
        return a.x * x + a.y * y;
    }
    int operator/(vec const &a){
        return x*a.y - a.x*y;
    }
};

int cp(vec a, vec b){
    return a.x * b.y - a.y * b.x;
}

double len(vec a){
    return a.x * a.x + a.y * a.y;
}

double S(int x1, int y1, int x2, int y2, int x3, int y3){
    return cp(vec(x1,y1,x2,y2),vec(x1,y1,x3,y3));
}

int main(){
    vec points[2000];
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        points[i] = vec(x,y);

    }
    int col = 0;
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            double ij = len(vec(points[i], points[j]));
            for(int k = j + 1; k < n; k++){
                double jk = len(vec(points[j], points[k]));
                double ik = len(vec(points[k], points[i]));
                if((ij == ik || ij == jk || ik == jk) &&
                    S(points[i].x, points[i].y, points[j].x, points[j].y, points[k].x, points[k].y)){
                    col++;
                }
            }
        }
    }
    std::cout << col << std::endl;

    return 0;
}

/*

4
0 0
1 0
2 0
1 1


4
0 0
0 1
1 0
2 0

*/