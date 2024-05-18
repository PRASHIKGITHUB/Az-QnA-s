#include <bits/stdc++.h>
using namespace std;
int n;
int queen[12];
bool check(int row, int col)
{
    for (int cr = 0; cr < row; cr++)
    {
        int cc = queen[cr];
        if (col == cc || (abs(col - cc) == abs(cr - row)))
        {
            return 0;
        }
    }
    return 1;
}
int solve(int row)
{
    if (row == n)
    {
        return 1;
    }
    int ans = 0;
    for (int col = 0; col < n; col++)
    {

        if (check(row, col))
        {
            // place a queen
            queen[row] = col;
            ans += solve(row + 1);
            // unplace the queen
            queen[row] = -1;
        }
    }
    return ans;
}
int main()
{
    memset(queen,-1,sizeof(queen));
    cin >> n;
    int ans = solve(0);
    cout << ans << endl;
    return 0;
}