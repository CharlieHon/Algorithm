#include<cstdio>
#include<algorithm>
using namespace std;
struct mooncake{
    double store;   //库存量
    double sell;    //总售价
    double price;   //单价
}cake[1010];

bool cmp(mooncake a, mooncake b){
    return a.price > b.price;
}

int main()
{
    int n;  //月饼种类
    double D;   //总需求量
    scanf("%d%lf", &n, &D);
    for(int i=0; i<n; ++i)
        scanf("%lf", &cake[i].store);
    for(int i=0; i<n; ++i){
        scanf("%lf", &cake[i].sell);
        cake[i].price = cake[i].sell / cake[i].store;
    }
    sort(cake, cake+n, cmp);    //按单价从大到小排序
    double res = 0; //总收益
    for(int i=0; i<n; ++i){
        if(cake[i].store >= D){
            res += D * cake[i].price;
            break;
        }
        else{
            res += cake[i].store * cake[i].price;
            D -= cake[i].store;
            cake[i].store = 0;
        }
    }
    printf("res = %.2f", res);  //输出结果保留两位小数
    return 0;
}