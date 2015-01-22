/*
作者:959547664@qq.com
题目:p1842 递归第一次
*/


#include <iostream>
#include <vector>
using namespace std;


vector <int> vtFNum;

void F(int nK)
{
    vtFNum.push_back(1);
    vtFNum.push_back(1);
    int nNum;
    for (int i = 2; i <= nK; i++)
    {
        nNum = vtFNum[i - 1] + vtFNum[i - 2];
        vtFNum.push_back(nNum);
    }
}

int GetResult(int nK)
{
    int nRst = 5 * (vtFNum[nK] + vtFNum[nK+1]);
    for (int i = 0; i <= nK; i++)
    {
        nRst += vtFNum[i];
    }
    return nRst;
}

int main()
{
    int nIn;
    cin >> nIn;
    if (nIn >= 0)
    {
        cout << 5;
        return 0;
    }
    switch (nIn)
    {
    case -1:
        cout << 11;
        return 0;
    case -2:
        cout << 16;
        return 0;
    }
    int nK = -nIn;
    F(nK);
    int nRst = GetResult(nK - 1);
    cout << nRst;
    return 0;
}
