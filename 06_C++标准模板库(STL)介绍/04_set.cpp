#include<cstdio>
#include<set>
using namespace std;

int main()
{
    set<int> st;
    for(int i=1; i<=9; ++i){
        st.insert(i);
    }

    for(set<int>::iterator it=st.begin(); it!=st.end(); ++it){
        printf("%d ", *it);
    }
    printf("\n");

    //插入元素
    st.insert(10);
    //删除元素
    st.erase(st.begin());  //删除st开头位置的元素
    st.erase(2);    //删除值为2的元素
    st.erase(st.find(4), st.end()); //删除4~10
    for(auto i : st){
        printf("%d", i);    //3 只剩下了元素3
    }
    printf("\n");

    printf("%d\n", st.size());  //返回st的大小

    st.clear();                 //将st清空
    printf("%d\n", st.size());

    return 0;
}