#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct mark
{
    char name[50];
    int ac;
    int ftime;
    int q[15];
};

vector<struct mark> marks;

int cmp(struct mark a, struct mark b)
{
    return ((a.ac > b.ac) || (a.ac == b.ac && a.ftime < b.ftime) || (a.ac == b.ac && a.ftime == b.ftime && strcmp(a.name, b.name) < 0));
}

main()
{
    char name[50], q;
    int time, r, num = 0, i;
    while (scanf("%d %s %c %d", &time, &name, &q, &r) == 4)
    {
        for (i = 0; i < num; i++)
            if (strcmp(marks[i].name, name) == 0)
                break;
        if (i == num)
        {
            struct mark tmp;
            strcpy(tmp.name, name);
            tmp.ac=0;tmp.ftime=0;for(int x=0;x<15;x++)tmp.q[x]=0;
            num++;
            marks.push_back(tmp);
        }
        if (r == 0 && marks[i].q[q - 65] != -1)
        {
            marks[i].ftime += (marks[i].q[q - 65] * 20 + time);
            marks[i].q[q - 65] = -1;
            marks[i].ac++;
        }
        if (r != 0 && marks[i].q[q - 65] != -1)
            marks[i].q[q - 65]++;
    }
    sort(marks.begin(), marks.end(), cmp);
    for (int i=0; i < num && marks[i].ac != 0; i++)
        cout << marks[i].name << " " << marks[i].ac << " " << marks[i].ftime << endl;
}
/*每行一个评判结果，格式为：时间（第几分钟提交的）+半角空格+队名+半角空格+题号+半角空格+评判结果（0通过，其它为出错）
题号由大写A字符开始，第2题是B，依次类推，最多不超过15题
所有评判结果已经按时间排序好
输出格式
输出排名，一行一个，格式为队名+半角空格+通过题数+半角空格+罚时
注：0题的队伍不需要输出
测试数据中，没有同题且同罚时的情况
输入样例
2 abc A 4
5 abc B 0
6 def A 0
10 abc A 0
13 xyx A 4
20 def B 5
输出样例
abc 2 35
def 1 6
*/
