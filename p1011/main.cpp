/*
����:959547664@qq.com
��Ŀ:p1011 ���ļ���
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
