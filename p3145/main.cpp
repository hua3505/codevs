/*
����:959547664@qq.com
��Ŀ:p3145 ��ŵ����Ϸ
*/

#include <iostream>
#include <math.h>

using namespace std;

typedef enum
{
    TOWER_A,
    TOWER_B,
    TOEWR_C,
} TOWER;

void Move(int n, TOWER moveFrom, TOWER moveTo)
{
    char cFrom = 'A' + moveFrom;
    char cTo = 'A' + moveTo;
    cout << n << " from " << cFrom << " to "  << cTo << endl;
}

TOWER FindAnotherTower(TOWER t1, TOWER t2)
{
    return static_cast<TOWER>(3 - t1 - t2);
}

void Foo(int n, TOWER moveFrom, TOWER moveTo)
{
    if (n > 1)
    {
        Foo(n - 1, moveFrom, FindAnotherTower(moveFrom, moveTo));
        Move(n, moveFrom, moveTo);
        Foo(n - 1, FindAnotherTower(moveFrom, moveTo), moveTo);
    }
    else
    {
        Move(1, moveFrom, moveTo);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << endl;
    Foo(n, TOWER_A, TOEWR_C);

    return 0;
}
