#include<cstdio>
int main()
{
    int a[99], n = 0;
    while(scanf("%d", &a[n]) != EOF){
        ++n;
    }
    printf("%d\n", n);
    
    for(int i=1; i<=n-1; ++i){
        for(int j=0; j<n-i; ++j){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for(int i=0; i<n; ++i){
        printf("%d", a[i]);
        if(i != n-1)
            printf(" ");
    }

    return 0;
}
