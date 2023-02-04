#include<iostream>
#include<string>
using namespace std;

int n;  //精度
//处理字符串s，e为指数
string deal_str(string s, int &e){
    int k = 0;
    while(s.size() > 0 && s[0] == '0'){
        s.erase(s.begin()); //删除前置的0，如"00123"->"123"
    }
    if(s[0] == '.'){    //如果去除0后，第一个是小数点，说明s是小于1的数
        s.erase(s.begin()); //去掉小数点
        while(s.size()>0 && s[0]=='0'){
            s.erase(s.begin()); //去掉小数点后非零位前的所有零
            --e;                //每去掉一个0，指数e减1
        }
    }else{                      //去掉前导0不是小数点，则找到后面的小数点删除
        while(k<s.size() && s[k]!='.'){ //寻找小数点
            ++k;
            ++e;    //只要不碰到小数点就让指数e+1
        }
        if(k<s.size()){ //while结束后 k<s.size()，说明碰到了小数点
            s.erase(s.begin()+k);   //把小数点删除
        }
    }

    if(s.size() == 0){  //如果去除前导0的长度变为0，说明这个数是0
        e = 0;
    }

    int num = 0;
    k = 0;
    string res;
    while(num < n){
        if(k < s.size())  res += s[k++];  //只要还有数字，就加到res末尾
        else    res += '0';             //否则res末尾添加0
        ++num;  //精度加1
    }

    return res;
}

int main()
{
    string s1, s2, s3, s4;
    cin >> n >> s1 >> s2;
    int e1 = 0, e2 = 0;
    s3 = deal_str(s1, e1);
    s4 = deal_str(s2, e2);

    if(s3==s4 && e1==e2){
        cout << "YES 0." << s3 << "*10^" << e1 << endl;
    }else{
        cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
    }

    return 0;
}