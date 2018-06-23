#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;
priority_queue<long long,vector<long long>,greater<long long> >q;

main()
{
    long long a[2500],x,x2,T;
    set<long long>s;
    q.push(1);
    for(int i=0;i<1500;i++)
    {
        x=q.top();q.pop();
        a[i]=x;
        x2=x*2;
        if(!s.count(x2)){s.insert(x2);q.push(x2);}
        x2=x*3;
        if(!s.count(x2)){s.insert(x2);q.push(x2);}
        x2=x*5;
        if(!s.count(x2)){s.insert(x2);q.push(x2);}
    }
    cin>>T;
    while(T--)
    {
        cin>>x;
        for(int i=1,x2=0;i<1500;i++)
        {
            x2+=a[i]-a[i-1]-1;
            if(x2>=x){x=a[i]-1-(x2-x);break;}
        }
        cout<<x<<endl;
    }
}
/*
18005 It is not ugly number
时间限制:2000MS  内存限制:65535K
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC
Description
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence1, 2, 3, 4, 5, 6, 8, 9, 10, 12, ...shows the 
first 10 ugly numbers. By convention, 1 is included. Then, here are the first 10 Not ugly numbers:7, 11, 13, 14, 17, 19, 
21, 22, 23, 26. Given the integer n, write a program to find and print the n'th Not ugly number.



输入格式
First line is T（T<=10000）, the number of cases.
The T lines following. Each line of the input contains a positive integer n (n <= 100000000).


输出格式
For each case, output the n'th Not ugly number .


输入样例
3
1
2
9


输出样例
7
11
23*/
