#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
char chess[8][8];
int queen[8];
lli m = 1e9 + 7;
bool check(int pr, int pc)
{
    if( chess[pr][pc] == '*'){
        return 0;
    }
    for (int row = 0; row < pr; row++)
    {
        int col = queen[row];
        if (pc == col || (abs(row - pr) == abs(pc - col)))
        {
            return 0;
        }
    }
    return 1;
}
int rec(int level)
{
    if (level == 8)
    {
        return 1;
    }
    int ans = 0;
    // choices

    for (int ch = 0; ch < 8; ch++)
    {
        if (check(level, ch))
        {
            // place queen
            queen[level] = ch;
            ans += rec(level + 1);
            queen[level] = -1;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(queen, -1, sizeof(queen));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> chess[i][j];
        }
    }
    int temp;
    temp = rec(0);
    cout << temp << endl;
    return 0;
}