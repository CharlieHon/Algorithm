#include<cstdio>
#include<cmath>

const double eps = 1e-5;
const double PI = acos(-1.0);   //PI

double f(double x){ //f(x) = x ^ 2
    return x * x;
}

double calSqrt(){   //求 sqrt(2) 的近似值
    double left = 1, right = 2, mid;
    while(right - left > eps){
        mid = (left + right) / 2;
        if(f(mid) > 2)
            right = mid;
        else if(f(mid) < 2)
            left = mid;
    }
    return mid;
}

//装水问题
double func(double H, double R){
    double alpha = acos((R-H) / R);
    double s2 = PI * R * R / 2;
    double s1 = alpha * R * R - (R - H) * R * sin(alpha);
    return s1 / s2;
}

double solve(double R, double r){
    double left = 0, right = R, mid;
    while(right - left > eps){
        mid = (left + right) / 2;
        if(func(mid, R) > r)
            right = mid;
        else
            left = mid;
    }
    return mid;
}

int main()
{
    //求 sqrt(2) 近似值
    double res1 = calSqrt();
    printf("%.5f\n", res1);  //1.41421

    //装水问题
    double R, r;    //半径和比例
    scanf("%lf%lf", &R, &r);
    double res2 = solve(R, r);
    printf("the h of water is %.5f\n", res2);
    return 0;
}
