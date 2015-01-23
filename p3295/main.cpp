/*
作者:959547664@qq.com
题目:p3295 落单的数
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
        scanf("%d", &b); //这里用cin 最大的一个输入超时，用scanf才291ms
        a = a ^ b;
    }
    cout << a;
    return 0;
}
