#include <bits/stdc++.h>
using namespace std;

int maxCoinsRec(int left, int right, vector<int>& balloons, vector<vector<int>>& dp) {
    // Base case: if there are no balloons between left and right
    if (left + 1 == right) return 0;

    // If already computed, return the result from memoization table
    if (dp[left][right] != -1) return dp[left][right];

    int maxCoins = 0;

    // Try bursting each balloon between left and right
    for (int k = left + 1; k < right; ++k) {
        // Coins collected by bursting the balloon `k`
        int coins = balloons[left] * balloons[k] * balloons[right];

        // Solve for subproblems (left to k, k to right)
        coins += maxCoinsRec(left, k, balloons, dp) + maxCoinsRec(k, right, balloons, dp);

        // Maximize the result
        maxCoins = max(maxCoins, coins);
    }

    // Store the result in the memoization table
    dp[left][right] = maxCoins;
    return maxCoins;
}

int maxCoins(vector<int>& nums) {
    int n = nums.size();

    // Add virtual balloons with value 1 at both ends
    vector<int> balloons(n + 2, 1);
    for (int i = 0; i < n; ++i) {
        balloons[i + 1] = nums[i];
    }

    // Memoization table, initialized with -1
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

    // Call the recursive function with full range (0 to n+1)
    return maxCoinsRec(0, n + 1, balloons, dp);
}

int main() {
    vector<int> nums = {3, 1, 5, 8};  // Example input
    cout << maxCoins(nums) << endl;    // Output the result
    return 0;
}
