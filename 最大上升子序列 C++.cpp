#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int N,a[1000],i=0,LIS[1000];
    cin>>N;
    for(i=0;i<N;i++) cin>>a[i];
    LIS[0]=1;
    for(i=1;i<N;i++)
    {
        int max=1;
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j]&&max<LIS[j]+1)max=LIS[j]+1;
        }
        LIS[i]=max;
    }
    cout<<*max_element(LIS,LIS+N)<<endl;
}
/*最大上升子序列
时间限制:1000MS  内存限制:65535K
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC;VC
Description
给一个数列，输出最大上升子序列的数字个数。



输入格式
第一行一个数字N，N<=1000
第二行N个数字，数字之间有一个空格分格


输出格式
输出最大上升子序列数字个数


输入样例
4
1 1 5 3


输出样例
2
*/
