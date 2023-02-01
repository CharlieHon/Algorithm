#include<cstdio>
#include<cstring>

struct bign{
    int d[1000];
    int len;
    bign(){
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char str[]){    //将整数转换为bign
    bign a;
    a.len = strlen(str);
    for(int i=0; i<a.len; ++i)
        a.d[i] = str[a.len-i-1] - '0';
    return a;
}

int compare(bign a, bign b){    //比较两个大整数大小，a大、相等、小，分别返回1、0、-1
    if(a.len > b.len)   return 1;
    else if(a.len < b.len)  return -1;
    else{
        for(int i=a.len-1; i>=0; --i){
            if(a.d[i] > b.d[i])
                return 1;
            else if(a.d[i] < b.d[i])
                return -1;
        }
    }
    return 0;
}

bign add(bign a, bign b){   //大整数相加
    bign c;
    int carry = 0;  //进位
    for(int i=0; i<a.len || i<b.len; ++i){  //从低位开始相加
        int tmp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = tmp % 10;
        carry = tmp / 10;
    }
    if(carry != 0)
        c.d[c.len++] = carry;
    return c;
}

bign sub(bign a, bign b){
    bign c;
    for(int i=0; i<a.len || i<b.len; ++i){
        if(a.d[i] < b.d[i]){
            a.d[i+1]--; //借位
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while(c.len-1>=1 && c.d[c.len-1] == 0){
        c.len--;    //去除高位的0，同时至少保留一位最低位
    }
    return c;
}

//乘法
bign multi(bign a, int b){  //高精度与低精度的乘法(高精度与低精度的乘法一部考试不涉及)
    bign c;
    int carry = 0;
    for(int i=0; i<a.len; ++i){
        int tmp = a.d[i] * b + carry;
        c.d[c.len++] = tmp % 10;
        carry /= 10;
    }
    while(carry != 0){  //乘法的进位可能不止一位，如25
        c.d[a.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

bign divide(bign a, int b, int &r){
    bign c;
    c.len = a.len;
    for(int i=a.len-1; i>=0; --i){
        r = r * 10 + a.d[i];
        if(r < b){
            c.d[i] = 0;
        }else{
            c.d[i] = r / b;
            r = r % b;
        }
    }
    while(c.len >= 2 && c.d[c.len-1] == 0){
        c.len--;
    }
    return c;
}

//打印大整数bign
void print_bign(bign a){
    for(int i=a.len-1; i>=0; --i){
        printf("%d", a.d[i]);
    }
    printf("\n");
}

int main()
{
    char str1[1000], str2[1000];
    scanf("%s%s", str1, str2);
    bign a = change(str1);
    bign b = change(str2);
    // print_bign(a);
    //加法
    print_bign(add(a, b));
    //减法，先比较大小，如果a小于b，则输出负号，然后交换a和b
    if(compare(a, b) == -1){
        printf("-");
        print_bign(sub(b, a));
    }else{
        print_bign(sub(a, b));
    }
    //乘法
    int c;
    scanf("%d", &c);
    if(c < 0){
        printf("-");
        print_bign(multi(a, -c));
    }else{
        print_bign(multi(a, c));
    }
    //除法
    int r = 0;
    print_bign(divide(a, c, r));
    printf("r=%d\n", r);
    return 0;
}
