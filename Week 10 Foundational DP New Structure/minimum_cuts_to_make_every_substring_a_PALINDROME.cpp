#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int dp1[1001][1001];
int dp2[1001];
int rec1(int l, int r) // check PALINDROME
{
    if (l >= r)
    {
        return 1;
    }

    if (dp1[l][r] != -1)
    {
        return dp1[l][r];
    }
    return dp1[l][r] = (rec1(l + 1, r - 1) && (s[l-1] == s[r-1]));//for checking palindrome in o based index
}

int rec2(int i) //minimum cuts to make every substring a PALINDROME [1....i]
{
    if (i == 0)//if string is empty
    {
        return -1;
    }

    if (dp2[i] != -1)
    {
        return dp2[i];
    }
    int ans = 1e9;
    for (int j = 0; j < i; j++)
    {
        if (rec1(j + 1, i))
        {
            ans = min(ans, 1 + rec2(j));
        }
    }

    return dp2[i] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    cin >> s;
    n = s.size();
    int ans = rec2(n);
    cout << ans << endl;
    return 0;
}