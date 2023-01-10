#include<cstdio>

struct studentInfo{
    int id;
    char gender;
    studentInfo *next;  //用来指向下一个学生的地址
}stu, *p;
/**
 * 访问stu变量的写法如下：
 * stu.id
 * stu.name
 * stu.next
 * 访问指针变量p中元素的写法如下：
 * (*p).id
 * (*p).name
 * (*p).next 
 * 访问结构体指针变量内元素的更简洁的写法：
 * p->id
 * p->name
 * p->next
 */
int main()
{
    //结构体的初始化
    stu.id = 1;
    stu.gender = 'M';
    //或者在读入时进行幅值
    scanf("%d %c", &stu.id, &stu.gender);
    return 0;
}