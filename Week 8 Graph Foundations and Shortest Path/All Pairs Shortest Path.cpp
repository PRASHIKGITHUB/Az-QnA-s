#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int g[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }
    int queries[n];
    for (int i = 0; i < n; i++)
    {
        cin >> queries[i];
    }
    vector<lli> ans;
    for (int k = n - 1; k >= 0; k--)//this outer loop will only consider those nodes that are passed by for calculating shortest distance from every node that are passed by till now (it is as if there are no nodes except for those that are passed by )
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                g[i][j] = min(g[i][j], g[i][queries[k]] + g[queries[k]][j]);
            }
        }
        lli temp = 0;
        for (int i = k; i < n; i++)
        {
            for (int j = k; j < n; j++)
            {
                temp += g[queries[i]][queries[j]];
            }
        }
        ans.push_back(temp);
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}