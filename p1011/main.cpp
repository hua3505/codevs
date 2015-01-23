/*
作者:959547664@qq.com
题目:p1011 数的计算
*/


#include <iostream>

using namespace std;

int GetSpecialNumCount(int n)
{
    int num = 1;

    for (int i = 1; i <= n / 2; i++)
    {
        num += GetSpecialNumCount(i);
    }
    return num;
}

int main()
{
    int n;
    cin >> n;
    cout << GetSpecialNumCount(n);
    return 0;
}
