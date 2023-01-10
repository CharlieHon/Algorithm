#include<cstdio>
/**
 * @brief 有两个日期，求两个日期之间的天数，如果两个日期是连续的，则规定它们之间的天数为两天。
 * 有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
 * 每组数据输出一行，即日期差值
 * 20130101
 * 20130105
 * 5
 * 为了方便去除每个月的天数，不妨给定一个二维数组 int month[13][2]，用来存放每个月的天数，其中第二维为0表示平年，为1时表示闰年
 * @return int 
 */
int month[13][2] = {{0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};
bool isLeap(int year){  //判断是否是闰年
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main()
{
    int time1, y1, m1, d1;
    int time2, y2, m2, d2;
    while(scanf("%d%d", &time1, &time2) != EOF){
        if(time1 > time2){  //保证第一个日期小于第二个日期，否则交换之
            int temp = time1;
            time1 = time2;
            time2 = temp;
        }
        y1 = time1 / 10000, m1 = time1 / 100 % 100, d1 = time1 % 100;
        y2 = time2 / 10000, m2 = time2 / 100 % 100, d2 = time2 % 100;
        int ans = 1;    //记录结果
        while(y1 < y2 || m1 < m2 || d1 < d2){
            ++d1;
            if(d1 == month[m1][isLeap(y1)]+1){
                d1 = 1;
                ++m1;
            }
            if(m1 == 13){
                m1 = 1;
                ++y1;
            }
            ++ans;  //累计
        }
        printf("%d\n", ans);    //输出结果
    }
    return 0;
}