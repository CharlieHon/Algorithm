#include<cstdio>
int main()
{
    int a[] = {2, 5, 6, 4, 1, 3, 8};
    int n = sizeof(a) / sizeof(int);
    for(int i=1; i<=n-1; ++i){  //进行n-1次冒泡
        for(int j=0; j<n-i; ++j){   //每次从a[0]到a[n-1-i]与后一位比较大小
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for(int i=0; i<n; ++i)
        printf("%d\n", a[i]);

    return 0;
}