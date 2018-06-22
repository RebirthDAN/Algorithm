#include <iostream>
#include <cstdio>
#define abs(x) ((x)>0?(x):-(x))


using namespace std;

int count;

void dfs(int n,int A[],int cur)
{
    int i;
    if(cur==n) count++;
    else for(i=1;i<=n;i++)
    {
        int ok=1,j;
        for(j=0;j<cur;j++)if(A[j]==i|| abs(i-A[j])== abs(cur-j)){ok=0;break;}
        if(ok)
        {
            A[cur]=i;
            dfs(n,A,cur+1);
        }
    }
}

int main()
{
    int T,N,a[13]={0};
    cin>>T;
    while(T--)
    {
        count=0;
        cin>>N;
        dfs(N,a,0);
        cout<<count<<endl;
    }
}
/*18124 N皇后问题
时间限制:2000MS  内存限制:65535K
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC;VC
Description
有N*N的国际象棋棋盘，要求在上面放N个皇后，要求任意两个皇后不会互杀，有多少种不同的放法？



输入格式
每一个数为T，代表CASE的数量，T<=13
此后，每行一个数N（13>=N>0）


输出格式
每一个CASE，输出对应答案


输入样例
2
4
5


输出样例
2
10
*/
