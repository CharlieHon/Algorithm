#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 100010;

struct Node{
    int address, data, next;
    bool flag;       //

}node[MAXN];

//结点排序，如果是都是有效结点，则按照数据值升序排序；否则，按照先有效后无效排序
bool cmp(Node a, Node b){
    if(a.flag==0 || b.flag==0){
        return a.flag > b.flag;
    }else{
        return a.data < b.data;
    }
}

int main()
{
    for(int i=0; i<MAXN; ++i){
        node[i].flag = 0;
    }

    int n, begin;
    scanf("%d%d", &n, &begin);

    int address, data, next;

    for(int i=0; i<n; ++i){
        scanf("%d%d%d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }

    int count = 0, p = begin;

    while(p != -1){
        node[p].flag = true;
        ++count;
        p = node[p].next;
    }

    if(count==0){
        printf("0 -1"); //特判，新链表中没有结点时输出 0 -1
    }else{
        //筛选有效结点，并按data从小到大排序
        sort(node, node+MAXN, cmp);
        //输出结果
        printf("%d %05d\n", count, node[0].address);
        for(int i=0; i<count; ++i){
            if(i != count-1){
                printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
            }else{
                printf("%05d %d -1\n", node[i].address, node[i].data);
            }
        }
    }

    return 0;
}

