# 6.8 pair的常见用法详解

当想要将两个元素绑在一起作为一个合成元素，又不想要因此定义结构体时，使用pair可以很方便地作为一个替代品。也就是说，pair实际上可以看作一个内部有两个元素的结构体，且这两个元素的类型是可以指定的，如下面的短代码所示：

```cpp
struct pair{
    typename1 first;
    typename2 second;
};
```

## pair的定义

```cpp
#include<utility>
#include<string>
using namespace std;

int main()
{
    // pair<typename1, typename2> name;
    pair<string, int> p;
    //在定义pair时进行初始化，只需要跟上一个小括号，里面填写两个想要初始化的元素即可
    pair<string int> p1("hello", 5);
    //在代码中临时构建一个pair，有如下两种方式：
    pair<string, int> p2("haha", 5)
    make_pair("hi", 10);
    return 0;
}
```

## pair中元素的访问和常用函数实例解析

pair中只有两个元素，分别是first和second，只需要按正常结构体的方式访问即可。

```cpp
#include<iostream>
#include<utility>
#include<string>
using namespace std;

int main()
{
    pair<string, int> p;
    p.first = "hi";
    p.second = 10；
    cout << p.first << " " << p.second << endl;    //hi 10
    p = make_pair("xixi", 55);
    cout << p.first << " " << p.second << endl;    //xixi 55
    p = pair<string, int>("yes", 12);
    cout << p.first << " " << p.second << endl;    //tes 12
    return 0;
}
```

比较操作数

两个pair类型数据可以直接使用`==, !=, <, <=, >, >=`比较大小，**比较规则是先以first的大小作为标准，只有当first相等时才去判别second的大小**。

## pair的常见用途

关于pair有两个比较常见的例子：

1. 用来代替二元结构体及其构造函数，可以节省编码时间。
2. 作为map的键值对来进行插入。

```cpp
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    map<string, int> mp;
    mp.insert(make_pair("hi", 5));
    mp.insert(pair<string, int>("ha", 10));
    for(map<string, int>::iterator it=mp.begin(); it!=mp.end(); ++it){
        cout << it-> first << " " << it->second << endl;
    }
    //ha 10
    //hi 5
    return 0;
}
```
