/*
作者:959547664@qq.com
题目:p3116 高精度练习之加法
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string strA = "";
    string strB = "";
    string strRst = "";

    cin  >> strA >> strB;

    reverse(strA.begin(), strA.end());
    reverse(strB.begin(), strB.end());

    unsigned int nIndex = 0;
    int nSum = 0;
    int nUp = 0;
    while (true)
    {
        char cA = '0';
        char cB = '0';
        if (nIndex < strA.size())
        {
            cA = strA[nIndex];
        }
        if (nIndex < strB.size())
        {
            cB = strB[nIndex];
        }

        if (nIndex >= strA.size() && nIndex >= strB.size())
        {
            break;
        }

        nSum = cA - '0' + cB - '0' + nUp;
        nUp = 0;
        if (nSum >= 10)
        {
            nUp = 1;
            nSum -= 10;
        }
        char cRst = nSum + '0';
        strRst.push_back(cRst);
        nIndex++;
    }
    if (nUp == 1)
    {
        strRst.push_back('1');
    }

    reverse(strRst.begin(), strRst.end());
    cout << strRst;

    return 0;
}
