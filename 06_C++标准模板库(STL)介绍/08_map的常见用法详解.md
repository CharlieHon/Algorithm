# 6.4 map的常用用法详解

`map`翻译为映射。在定义数组时，如`int array[10]`其实是定义了一个从int型到int型的映射，比如array[0]=25是将0映射到25。无论是什么类型，它总是将int型映射到其他类型，其弊端在于当需要以其他类型作为关键字来做映射时，会显得不太方便。而**map可以将任何基本类型(包括STL容器)映射到任何基本类型(包括STL容器)**，比如可以建立string型到int型的映射。

```cpp
#include<map>            //使用map，需要添加map头文件
using namespace std;     //还得加上这句
```

## map的定义

```cpp
/*
 * map和其他STL容器在定义上不同，因为map需要确定映射前类型(键key)和映射后类型(值value)
 * 所以需要在<>内填写两个类型。
 */
map<typename1, typename2> mp;    //单独定义一个map

//如果是字符串到整型的映射，必须使用 string 而不能用char数组
map<string, int> mp;

//map的键和值也可以是STL容器
map<set<int>, string> mp;
```

## map容器内元素的访问

map一般有两种访问方式：通过下标访问或通过迭代器访问。

### 通过下标访问

和访问普通的数组一样，例如对一个定义为 `map<char, int> mp` 的map来说，可以直接使用 `mp['c']` 的方式来访问它对应的整数。需要注意的是，**map中的键是唯一的**。

```cpp
map<char, int> mp;
mp['c'] = 20;    //建立映射
mp['c'] = 30;    //新映射
printf("%d\n", mp['c']);    //30
```

### 通过迭代器访问

map迭代器的定义和其他STL容器迭代器定义的方式相同：`map<typename1, typename2> it;`

因为 map 的每一对映射都有两个 typename，这决定了必须通过一个 it 来同时访问键和值。**map可以使用`it->first`来访问键，使用`it->second`来访问值。**

```cpp
map<char, int> mp;
mp['m'] = 20;
mp['r'] = 30;
for(map<char, int>::iterator it=mp.begin(); it!=mp.end(); ++it){
    printf("%c %d\n", it->first, it->second);
}
```

### map的常用函数实例解析

1. find()
`find()`返回键为key的映射的迭代器，时间复杂度为O(logN)，N为map中映射的个数。
2. erase()
`erase()`有两种用法：删除单个元素，删除一个区间内的所有元素。
   1. 删除单个元素。`mp.erase(it)`，it为需要删除的元素的迭代器。时间复杂度为O(1)。`mp.erase(key)`，key为欲删除的映射的键。时间复杂度为O(logN)，N为map内元素的个数。
   2. 删除一个区间内的所有元素。`mp.erase(first, lat)`，其中first为需要删除的区间的起始迭代器，而last则为需要删除区间的末尾迭代器的下一个地址，也即为删除左闭右开的区间[first, last)。时间复杂度为O(last-first)。
3. size()。用来获得map中映射的对数，时间复杂度为O(1)。
4. clear()。用来清空map中的所有元素，复杂度为O(N)，其中N为map中元素的个数。

## map的常见用途

1. 需要建立字符(或字符串)与整数之间映射的题目，使用map可以减少代码量
2. 判断大整数或者其他类型数据是否存在的题目，可以把map当bool数组用。
3. 字符串和字符串的映射也可能会遇到。

> 延伸：map的的键和值是唯一的，而如果一个键需要对应多个值，就只能用 `multimap`。
