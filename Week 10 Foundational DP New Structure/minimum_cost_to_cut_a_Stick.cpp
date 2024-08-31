#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>

class Solution
{
public:
    int rec(int l, int r, vector<int> &cuts, vector<vector<int>> &dp)
    {
        // If there are no cuts between l and r, return 0
        if (l + 1 == r)
            return 0;

        // If the value is already calculated, return it
        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = INT_MAX;
        for (int i = l + 1; i < r; i++)//cuts on cuts array's index
        {
            int cost = cuts[r] - cuts[l] + rec(l, i, cuts, dp) + rec(i, r, cuts, dp);
            ans = min(ans, cost);
        }

        // Store the result in dp array
        return dp[l][r] = ans;
    }

    int minCost(int n, vector<int> &cuts)
    {
        // Add 0 and n to the cuts array to cover the full length
        cuts.push_back(0);
        cuts.push_back(n);

        // Sort the cuts array
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();

        // Initialize the dp array with -1
        vector<vector<int>> dp(m, vector<int>(m, -1));

        // Start the recursion from the full stick (0 to n)
        return rec(0, m - 1, cuts, dp);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}
