#include <iostream>
#include <cmath>

struct vec{
    double x, y;
    vec(){}
    vec(double x, double y){
        this -> x = x;
        this -> y = y;
    }
    vec(double x1, double y1, double x2, double y2){
        x = x2 - x1;
        y = y2 - y1;
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
    return sqrt(a.x * a.x + a.y * a.y);
}

double angl(vec a, vec b){
    return acos((a*b)/(len(a)*len(b)));
}

bool point_in_ray(double x, double y, double x1, double y1, double x2, double y2){
    vec a(x1, y1, x2, y2), b(x1, y1, x, y);
    return (a/b == 0 && a*b >= 0);
}

double S(double x1, double y1, double x2, double y2, double x3, double y3){
    return cp(vec(x1,y1,x2,y2),vec(x1,y1,x3,y3)) / 2.0;
}

int main(){
    double x, y, A, B, C;
    std::cin >> x >> y >> A >> B >> C;
    vec a(0, (A * 0 - C) / B), b(1, (A * 1 - C) / B);

    printf("%.5f\n",(2 * S(a.x, a.y, b.x, b.y, x, y)) / len(vec(x, y, b.x, b.y)));

    return 0;
}