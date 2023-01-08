// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stdlib.h>
using namespace std;
int a[9][9],s[1000];//用队列s来存储a中的所有数据，按照顺时针的顺序遍历
int main()
{
    int m, n, i, j, k=0;
    m = rand() % 5 + 3;
    n = rand() % 5 + 3;
    for (i = 0; i <m; i++)
        for (j = 0; j < n; j++)
            a[i][j] = rand() % 9 + 1;
    cout << m << " " << n << endl;
    cout << "原矩阵为:" << endl;
    for (i =0; i <m; i++)
    {
        for (j = 0; j < n; j++)
            cout << a[i][j]<<" ";
        cout << endl;
    }
    int rowTop = 0, rowButtom = m- 1;
        int colLeft = 0, colRight = n - 1;
//我们把原矩阵顺时针存放到数组s中
        //下面进行顺时针螺旋遍历
    while (rowTop <= rowButtom && colLeft <= colRight) 
    {
        //从左往右
        for (int c = colLeft; c <= colRight; c++) 
        {
            s[k]=a[rowTop][c];
            k++;
        }
        //从上往下
        for (int r = rowTop + 1; r <= rowButtom; r++) 
        {
            s[k]=a[r][colRight];
            k++;
        }

        //判断是否会因只剩一行而重复遍历
        if (rowTop < rowButtom && colLeft < colRight) 
        {
            //从右往左
            for (int c = colRight - 1; c >= colLeft; c--) 
            {
                s[k]=a[rowButtom][c];
                k++;
            }
            //从下往上
            for (int r = rowButtom - 1; r > rowTop; r--)
            {
                s[k]=a[r][colLeft];
                k++;
            }
        }
        rowTop++;
        rowButtom--;
        colLeft++;
        colRight--;
    }
    //检验一下是否正确存储
    for (i = 0; i < k; i++)
        cout << s[i] << " ";
    cout << endl;
    //将最后一个数放到最前面
    for (i = k; i < 2 * k - 1; i++)
        s[i] = s[i - k];
    //检验一下是否正确操作
    for (i = k-1; i <2* k-1; i++)
        cout << s[i] << " ";
    cout << endl;
    //下面我们反过来将数组s按照顺时针顺序重新赋值给数组a，代码与遍历代码基本上一致
    int h = k-1;
    //重新赋值过
    rowTop = 0; rowButtom = m - 1;
    colLeft = 0; colRight = n - 1;
    while (rowTop <= rowButtom && colLeft <= colRight)
    {
        //从左往右
        for (int c = colLeft; c <= colRight; c++)
        {
            a[rowTop][c] = s[h];
            h++;
        }
        //从上往下
        for (int r = rowTop + 1; r <= rowButtom; r++)
        {
            a[r][colRight]=s[h];
            h++;
        }

        //判断是否会因只剩一行而重复遍历
        if (rowTop < rowButtom && colLeft < colRight)
        {
            //从右往左
            for (int c = colRight - 1; c >= colLeft; c--)
            {
                a[rowButtom][c]=s[h];
                h++;
            }
            //从下往上
            for (int r = rowButtom - 1; r > rowTop; r--)
            {
                a[r][colLeft]=s[h];
                h++;
            }
        }
        rowTop++;
        rowButtom--;
        colLeft++;
        colRight--;
    }
    cout << "移动后矩阵为:" << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
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
