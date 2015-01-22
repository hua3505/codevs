#include <iostream>

using namespace std;

int foo(int nIn)
{
    if (nIn == 1)
    {
        return 0;
    }
    if (nIn % 2 == 1)
    {
        nIn = 3 * nIn + 1;
    }
    else
    {
        nIn /= 2;
    }
    return foo(nIn) + 1;
}

int main()
{
    int num;
    cin >> num;
    int input[num];
    for (int i = 0; i < num; i++)
    {
        cin >> input[i];
    }
    for (int i = 0; i < num; i++)
    {
        cout << foo(input[i]) << endl;
    }
    return 0;
}
