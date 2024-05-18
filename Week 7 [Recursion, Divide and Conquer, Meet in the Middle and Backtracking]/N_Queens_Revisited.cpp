#include <bits/stdc++.h>
using namespace std;
int n;
int squeen[14];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
bool check(int currR, int currC)
{
    // check for queen property
    for (int prevR = 0; prevR < currR; prevR++)
    {
        int prevC = squeen[prevR];
        if (currC == prevC || abs(prevC - currC) == abs(prevR - currR))
        {
            return 0;
        }
    }

    // check for knight property
    for (int i = 0; i < 8; i++)
    {
        int x = currR + dx[i];
        int y = currC + dy[i];
        if ((x >= 0 && x < n) && (y >= 0 && y < n))
        {
            if (squeen[x] == y)
            {
                return 0;
            }
        }
    }
    return true;
}
int rec(int level)
{
    if (level == n)
    {
        return 1;
    }
    int ans = 0;
    for (int ch = 0; ch < n; ch++)
    {
        if (check(level, ch))
        {
            squeen[level] = ch;
            ans += rec(level + 1);
            squeen[level] = -1;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(squeen, -1, sizeof(squeen));
    cin >> n;
    int ans;
    ans = rec(0);
    cout << ans << endl;
    return 0;
}