#include <iostream>
#include <algorithm>

using namespace std;

struct circle
{
    double x,y,r,left;
}cir[100050];

int f[100050];

int find(int i)
{
    if(f[i]==i) return i;
    return f[i]=find(f[i]);
}

int cmp(struct circle a,struct circle b)
{
    return (a.left<b.left);
}

main()
{
    int N,count,x2,x1;
    cin>>N;count=N;
    for(int i=0;i<N;i++)
    {
        cin>>cir[i].x>>cir[i].y>>cir[i].r;
        cir[i].left=cir[i].x-cir[i].r;
        f[i]=i;
    }
    sort(cir,cir+N,cmp);
    for(int i=0;i<N;i++)
    {
        int j=i+1;
        while(cir[i].x+cir[i].r>cir[j].left&&j<N)
        {
            if((cir[i].x-cir[j].x)*(cir[i].x-cir[j].x)+(cir[i].y-cir[j].y)*(cir[i].y-cir[j].y)<(cir[i].r+cir[j].r)*(cir[i].r+cir[j].r))
            {
                x1=find(i);x2=find(j);
                if(x1!=x2)count--;
                f[x2]=x1;
            }
            j++;
        }
    }
    cout<<count<<endl;
}
/* 万湖之国的形成
时间限制:2500MS  内存限制:65535K
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC;VC
Description
N国原是一块平原上，没有湖，直到一颗小行星撞入大气层碎成成千上万的碎片，碎片再撞击地面形成
一个一个的坑， 下雨之后，最终形成万湖之国。
现在科学家想用计算机模拟万湖之国形成过程，假设每一块碎片撞击地面，都撞出一个园形坑，现在知道
每一个碎片造成的坑的圆心和半径，问每个坑都注满水后，最终形成多少个湖？(相切不算同一个湖）



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
