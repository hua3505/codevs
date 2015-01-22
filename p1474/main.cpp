#include <iostream>
#include <sstream>

using namespace std;

string TransformToK(int n, int m);

int main()
{
    int n;
    int m;
    cin >> n >> m;
    cout << TransformToK(n, m);
    return 0;
}

string TransformToK(int n, int m)
{
    if (m <= 0) return "";
    if (m == 1)
    {
        stringstream sstr;
        sstr << m;
        string strBuf = "";
        sstr >> strBuf;
        return strBuf;
    }
    if (n == 0) return "0";

    string strBuf = "";
    while (n > 0)
    {
        int res = n % m;
        n = n / m;
        char c = (res <= 9) ? '0' + res : 'A' + res - 10;
        strBuf.insert(strBuf.begin(), c);
    }
    return strBuf;
}
