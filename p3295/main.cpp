/*
����:959547664@qq.com
��Ŀ:p3295 �䵥����
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a;
    int b;
    cin >> a;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &b); //������cin ����һ�����볬ʱ����scanf��291ms
        a = a ^ b;
    }
    cout << a;
    return 0;
}
