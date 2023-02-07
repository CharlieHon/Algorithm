# 6.5 queue的常见用法详解

## queue的定义

```cpp
#include<cstdio>
#include<queue>        //要使用queue，应先添加头文件`#include<queue>`
using namespace std;    //并在头文件下面加上 `using namespace std;`

int main()
{
    queue<typename> name;
}
```

## queue容器内元素的访问

由于队列(queue)本身是一种先进先出的限制性数据结构，因此**STL中只能通过front()来访问队首元素，或是通过back()来访问队尾元素**。

```cpp
#include<cstdio>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    for(int i=1; i<=5; ++i){
        q.push(i);
    }

    printf("%d %d\n", q.front(), q.back());    // 1 5
    return 0;
}
```

## queue常用函数实例解析

1. push()
push(x)将x进行入队，时间复杂度O(1)
2. front(), back()
front()和back()分别返回队首元素和队尾元素，时间复杂度为O(1)。
3. pop()
pop()令队首元素出队，时间复杂度为O(1)。
4. empty()
empty()检测queue是否为空，返回true则空，返回false则非空，时间复杂度为O(1)。
5. size()
size()返回queue内元素的个数，时间复杂度为O(1)。

## queue的常见用途

当需要实现广度优先搜索时，可以不同自己手动实现一个队列，而是用queue作为代替，以提高程序的准确性。另外有一点注意的是，使用front()和pop()函数前，必须用empty()判断队列是否为空，否则可能因为队空而出现错误。

> STL的容器还有两中容器跟队列有关，分别是双端队列(deque)和优先队列(priority_queue)，前者是首尾皆可插入和删除的队列，后者是使用堆实现的默认将当前队列最大元素置于队首的容器。
