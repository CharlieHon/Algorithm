#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    cout << str << endl;

    string str1 = "charlie";
    for(string::iterator it=str1.begin(); it!=str1.end(); ++it){
        cout << *it;
    }
    cout << endl;

    for(int i=0; i<str1.size(); ++i){
        cout << str1[i];
    }
    cout << endl;

    
    string str2 = "man";
    //字符串拼接
    cout << str1 + str2 << endl;

    //两个string类型可以直接比较大小，比较规则是字符序
    cout << "compare: " << (str1 > str2) << endl;

    cout << "str1.size(): " << str1.size() << endl;

    str1.insert(7, "Hon");
    cout << str1 << endl;
    str2.insert(str2.end(), str1.begin(), str1.begin()+7);
    cout << str2 << endl;

    string str3 = "Hello";
    //删除单个元素，参数为需要删除的元素的迭代器
    str3.erase(str3.begin());
    cout << str3 << endl;
    //删除一个区间内的所有元素
    str3.erase(1, 3);       //str.erase(pos, length)
    cout << str3 << endl;
    //清空
    str3.clear();

    string str4 = "Leslie";
    cout << str4.substr(2, 3) << endl;

    //查找字串，str.find(str2, pos)，从str的pos号位开始匹配str2，返回其在str中第一次出现的位置
    cout << str4.find("e", 2) << endl;

    return 0;
}