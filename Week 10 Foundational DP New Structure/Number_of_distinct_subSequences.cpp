#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int prefix[n + 1];//unique subseq ending at i-1 of string
    int last[26];
    int dp[n + 1];
    memset(last, -1, sizeof(last));
    dp[0] = 1;//unique subseq ending at i-1 of string
    prefix[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = prefix[i - 1];//unique subseq ending at i-1 of string
        if (last[s[i - 1] - 'a'] != -1)
        {
            int idx = last[s[i - 1] - 'a'];
            dp[i] -= prefix[idx];//count of currently generated new sub strings that are unique
        }
        last[s[i - 1] - 'a'] = i - 1;
        prefix[i] = prefix[i - 1] + dp[i];
    }
    cout << prefix[n] - 1 << endl;//removing that empty sub sequence
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}