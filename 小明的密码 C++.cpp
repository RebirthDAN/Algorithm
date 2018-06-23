#include <iostream>

using namespace std;

int count=0;
int p[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0};

int dfs(int a[],int cur,int n,int m)
{
    if(cur==n) count++;
    else
    {
        for(int i=0;i<10;i++)
        {
            int sum=0;
            for(int j=cur-m+1;j<cur&&j>=0;j++)sum+=a[j];
            sum+=i;
            if(p[sum]==1||cur<m-1)
            {
                a[cur]=i;
                dfs(a,cur+1,n,m);
            }
        }
    }
    return 0;
}

main()
{
    int a[13],N,M,T;
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        dfs(a,0,N,M);
        cout<<count<<endl;
        count=0;
    }
}
/*18025 小明的密码
时间限制:4000MS  内存限制:65535K
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC
Description
小明的密码由N（1<=N<=12）个数字构成，每个数字都可以是0至9中任意一个数字，但小明的密码还有
一个特点就是密码中连续的M（1<=M<=4）个数字的和是质数，现给定M和N，求满足条件的密码共有多少
个？



输入格式
第1行是T，case数量，此后T行，每行两个数，N和M


输出格式
每个case输出一个满足条件的密码总数


输入样例
2
1 1
2 1


输出样例
4
16
*/
