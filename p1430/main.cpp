/*
����:959547664@qq.com
��Ŀ:p1430 �����ж�
*/

#include <iostream>
#include <math.h>

using namespace std;

bool IsPrimeNumber(int n)
{
    if (n == 1) return false;
    if (n == 2) return true;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;

    cin >> n;
    bool bIsPrime = IsPrimeNumber(n);
    string str = bIsPrime ? "\\t" : "\\n";
    cout << str << endl;
    return 0;
}
