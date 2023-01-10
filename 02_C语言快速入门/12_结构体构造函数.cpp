#include<cstdio>
/**
 * @brief 构造函数就是用来初始化结构体的一种函数，它直接定义在结构体中。
 * 构造函数的一个特点是它不需要写返回类型，且函数名与结构体名相同。
 * 一般的，结构体内部会生成一个默认的构造函数(但不可见)。
 * 默认构造函数没有返回类型，所以 studentInfo 前面没有写东西；没有参数，所以小括号内是空的；没有函数体，因此花括号内也是空的。
 * 由于这个构造函数的存在，才可以直接定义 studentInfo 类型的变量而不进行初始化
 * 
 * 可以自定义构造函数进行初始化
 * 
 * 如果自己重新定义了构造函数，则不能不经初始化定定义结构体变量，因为默认构造函数被覆盖了
 * 但是可以把默认构造函数手动加上，只要参数个数和类型不完全相同，就可以定义任意多个构造函数，以适应不同的初始化场合。
 */

struct studentInfo{
    int id;
    char gender;
    //默认生成的构造函数
    studentInfo(){}
    //下面的参数用以对结构体内部变量进行赋值
    studentInfo(int _id, char _gender){
        //赋值
        id = _id;
        gender = _gender;
    }
    //构造函数也可以简化为一行
    // studentInfo(int _id, char _gender) : id(_id), gender(_gender)    {}

};

struct Point{
    int x, y;
    Point(){}   //用以不经初始化地定义pt[10]
    Point(int _x, int _y) : x(_x), y(_y)    {}  //用以提供x和y的初始化
}pt[10];

int main()
{
    int num = 0;
    for(int i=1; i<=3; ++i){
        for(int j=1; j<=3; ++j){
            pt[num++] = Point(i, j);    //直接使用构造函数
        }
    }

    for(int i=0; i<num; ++i){
        printf("%d,%d\n", pt[i].x, pt[i].y);
    }

    return 0;
}