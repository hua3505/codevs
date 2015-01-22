#include <iostream>
#include <math.h>

using namespace std;

int TransformToTen(string &strNum, int m);

int main()
{
    string n;
    int m;
    cin >> n >> m;
    cout << TransformToTen(n, m) << endl;
    return 0;
}

int TransformToTen(string &strNum, int m)
{
    int nRs = 0;
    unsigned int uSize = static_cast<unsigned int>(strNum.size());
    for (unsigned int i = 0; i < uSize; i++)
    {
        char c = strNum[uSize - i - 1];
        int a = (c > '9') ? c - 'A' + 10: c - '0';
        int b = static_cast<int>(pow(m, i));
        nRs = nRs + a * b;
    }
    return nRs;
}
