#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct circles
{
    double x,y,r;
    double left;
}cir[100050];
long long fn[100050];
long long find(int i)
{
    if(fn[i]==i) return i;
    return fn[i] = find(fn[i]);
}
int cmp(struct circles a,struct circles b)
{
    return (a.left<b.left);
}
int main()
{
    long long n;
    scanf("%lld",&n);
    for(long long i = 0;i<n;i++)
    {
        scanf("%lf%lf%lf",&cir[i].x,&cir[i].y,&cir[i].r);
        cir[i].left = cir[i].x-cir[i].r;
        fn[i] = i;
    }
    long long count = n;
    sort(cir,cir+n,cmp);
    for(long long k = 0;k<n;k++)
    {
        long long tk = k+1;
        while(cir[tk].left<cir[k].x+cir[k].r&&tk<n)
        {
            if(((cir[k].x-cir[tk].x)*(cir[k].x-cir[tk].x)+(cir[k].y-cir[tk].y)*(cir[k].y-cir[tk].y))<((cir[k].r+cir[tk].r)*(cir[k].r+cir[tk].r)))
            {
                long long l = find(k),r = find(tk);
                if(fn[l]!=r) count--;
                fn[l] = r;
            }
            tk++;
        }
    }
    printf("%lld\n",count);
}
/* 万湖之国的形成
时间限制:2500MS  内存限制:65535K
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC;VC
Description
N国原是一块平原上，没有湖，直到一颗小行星撞入大气层碎成成千上万的碎片，碎片再撞击地面形成
一个一个的坑， 下雨之后，最终形成万湖之国。
现在科学家想用计算机模拟万湖之国形成过程，假设每一块碎片撞击地面，都撞出一个园形坑，现在知道
每一个碎片造成的坑的圆心和半径，问每个坑都注满水后，最终形成多少个湖？



输入格式
第一行一个整数N，1<=N<=100,000，表示坑的数量
此后N行，每一行三个double实数，前两个数是圆心的坐标x和y，最后一个数是圆半径（不大于1000）
(数据随机产生，分布均匀)


输出格式
湖的个数


输入样例
3
0 0 5
10 0 5
11.1 0 2.5


输出样例
2
*/
