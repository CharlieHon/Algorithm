#include<cstdio>
/**
 * 引用不产生副本，而是给原变量起了个别名，对引用变量的操作就是对原变量的操作。
 * 
 */

void change(int &x){    //传引用
    x = 1;
}

//指着的引用
void swap(int* &p1, int* &p2){
    int *temp = p1;
    p1 = p2;
    p2 = temp;
}

int main()
{
    int x = 10;
    printf("x=%d\n", x);
    change(x);
    printf("x=%d\n", x);
    int a = 1, b = 2;
    int *p1 = &a, *p2 = &b;
    swap(p1, p2);       //不能写成swap(&a, &b),因为引用时产生变量的别名，地址是常量不能使用引用
    printf("a=%d b=%d\n", a, b);
    printf("*p1=%d *p2=%d\n", *p1, *p2);
    return 0;
}