#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct stu{
    int score;
    int location_number;
    int local_rank;
    char id[15];
}s[10010];

bool cmp(stu a, stu b){
    if(a.score != b.score)  return a.score > b.score;
    else    return strcmp(a.id, b.id) < 0;  //字典序从小到大
}

int main()
{
    int n, k, sum = 0;  //n为考场数，k为每个考场人数，sum为总人数
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d", &k);
        for(int j=0; j<k; ++j){
            scanf("%s %d", s[sum].id, &s[sum].score);
            s[sum].location_number = i;
            ++sum;  //得用sum，从0到sum-1赋值！
        }
        sort(s+sum-k, s+sum, cmp);  //考生在本考场的排序
        s[sum - k].local_rank = 1;
        for(int j=sum-k+1; j<sum; ++j){
            if(s[j].score == s[j-1].score)
                s[j].local_rank = s[j-1].local_rank;
            else
                s[j].local_rank = j + 1 - (sum - k);
        }
    }
    printf("%d\n", sum);   //输出考生总数
    sort(s, s+sum, cmp);
    int r = 1;  //第一位学生排名
    for(int i=0; i<sum; ++i){
        if(i > 0 && s[i].score != s[i-1].score)
            r = i + 1;
        printf("%s ", s[i].id);
        printf("%d %d %d\n", r, s[i].location_number, s[i].local_rank);
    }
    return 0;
}