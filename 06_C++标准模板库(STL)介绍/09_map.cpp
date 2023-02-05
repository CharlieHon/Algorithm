#include<cstdio>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<char, int> mp;
    string str = "abcdefg";

    int i = 1;
    for(string::iterator it=str.begin(); it!=str.end(); ++it){
        mp[*it] = i++;    //建立映射
    }

    //遍历map
    printf("iterator the map\n");
    for(map<char, int>::iterator it=mp.begin(); it!=mp.end(); ++it){
        printf("%c %d\n", it->first, it->second);
    }

    //通过下标访问元素
    printf("index:\n");
    printf("%d %d\n", mp['a'], mp['b']);

    //通过迭代器访问元素
    printf("iterator\n");
    map<char, int>::iterator it = mp.find('f');
    printf("%c %d\n", it->first, it->second);

    //map大小
    printf("the size of map\n");
    printf("%d\n", mp.size());

    //删除单个元素
    printf("erase an element of the map\n");
    mp.erase('a');
    printf("%c %d\n", mp.begin()->first, mp.begin()->second);

    //清空map
    printf("clear the map");
    mp.clear();

    return 0;
}