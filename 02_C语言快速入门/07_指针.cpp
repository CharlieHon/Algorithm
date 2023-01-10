#include<cstdio>

void change(int *p){    //使用指针变量作为函数参数，把变量的地址传入函数
    *p = 223;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a[10];
    for(int *p=a; p<a+10; ++p){
        scanf("%d", p); //数组名称可以作为首地址，a==&a[0]，指针变量可以进行加减法
    }
    for(int i=0; i<10; ++i){
        printf("%d ", a[i]);
    }
    int *m = a, *n = &a[5];
    printf("\nm = %d\n", m);    //输出m保存的地址
    printf("n = %d\n", n);
    printf("n - m = %d\n", n-m);    // 20 / 4 = 5，m和n值相差20，但n-m表示两个地址之间的距离，以int为单位，由于1个int占用4Byte，所以...
    
    int b = 1;
    change(&b); //传入地址 int *p = &b;
    printf("%d\n", b);  // 223
    
    return 0;
}