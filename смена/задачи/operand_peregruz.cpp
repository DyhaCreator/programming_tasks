#include <iostream>

struct vec{
    int x, y;
    vec(){}
    vec(int x, int y){
        this -> x = x;
        this -> y = y;
    }
    vec(int x1, int y1, int x2, int y2){
        x = x2 - x1;
        y = y2 - y1;
    }
    int operator*(vec const &a){
        return a.x * a.y + x * y;
    }
    int operator/(vec const &a){
        return x*a.y - a.x*y;
    }
};

int main(){
    vec a(39, 21), b(-1, 4);

    return 0;
}