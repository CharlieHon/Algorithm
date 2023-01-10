# sort()

## 1.如何使用sort排序

sort函数的使用必须加上头文件`#include<algorithm>`和`using namespace std;`，其使用方法如下：

```cpp
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    //sort的参数有三个，其中前两个是必填的，而比较函数则可以根据需要填写，如果不写则默认对前面给出的区间进行递增排序
    sort(首元素地址(必填), 尾元素地址的下一个地址(必填), 比较函数(非必填));
    return 0;
}
```

## 2.如何实现比较函数cmp

如果需要对序列进行排序，那么序列中的元素一定要有可比性。因此需要执行排序规则来建立这种可比性。sort的第三个可选参数就是compare函数(一般写作`cmp`函数)，用来实现这个规则。

### 2.1.基本数据类型数组的排序

若比较函数不填，则默认按照从小到大的顺序排序。
如果想从大到小来排序，则要使用比较函数`cmp`来“告诉”sort何时要交换元素(让元素的大小比较关系反过来)。

```cpp
#include<stdio.h>
#include<algorithm>
bool cmp(int a, int b){    //改变比较元素类型，可以实现对不同数据类型自定义排序
    return a > b;    //可以理解为当a > b时把a放在b前面
}
```

### 2.2.结构体数组的排序

现在定义了如下的结构体：

```cpp
struct node{
    int x, y;
}ssd[10];
```

如果想将ssd数组按照x从大到小排序(即一级排序)，那么可以这样写cmp函数：

```cpp
bool cmp(node a, node b){
    return a.x > b,x;
}
```

而如果想先按x从大到小排序，但当x相等的情况下，按照y的大小从小到大来排序(即进行二级排序)，那么cmp的写法是：

```cpp
bool cmp(node a, node b){
    if(a.x != b.x)    return a.x > b.x;
    else    return a.y < b.y;
}
```

### 2.3.容器的排序

在STL标准容器中，只有`vector`, `string`, `deque`是可以用sort的。这是因为像set，map这种容器是用红黑树实现的，元素本身有序，故不允许使用sort排序。

下面以vector为例：

```cpp
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a, int b){    //因为vector中的元素为int型，因此仍然是int的比较
    return a > b;
}
int main()
{
    vector<int> vi;
    vi.push_back(3);
    vi.push_back(1);
    vi.push_back(2);
    sort(vi.begin(), vi.end(), cmp);    //对整个vector排序
    for(int i=0; i<3; ++i){
        printf("%d ", vi[i]);
    }
    /*输出结果
    3 2 1
    */
    return 0;
}
```

再来看string的排序：

```cpp
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string str1, string str2){
    return str1.length() < str2.length();    //按string的长度从小到大排序
}
int main()
{
    string str[3] = {"bbbb", "cc", "aaa"};
    sort(str, str+3);    //将string型数组按字典序从小到大输出
    for(int i=0; i<3; ++i){
        cout << str[i] << endl;
    }
    /*输出结果
    aaa
    bbbb
    cc
    */
    sort(str, str+3, cmp);    //将string型数组按字典序从小到大输出
    for(int i=0; i<3; ++i){
        cout << str[i] << endl;
    }
    /*输出结果
    cc
    aaa
    bbbb
    */
    return 0;
}
```
