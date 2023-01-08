// ConsoleApplication7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
//定义结构，用结构来表示字符串，字符串自带头尾，便于查找
struct str
{
    int head;
    int tail;
    char a[100];
};
int sign = 1;//sign用来判定是否属于输出ERROR的情况
struct str s1, s2,s3;
//第三步和第四步一起用递归做掉，就是输出对应字符的ascii码值的逆序数
//分为两个函数，是为了处理补0的情况
void nixushu1(int n)
{
    if (n / 10 == 0)
    {
        cout << n << "0";
        return;
    }
    else
    {
        cout << n % 10;
        nixushu1(n / 10);
    }
}
void nixushu2(int n)
{
    if (n / 10 == 0)
    {
        cout << n;
        return;
    }
    else
    {
        cout << n % 10;
        nixushu2(n / 10);
    }
}
//第一步的函数，查找中间帧的字符串
void chazhao(void)
{
    //头尾的差值正好就是字符串长度减1，它的长度就是对应字符串的长度
    s1.head = 0; s1.tail = strlen(s1.a)-1;
    //查找帧头和帧尾
    while (s1.tail < strlen(s3.a))
    {
        int flag = 1;//flag作为循环退出条件
        //看看连续的几个字符是不是与帧头吻合
        for (int i = s1.head; i <= s1.tail; i++)
        {
            //只要不吻合，退出循环，更新头尾指针
            if (s3.a[i] != s1.a[i - s1.head])
            {
                flag = 0;
                break;
            }
        }
        //如果找到了，直接退出循环，这句话应该放在更新头尾指针之前
        if (flag == 1)
            break;
        s1.head++; s1.tail++;
    }
    cout << s1.head << " " << s1.tail << endl;//输出头尾指针，检查一下是否正确
    if (s1.tail == strlen(s3.a))//如果查找不到，则是属于输出ERROR的情况，sign赋为0
        sign = 0;
    s2.head = 0; s2.tail = strlen(s2.a) - 1;
    while (s2.tail < strlen(s3.a))
    {
        int flag = 1;
        for (int i = s2.head; i <= s2.tail; i++)
        {
            if (s3.a[i] != s2.a[i - s2.head])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            break;
        s2.head++; s2.tail++;
    }
    cout << s2.head << " " << s2.tail << endl;
    if (s2.tail == strlen(s3.a))
        sign = 0;
    return;
}
int main()
{
    char b[100], c[100];
    int i, j = 0, cnt = 0, k = 0;
    cin >> s1.a; cin >> s2.a; cin >> s3.a;
    chazhao(); 
    //如果查找不到，则输出ERROR
    if (sign == 0)
    {
        cout << "ERROR";
        return 0;
   }
    //如果帧头和帧尾之间没有字符，则输出NONE
    if (s1.tail == s2.head || s1.head == s2.tail)
    {
        cout << "NONE";
        return 0;
    }
    //判断s1和s2的相对位置
    //s1在s2之前
    else if (s1.tail < s2.head)
    {
        //这个时候判断s1和s2哪个是帧头，我们希望s1是帧头，所以等号放在这儿
        if (strlen(s1.a) <= strlen(s2.a))
        {
            //从帧头的尾到帧尾的头之间的字符是需要读取的，我们把它存到数组b中
            for (i = s1.tail + 1; i <= s2.head - 1; i++, j++)
            {
                b[j] = s3.a[i];
            }
        }
        else
        {
            for (i=s2.head-1;i>=s1.tail+1;i--,j++)
            {
                b[j] = s3.a[i];
            }
        }
    }
    else if(s2.tail<s1.head)
    {
        if (strlen(s2.a) <= strlen(s1.a))
        {
            for (i = s2.tail + 1; i <= s1.head - 1; i++, j++)
            {
                b[j] = s3.a[i];
            }
        }
        else
        {
            for (i = s1.head - 1; i >= s2.tail + 1; i--, j++)
            {
                b[j] = s3.a[i];
            }
        }
    }
    //输出数组b，检查一下是否正确操作
    for (i = 0; i < j; i++)
        cout << b[i];
    cout << endl;
    //下面是挑出数组b中的大小写英文字母，将其存入数组c中
    //这里的cnt是用来计数的，是大小写英文字母的个数，也是数组c的长度
    for (i = 0; i < j; i++)
    {
        if (b[i] >= 'A' && b[i] <= 'Z' || b[i] >= 'a' && b[i] <= 'z')
        {
            cnt++;
            c[k] = b[i];
            k++;
        }
    }
    //如果没有大小写英文字母，则输出NONE
    if (cnt == 0)
    {
        cout << "NONE";
        return 0;
    }
    //再将大小写字母反转
    for (i = 0; i < cnt; i++)
    {
        if (c[i] >= 'A' && c[i] <= 'Z')
            c[i] = c[i] + 32;
        else if (c[i] >= 'a' && c[i] <= 'z')
            c[i] = c[i] - 32;
    }
    //输出数组c，检查一下是否正确操作
    for (i = 0; i < cnt; i++)
        cout << c[i];
    cout << endl;
    //第三步和第四步的操作，因为最后是倒过来输出，所以我们倒过来求每一个字符的ascii码的逆序数
    for (i = cnt - 1; i >= 0; i--)
    {
        //i等于0，也就是最后一位，是不需要补0的，所以使用nixushu2函数
        if (i == 0)
            nixushu2(int(c[i]));
        //需要补0的，就用nixushu1函数
        if (int(c[i]) < 100&&i!=0)
            nixushu1(int(c[i]));
        //不需要补0的，就用nixushu2函数
        else if(int(c[i])>=100)
            nixushu2(int(c[i]));
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
