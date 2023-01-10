#include<cstdio>

int basep2ten(int x, int p){  //将P进制x转换为十进制数y
    int y = 0, product = 1;
    while(x != 0){
        y = y + (x % 10) * product;
        x = x / 10;
        product = product * p;
    }
    return y;
}

void baseten2q(int x, int q){   //将10进制x转换为q进制y
    int z[40], num = 0;
    do{
        z[num++] = x % q;
        x = x / q;
    }while(x != 0);
    for(int i=num-1; i>=0; --i){
        printf("%d", z[i]);
    }
    printf("\n");
}

int main()
{
    int a = 11, b = 12;
    //十进制11转换为二进制
    baseten2q(a, 2);
    //8进制12转换为十进制
    int res = basep2ten(b, 8);
    printf("%d", res);
    return 0;
}