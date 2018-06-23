#include <iostream>
#include <cstring>
 
using namespace std;

int L[1000][1000];

main()
{
    char a[1000],b[1000];
    gets(a);gets(b);
    int lenA=strlen(a),lenB=strlen(b);
    for(int i=0;i<lenA;i++)L[i][0]=0;
    for(int j=0;j<lenB;j++)L[0][j]=0;
    for(int i=1;i<lenA;i++)
        for(int j=1;j<lenB;j++)
            if(a[i]==b[j])L[i][j]=L[i-1][j-1]+1;
            else L[i][j]=(L[i-1][j]>L[i][j-1]?L[i-1][j]:L[i][j-1]);
    cout<<L[lenA-1][lenB-1]+1<<endl;
}
/*最长公共子序列
时间限制:1000MS  内存限制:65535K
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC;VC
Description
给定两个字符串，请输出这两个字符串的最大公共子序列



输入格式
两行，一行一个字符串（不包括空格，Tab键）,长度不超过1000


输出格式
输出最大公共子序列的长度


输入样例
abbca
aba


输出样例
3
*/
