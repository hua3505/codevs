/*
����:959547664@qq.com
��Ŀ:p1212 ���Լ��
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
