# 6.3 string的常见用法详解

在C语言中，一般使用字符数组`char str[]`来存放字符串，但是使用字符数组有时会显得操作麻烦，而且容易因经验不足而产生一些错误。C++在STL中加入了string类型，使用需要添加`string`头文件，即`#include<string>`(**注意string.h和string是不一样的头文件**)。除此之外，还需要在头文件下面加上一句`using namespace std;`。

## string的定义

```cpp
//定义string的方式跟基本数据类型相同，只需要在string后跟上变量名即可
string str;
//初始化，直接给string类型的变量进行赋值
string str = "abcde";
```

## string中内容的访问

1. **通过下标访问**
一般来说，可以直接像字符数组那样去访问string。如果要读入和输出整个字符串，则只能用`cin`和`cout`。

```cpp
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    cout <<str;

    return 0;
}
```

> 其实可以用`c_str()`将string类型转换为字符数组进行输出。
>
> `printf("%s\n", str.c_str());`

2. **通过迭代器访问**

```cpp
//string不像其他STL容易那样需要参数，可以直接定义
string::iterator it;
//string 和 vector 一样，支持直接对迭代器进行加减某个数字
*(str.begin()+3);    //是可行的
```

3. string常用函数实例解析
   1. `operator+=`，string的加法，可以将两个string直接拼接起来。
   2. `compare operator`，两个string类型可以直接使用`==, !=, <, <=, >, >=`比较大小，比较规则是**字典序**。
   3. `length()/size()`，返回string的长度，即存放的字符数，时间复杂度为O(1)。二者基本相同。
   4. `insert()`，string的insert()函数有很多写法，这里给出几个常用的写法，时间复杂度为O(N)。
      1. `insert(pos, string)`，在pos号位置插入字符串string。
      2. `insert(it, it2, it3)`，it为原字符串的欲插入位置，it2和it3为待插入字符串的首尾迭代器，用来表示串[it2, it3)将被插入在it的位置上。
   5. `erase()`，有两种用法：删除单个元素、删除一个区间内的所有元素。时间复杂度为O(N)。
      1. 删除单个元素。`str.erase(it)`用于删除单个元素，it为需要删除的元素的迭代器。
      2. 删除一个区间内的所有元素。有两种方法：
         1. `str/erase(first, last)`，其中first为需要删除的区间的起始迭代器，而last则为需要删除的区间的末尾迭代器的下一个地址，也即为删除[first, last)。如`str.erase(str.begin(), str.begin()+3)`。
         2. `str.erase(pos, length)`，其中pos为需要开始删除的起始位置，length为删除的字符个数。如`str.erase(3, 2)`。
   6. `clear()`，用以清空string中的数据，时间复杂度一般为O(1)。
   7. `substr()`，`substr(pos, len)`返回从pos开始、长度为len的字串，时间复杂度为O(len)。
   8. `string::npos`，是一个常数，其本身值为-1，但由于是unsigned_int类型，因此实际上也可以认为是unsigned_int类型的最大值。用以作为`find`函数失匹配时的返回值。
   9. `find()`，`str.find(str2)`，当str2是str的子串时，返回在str中第一次出现的位置；如果str2不是str的字串，那么返回`string::npos`。`str.find(str2, pos)`，从str的pos号位开始匹配str2，返回值与上相同。时间复杂度为O(nm)，其中n和m分别是str和str2的长度。
   10. `replace()`，时间复杂度为O(str.length())。
       1. `str.replace(pos, len, str2)`把str从pos号位开始、长度为len的子串替换为str2.
       2. `str.replace(it1, it2, str2)`把str的迭代器[it1, it2)范围的子串替换为str2。
