#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct fruit{
    string name;
    int price;
    friend bool operator < (const fruit &f1, const fruit &f2){
        return f1.price < f2.price; //价格大的优先级高
    }
}f1, f2, f3;


int main()
{
    priority_queue<int> q1;
    q1.push(3);
    q1.push(5);
    q1.push(1);

    cout << q1.top() << endl;    //5 输出队首元素
    cout << q1.size() << endl;  //3 队列大小
    cout << q1.empty() << endl; //false/0 是否为空
    q1.pop();   //弹出队首元素5
    cout << q1.top() << endl;   //4
    q1.pop();
    q1.pop();

    if(q1.empty())  cout << "Empty" << endl;
    else    cout << "Not empty" << endl;

    priority_queue<fruit> q2;
    f1 = {"apple", 3}, f2 = {"banana", 5}, f3 = {"watermelon", 2};
    q2.push(f1);
    q2.push(f2);
    q2.push(f3);
    cout << q2.top().name << " " << q2.top().price << endl;

    return 0;
}