#include<cstdio>
#include<algorithm>
using namespace std;
/**
 * @brief 有n个开区间，输出最多能选择不相交区间的个数
 */
struct Interval{
    int x, y;   //x, y分别表示区间左右坐标
}I[110];
/**
 *       ----
 *       -------
 *   --
 *   -----
 * ----
 */
bool cmp(Interval a, Interval b){   //区间比较规则
    if(a.x != b.x)  
        return a.x > b.x;   //如果左端点不同，按左端点从大到小
    return a.y < b.y;       //相同，则按右端点从小到大
}

int main()
{
    int n;  //n个区间进行比较
    while(scanf("%d", &n)){
        for(int i=0; i<n; ++i)
            scanf("%d%d", &I[i].x, &I[i].y);    //分别输入n个区间的左右端点
    }
    sort(I, I+n, cmp);  //对区间进行排序
    int res = 1, lastX = I[0].x;    //res为区间个数
    for(int i=1; i<n; ++i){
        if(I[i].y <= lastX){
            ++res;
            lastX = I[i].x;
        }
    }
    printf("res = %d\n", res);
    return 0;
}

