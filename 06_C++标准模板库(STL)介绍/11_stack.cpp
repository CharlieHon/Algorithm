#include<cstdio>
#include<stack>
using namespace std;

int main()
{
    stack<int> st;
    for(int i=2; i<=6; ++i){
        st.push(i);
    }

    printf("st.size() = %d\n", st.size());
    printf("st.top() = %d\n", st.top());

    while(!st.empty()){
        st.pop();   //清空栈
    }

    if(st.empty()){
        printf("Empty\n");
    }else{
        printf("Not Empty\n");
    }

    return 0;
}