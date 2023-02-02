# 6.1 vector的常见用法详解

`vector`翻译为向量，更合理的叫法为“**可变数组**”，即长度根据需要而自动改变的数组。如果要使用vector，则需要添加vector头文件，即`#include<vector>`。除此之外，还需要在头文件下面加一句`using namespace std;`。

## vector的定义

```cpp
//单独定义一个vector
vector<typename> name;    //typename可以是任何基本类型，例如int、double、char、结构体等，也可以是STL标准容器
vector<int> vi;
vector<double> vd;
vector<vector<int> > vvi;    //>>之间要加空格，因为一些使用C++11之前标准的编译器会把它视为移位操作
vector<typename> Arrayname[arraySize];    //vector数组，一位长度已经固定为arraySize，另一维可变
```

## vector容器内元素的访问

1. 通过**下标**访问
和普通的数组是一样的，对一个定义为`vector<typename> vi`容器来说，直接访问 vi[index] 即可。
2. 通过**迭代器**访问
迭代器(iterator)可以理解为类似**指针**的东西，其定义是`vector<typename>::iterator it;`。这样就得到了迭代器it，并且可以通过`*it`来访问vector里的元素。

```cpp
vector<int> vi;
for(int i=1; i<=5; ++i){
    vi.push_back(i);
}
//vi.begin()为取vi的首元素地址，而it指向这个地址
vector<int>::iterator it = vi.begin()
for(int i=0; i<5; ++i){
    printf("%d ", *(it+i));    //输出vi[i]
}
```

输出结果：`1 2 3 4 5`。这里可以看出 **vi[i] 和 *(vi.begin()+i)是等价的**。

> begin()函数的作用是取vi的首元素地址，而end()并不是取vi的尾元素地址，而是取尾元素地址的下一个地址。end()作为迭代器末尾标值，不存储任何元素。

除此之外，迭代器还实现了两种自加操作：`++it和it++`(自减操作同理)，于是有了另一种遍历vector中元素的写法：

```cpp
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
    vector<int> vi;
    for(int i=1; i<=5; ++i){
        vi.push_back(i);
    }
    //vector的迭代器不支持 it<vi.end()写法，因此循环条件只能用 it != vi.end()
    for(vector<int>::iterator it=vi.begin(); it!=vi.end(); ++it){
        printf("%d ", *it);
    }
    return 0;
}
```

> 在常用STL容器中，只有在vector和string中，才允许使用vi.begin()+3这种迭代器加上整数的写法。

## vector常用函数实例解析

1. push_back()
`push_back()`在vector后面添加一个元素x，时间复杂度为O(1)。
2. pop_back()
`pop_back()`删除vector的尾元素，事件复杂度为O(1)。
3. size()
`size()`用来获得vector中元素的个数，时间复杂度为O(1)。size()返回的是`unsigned`类型，不过一般来说用`%d`不会出很大问题。
4. clear()
`clear()`用来清空vector中的所有元素，时间复杂度为O(N)，其中N为vector中元素的个数。
5. insert()
`insert(it, x)`用来向vector的任意迭代器it处插入一个元素x，时间复杂度O(N)
6. erase()
`erase()`有两种用法：删除单个元素，删除一个区间内的所有元素。时间复杂度均为O(N)
   1. 删除单个元素：`vi.erase(it)`即删除迭代器为it处的元素。
   2. 删除一个区间内的所有元素：`vi.erase(first, last)`即删除[first, last)内的所有元素。如果要删除vector内的所有元素，可以用`vi.erase(vi.begin(), vi.end())`。

## vector的常见用途

1. 存储数据
   1. vector本身可以作为数组使用，而且在一些元素个数不确定的常合可以很好地节省空间。
   2. 有些常合需要根据一些条件把部分数据输出在同一行，数据中间用空格隔开。由于输出数据地个数是不确定地，为了更方便地处理最后一个满足条件的数据后面不输出额外的空格，可以先用vector记录所有需要输出的数据，然后一次性输出。
2. 用邻接表存储图
