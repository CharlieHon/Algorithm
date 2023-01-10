#include<cstdio>
#include<cmath>
const double eps = 1e8;
const double pi = acos(-1); //圆周率Pi
#define Equ(a, b)   ((fabs((a)-(b)))<(eps)) //等于
#define More(a, b)  (((a)-(b))>(eps))
#define Less(a, b)  (((a)-(b))<(-eps))
int main()
{
    printf("pi=%.8f\n", pi);
    double db = 1.23;
    if(Equ(db, 1.23)){
        printf("true");
    }
    else{
        printf("false");
    }
    return 0;
}