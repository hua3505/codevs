#include <iostream>

using namespace std;

int (*g_aNodes)[2];

void PreorderTraversal(int nNode)
{
    int nLeft = g_aNodes[nNode][0];
    int nRight = g_aNodes[nNode][1];
    cout << nNode + 1 << ' ';
    if (nLeft != 0)
    {
        PreorderTraversal(nLeft - 1);
    }
    if (nRight != 0)
    {
        PreorderTraversal(nRight - 1);
    }
}

void InorderTraversal(int nNode)
{
    int nLeft = g_aNodes[nNode][0];
    int nRight = g_aNodes[nNode][1];

    if (nLeft != 0)
    {
        InorderTraversal(nLeft - 1);
    }
    cout << nNode + 1 << ' ';
    if (nRight != 0)
    {
        InorderTraversal(nRight - 1);
    }
}

void PostorderTraversal(int nNode)
{
    int nLeft = g_aNodes[nNode][0];
    int nRight = g_aNodes[nNode][1];

    if (nLeft != 0)
    {
        PostorderTraversal(nLeft - 1);
    }
    if (nRight != 0)
    {
        PostorderTraversal(nRight - 1);
    }
    cout << nNode + 1 << ' ';
}

int main()
{
    int nNodeNum;
    cin >> nNodeNum;
    g_aNodes = new int[nNodeNum][2];
    for (int i = 0; i < nNodeNum; i++)
    {
        cin >> g_aNodes[i][0] >> g_aNodes[i][1];
    }
    PreorderTraversal(0);
    cout << '\b' << endl;
    InorderTraversal(0);
    cout << '\b' << endl;
    PostorderTraversal(0);
    cout << '\b' << endl;
    return 0;
}
