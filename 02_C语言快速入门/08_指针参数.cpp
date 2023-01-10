#include<cstdio>

void swap1(int *a, int *b){
    int *temp = a;  //temp是指针指向变量a
    *a = *b;        //a的值发生变换后，*temp也发生变换，起不到交换值的作用
    *b = *temp;
}

void swap2(int *a, int *b){
    int temp = *a;  //保存a的值，可以实现值交换
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 10, b = 20;
    swap2(&a, &b);
    printf("a=%d b=%d", a, b);
    return 0;
}