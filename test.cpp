#include<cstdio>
#include<algorithm>
using namespace std;

void bubbleSort(int *a, const int n){
    for(int i=1; i<n; ++i){
        for(int j=0; j<n-i; ++j){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selectSort(int *a, const int n){
    for(int i=0; i<n-1; ++i){
        int k = i;
        for(int j=i+1; j<n; ++j){
            if(a[j] < a[k])
                k = j;
        }
        int temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    }
}

void insertSort(int *a, const int n){
    for(int i=1; i<=n; ++i){
        int temp = a[i];
        int j = i;
        while(j > 0 && temp < a[j-1]){
            a[j] = a[j-1];
            --j;
        }
        a[j] = temp;
    }
}

void print_a(int  *a, const int n){
    for(int i=0; i<n; ++i){
        printf("%d", a[i]);
        if(i != n-1)
            printf(" ");
    }
    printf("\n");
}

int main()
{
    int a[] = {1, 5, 6, 32, 4, 8, 9, 2, 0};
    int n = sizeof(a) / sizeof(int);
    print_a(a, n);
    // bubbleSort(a, n);
    // selectSort(a, n);
    // insertSort(a, n);
    sort(a, a+n);   //sort(数组首元素地址，尾元素后一位地址，排序规则)
    print_a(a, n);
    return 0;
}