/*
Problem Statement
Taro and Jiro will play the following game against each other.

Initially, they are given a sequence
a=(a
1
​
 ,a
2
​
 ,…,a
N
​
 ). Until
a becomes empty, the two players perform the following operation alternately, starting from Taro:

Remove the element at the beginning or the end of
a. The player earns
x points, where
x is the removed element.
Let
X and
Y be Taro's and Jiro's total score at the end of the game, respectively. Taro tries to maximize
X−Y, while Jiro tries to minimize
X−Y.

Assuming that the two players play optimally, find the resulting value of
X−Y.

Constraints
All values in input are integers.
1≤N≤3000
1≤a
i
​
 ≤10
9
*/

#include <bits/stdc++.h>
using namespace std;

int n;
using lli = long long int;
lli arr[3001];
lli dp[3001][3001][2];
lli sum = 0;
lli rec(int l, int r, int chance)//optimal value of X-Y respective of first chance if string is from l to r
{
    // Base case
    if (l > r)
    {
        return 0;
    }
    // Cache check
    if (dp[l][r][chance] != -1)
    {
        return dp[l][r][chance];
    }
    // Transition
    if (chance == 0)
    { // Taro's turn (he will try to maximise the value of x)
        lli ans = max(rec(l + 1, r, 1) + arr[l], rec(l, r - 1, 1) + arr[r]);
        return dp[l][r][chance] = ans;
    }
    else
    { // Jiro's turn (he will try to minimise the value of x)
        lli ans = min(rec(l + 1, r, 0), rec(l, r - 1, 0));
        return dp[l][r][chance] = ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));

    cout << 2 * rec(0, n - 1, 0) - sum << endl;

    return 0;
}

/*

*/
