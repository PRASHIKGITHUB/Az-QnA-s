#include <bits/stdc++.h>
using namespace std;
string s, t;
int n, m;
string lcs, current_string;

int dp[3001][3001];
int rec(int i, int j)
{
    if (i == n || j == m)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = -1e9;
    ans = max({rec(i + 1, j), rec(i, j + 1)});

    if (s[i] == t[j])
    {
        ans = max(1 + rec(i + 1, j + 1), ans);
    }

    return dp[i][j] = ans;
}

void print(int i, int j)
{
    if (i == n || j == m)
    {
        return;
    }

    if (s[i] == t[j])
    {
        lcs += s[i];
        print(i + 1, j + 1);
        cout<<i<<" "<<j<<endl;
    }
    else
    {
        if (dp[i + 1][j] > dp[i][j + 1])
        {
            print(i + 1, j);
            cout<<i+1<<" "<<j<<endl;
        }
        else
        {
            print(i, j + 1);
        }
    }
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> s >> t;
    n = s.length();
    m = t.length();
    lcs.clear();
    current_string.clear();
    int ans = rec(0, 0);
    print(0, 0);
    cout << lcs << endl;
    return 0;
}