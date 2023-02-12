#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    //map实现包含了pair，所以可以使用#include<map>代替#include<utility>
    pair<string, int> p1("hi", 10);
    cout << p1.first << " " << p1.second << endl;

    pair<string, int> p2("ko", 12);
    pair<string, int> p3("ko", 6);

    if(p1 > p2) cout << "p1 > p2" << endl;
    if(p2 > p3) cout << "p2 > p3" << endl;  //p2 > p3

    map<string, int> mp;
    mp.insert(pair<string, int>("apple", 5));
    mp.insert(make_pair("banana", 10));

    for(map<string, int>::iterator it=mp.begin(); it !=mp.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}