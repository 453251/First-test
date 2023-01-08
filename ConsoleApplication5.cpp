// ConsoleApplication5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cmath>
#include<string>
using namespace std;
int main()
{
    char a[100]; cin >> a;
    int sum=0;
    for (int i = 7; i < 12; i++)
        a[i] = a[i - 7];
    cout << "移动前:";
    for (int i = 5; i < 12; i++)
        cout << a[i];
    cout << endl;
    for (int i = 5; i < 12; i++)
    {
        if (a[i] >= '1' && a[i] <= '4')
            a[i] = a[i] + 18;
        else if (a[i] >= '5' && a[i] <= '9')
            a[i] = a[i]-5;
        else 
            a[i] = a[i] - 12;
    }
    cout << "减去5后:";
    for (int i = 5; i < 12; i++)
        cout << a[i];
    for (int i = 5; i < 12; i++)//十六进制转十进制
    {
        int temp;
        if (a[i] >= '1' && a[i] <= '9')
        {
            temp = (int(a[i]) - 48) * pow(16, 11 - i);
        }
        else
        {
            temp = (int(a[i]) - 55) * pow(16, 11 -i);
        }
        sum += temp;
    }
    cout <<endl<<"十进制:"<< sum << endl;//检查一下是否转换正确
    //讨论输出格式
    cout << "生日:";
    if (sum % 10000 < 1000)
    {
        if(sum%100>10)
            cout << sum / 10000 << "年" << "0" << sum % 10000 / 100 << "月" << sum % 100 << "日";
        else
            cout << sum / 10000 << "年" << "0" << sum % 10000 / 100 << "月" << sum % 10 << "日";
    }
    else
    {
        if (sum % 100 > 10)
            cout << sum / 10000 << "年" << sum % 10000 / 100 << "月" << sum % 100 << "日";
        else
            cout << sum / 10000 << "年" << sum % 10000 / 100 << "月" << sum % 10 << "日";
    }
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
