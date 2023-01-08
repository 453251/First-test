// ConsoleApplication4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
struct jiqi
{
    int flag;
    int time;
    int cnt;
}machine[100];
int main()
{
    int queue[100];
    int head = 0, tail = 0, m, n, Max = 0;
    cin >> m >> n;
    //读入每个学生的包裹数量
    for (int i = 0; i < n; i++)
    {
        cin >> queue[i];
        tail++;
    }
    while (head < tail)//当队列不为空时循环
    {
        //假设有一个学生站在m台机器面前，对m台机器进行遍历
        for (int i = 0; i < m; i++)
        {
            //找到了还未使用的机器
            if (machine[i].flag == 0)
            {
                machine[i].flag = 1;//标记该机器正在使用
                machine[i].time =queue[head];//读入该台机器需要使用的时间
                machine[i].cnt += queue[head];//这个是每一台机器所经过的总时间，最后我们计算结果时只需要取每台机器总时间的最大值即可
                head++;//将该名学生出队
            }
            //对于正在使用的机器
            if (machine[i].flag == 1)
            {
                machine[i].time--;//每一轮循环，时间都过去一秒，即还需要使用的时间自减1
                if (machine[i].time == 0)//如果该台机器需要使用时间为0
                    machine[i].flag = 0;//那么该台机器就可用
            }
        }
    }
    //找出最大的总时间，就是结果
    for (int i = 0; i < m; i++)
    {
        if (machine[i].cnt > Max)
            Max = machine[i].cnt;
    }
    cout << Max;
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
