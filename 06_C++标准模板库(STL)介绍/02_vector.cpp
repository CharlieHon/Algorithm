#include<cstdio>
#include<vector>
using namespace std;

int main()
{
    vector<int> vi;
    for(int i=1; i<=10; ++i){
        vi.push_back(i);    //1, 2, 3, ..., 10
    }
    printf("vi.size()=%d\n", vi.size());

    for(vector<int>::iterator it=vi.begin(); it!=vi.end(); ++it){
        printf("%d ", *it);
    }
    printf("\n");

    //添加元素
    vi.push_back(100);
    //删除元素
    vi.pop_back();  //删除尾元素
    //擦除元素
    vi.erase(vi.begin()+1);
    for(auto i : vi){
        printf("%d ", i);
    }
    printf("\n");

    //清空元素
    vi.clear();
    printf("vi.size()=%d\n", vi.size());

    return 0;
}