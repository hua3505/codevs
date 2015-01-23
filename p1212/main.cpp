/*
作者:959547664@qq.com
题目:p1212 最大公约数
*/

#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a == b) return a;
    if (a < b) swap(a, b);

    return gcd(b, a - b);
}

int main()
{
    int a;
    int b;

    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}
