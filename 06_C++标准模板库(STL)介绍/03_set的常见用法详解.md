# 6.2 set的常见用法详解

set译为集合，是一个**内部自动有序且不含重复元素**的容器。使用set需要添加set头文件，即`#include<set>`，除此之外，还需要在头文件下面加上一句`using namespace std;`。

## set的定义

```cpp
//单独定义一个set
set<nametype> name;
set<int> name;
//set数组
set<int> a[100];    //a[0]~a[99]每一个都是一个set容器
```

## set容器内元素的访问

> set只能通过迭代器(iterator)访问。通过`*it`可以来访问set里面的元素。
>
> 除开vector和string之外的STL容器都不支持`*(it+1)`的访问方式，因此只能按如下方式枚举。

```cpp
set<typename>::iterator it;

set<int> st;
st.insert(3);    //insert(x)将x插入set中
st.insert(5);
st.insert(3);
st.insert(2);
for(set<int>::iterator it=st.begin(); it!=st.end(); ++it){
    printf("%d", *it);    //235    set内的元素自动递增排序，且自动去除了重复元素
}
```

## set常用函数实例解析

1. insert()
`insert(x)`将x插入set容器中，并自动递增排序和去重，时间复杂度O(logN)，其中N为set内的元素个数。
2. find()
`find(value)`返回set中对应值为value的迭代器，时间复杂度为O(logN)
3. erase()
`erase()`有两种用法：删除单个元素、删除一个区间内的所有元素。
   1. 删除单个元素。
      1. `st.erase(it)`，it为所需要删除元素的迭代器。时间复杂度为O(1)。可以结合find()函数来使用
      2. `st.erase(value)`，value为所需要删除元素的值。时间复杂度为O(logN)，N为set内元素个数。
   2. 删除一个区间内的所有元素。
      1. `st.erase(first, last)`可以删除一个区间内的所有元素，其中first为所需要删除区间的起始迭代器，而last为所需要删除区间的末尾迭代器的下一个地址，也即为删除[first, last)。时间复杂度为O(last-first)。
4. size()
`size()`用来获得set内元素的个数，时间复杂度为O(1)。
5. clear()
`clear()`用来清空set中的所有元素，复杂度O(N)，其中N为set内元素的个数。

## set的常见用途

set最主要的作用是自动去重并按升序排序，因此碰到需要去重但是却不方便直接开数组的情况，可以尝试用set解决。

> set中元素是唯一的，如果需要处理不唯一的情况，则需要使用 `multiset`。另外，C++11标准中还增加了unordered_set，以散列代替set内部的红黑树实现，使其可以用来处理只去重但不排序的需求，速度比set要快得多。
