// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cmath>
using namespace std;
//判断一个数是否是素数
int isPrime(int n)
{
    int i;
    if (n == 0 || n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
    {
        for (i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return 0;
                break;
            }
        }
    }
    return 1;
}
int main()
{
    int n; cin >> n;
    int a, b, c;//考虑用两个或者三个素数来实现，三个已经足够表示了
    for(a=2;;a++)
        for (b = 2;; b++)
        {
            c = n - a - b;//c利用相减得到，降低时间复杂度
            if (isPrime(a)&&isPrime(b)&&isPrime(c))
            {
                printf("%d=%d+%d+%d", n, a, b, c);
                return 0;
            }
            else if (isPrime(a)&&isPrime(b)&&c == 0)
            {
                printf("%d=%d+%d", n, a, b);
                return 0;
            }
        }
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
