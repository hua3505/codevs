#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int nNodeNum;
    cin >> nNodeNum;
    int aNodes[nNodeNum][2];
    for (int i = 0; i < nNodeNum; i++)
    {
        cin >> aNodes[i][0] >> aNodes[i][1];
    }

    queue<int> qNodes;
    vector<queue<int>::size_type> vtLevel;
    qNodes.push(0);
    while (!qNodes.empty())
    {
        queue<int>::size_type nQsize = qNodes.size();
        vtLevel.push_back(nQsize);
        for (queue<int>::size_type i = 0; i < nQsize; i++)
        {
            int nNode = qNodes.front();
            if (aNodes[nNode][0] != 0)
            {
                qNodes.push(aNodes[nNode][0] - 1);
            }
            if (aNodes[nNode][1] != 0)
            {
                qNodes.push(aNodes[nNode][1] - 1);
            }
            qNodes.pop();
        }
    }

    cout << *max_element(vtLevel.begin(), vtLevel.end()) << ' ' << vtLevel.size();

    return 0;
}
