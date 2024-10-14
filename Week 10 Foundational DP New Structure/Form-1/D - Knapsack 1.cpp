#include <bits/stdc++.h>
using namespace std;
using lli=long long int;
int n, w;
lli wi[101];
lli vi[101];
lli dp[101][100100];
lli rec(int level, int wt_remain)
{
    if (level == n)
    {
        return 0;
    }
    if (dp[level][wt_remain] != -1)
    {
        return dp[level][wt_remain];
    }
    lli ans = rec(level + 1, wt_remain); // not take
    if (wi[level] <= wt_remain)
    { // take
        ans = max(ans, vi[level] + rec(level + 1, wt_remain - wi[level]));
    }
    return dp[level][wt_remain] = ans;
}
int main()
{ 
    cin >> n >> w;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> wi[i] >> vi[i];
    }
    cout << rec(0, w);
    return 0;
}