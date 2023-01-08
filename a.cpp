// a.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// ConsoleApplication3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//利用深度优先搜索

#include <iostream>
using namespace std;
char a[3] = { '+','-','^' };//用char数组来存储对应操作
struct stack
{
    int cnt;//用来存储步骤数
    char ans[100];//用队列来存储步骤
    int j;//遍历ans，j指向队列最后一个元素的下一个位置
}s[100];//用一个栈来存储所有的情况
int n, top, Min = 99999999, xiabiao=999;//Min用来存储最小步骤数，xiabiao来存储最小步骤的下标
int dfs(int step, int num)//这里的step其实就是一种情况的步骤数
{
    int i;
    if (step > Min)//如果step超过当前的最小步骤的话，直接退出，舍弃这种情况，这样子使得存储到栈中的情况的步骤数尽可能的小
    {
        return 0;
    }
    if (num == 1)
    {
        if (Min > step)//更新Min，并返回最小步骤的下标
        {
            Min = step;
            xiabiao = top;
       }
        s[top].cnt = step;
        cout << step << endl;
        for (i = 0; i < step; i++)
            cout << s[top].ans[i];
        top++;//存储下一种情况
        //转入到下一种情况之后，我们要把top-1中的内容全部拷贝到当前的top中，
        for (i = 0; i < step; i++)
            s[top].ans[i] = s[top - 1].ans[i];
        s[top].j = s[top - 1].j;
        s[top].cnt = s[top - 1].cnt;
        cout << endl;
        return 0;
    }
    for (i = 2; i >=0; i--)//要让num尽可能的趋向于1，那么首先考虑除法，在考虑减法，最后考虑加法，但是事实上并不能保证这样子做一定是最小步骤
    {
        if (a[i] == '+')
        {
            s[top].ans[s[top].j] = a[i];//将该步骤入队
            s[top].j++;//入队之后j要自增1
            dfs(step + 1, num + 1);
            s[top].j--;//返回来之后又回到当前步骤，将j--相当于当前步骤出队了（j指向当前步骤），这样子我们下一次循环也是对当前步骤进行修改
                       //也就是说在对该次步骤进行下一次尝试之前，让j指向当前步骤
        }
        if (a[i] == '-')
        {
            s[top].ans[s[top].j] = a[i];
            s[top].j++;
            dfs(step + 1, num -1);
            s[top].j--;
        }
        if (a[i] == '^' && num % 2 == 0)
        {

            s[top].ans[s[top].j] = a[i];
            s[top].j++;
            dfs(step + 1, num/2);
            s[top].j--;
        }
    }
    return 0;
}
int main()
{
    int  min = 99999999;
    cin >> n;
    dfs(0, n);
    cout << "最小步骤数:" << s[xiabiao].cnt << endl;
    for (int i = 0; i < s[xiabiao].cnt; i++)
        cout << s[xiabiao].ans[i];
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
