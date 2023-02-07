# 6.7 stack的常见用法详解

```cpp
#include<cstdio>
#include<stack>
using namespace std;
int main()
{
    //1.stack的定义
    stack<typename> name;
    //2.stack容器内元素的访问
    //栈(stack)后进先出，只能通过top()来访问栈顶元素
    stack<int> st;
    for(int i=1; i<=5; ++i){
        st.push(i);
    }
    printf("%d", st.top());    //取栈顶元素
}
```

## stack常用函数实例解析

1. push()
push(x)将x入栈，时间复杂度为O(1)
2. top()
top()获得栈顶元素，时间复杂度为O(1)
3. pop()
pop()用以弹出栈顶元素，时间复杂度为O(1)
4. empty()
empty()可以检测 stack 是否为空，返回true为空，返回false为非空，时间复杂度为O(1)。
5. size()
size()返回stack内元素的个数，时间复杂度为O(1)。

```cpp
#include<cstdio>
#include<stack>
using namespace std;
int main()
{
    stack<int> st;
    for(int i=1; i<=5; ++i){
        st.push(i);    //将1 2 3 4 5依次入栈
    }
    for(int i=1; i<=3; ++i){
        st.pop();    //连续三次将元素出栈，即 5 4 3
    }
    printf("%d\n", st.top());    // 2

    printf("%d\n", st.size());    // 2

    if(st.empty()){
        printf("Empty\n");
    }else{
        printf("Not Empty\n");
    }
    
    return 0;
}
```

## stack的常见用途

stack用来模拟实现一些递归，防止程序对栈内存的限制而导致程序运行出错。一般来说，程序的栈内存空间很小，对有些题目，如果用普通的函数来进行递归，一旦递归层数过深，则会导致程序运行崩溃。
