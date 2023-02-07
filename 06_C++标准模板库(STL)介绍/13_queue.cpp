#include<cstdio>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;

    for(int i=1; i<6; ++i){
        q.push(i);
    }

    printf("q.size()=%d\n", q.size());

    printf("front=%d, back=%d\n", q.front(), q.back());

    q.pop();    //从队首出列一个元素
    printf("q.size()=%d, q.front()=%d\n", q.size(), q.front());

    while(!q.empty()){
        q.pop();    //清空元素
    }

    if(q.empty())
        printf("Empty!\n");
    else
        printf("Not Empty!\n");

    return 0;
}