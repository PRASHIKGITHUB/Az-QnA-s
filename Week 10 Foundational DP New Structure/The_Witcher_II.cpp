#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int n, m;
vector<vector<int>> dungeon, dp;

int rec(int i, int j) {//The function rec(i, j) in the recursive code returns the minimum initial health that the player needs to start with at the cell (i, j) in order to ensure that the player can reach the bottom-right corner of the dungeon (i.e., cell (n-1, m-1)) alive.
    // If the position is out of bounds, return a large value indicating an invalid path
    if (i >= n || j >= m) return 1e9;

    // Base case: When we reach the bottom-right corner of the dungeon
    if (i == n - 1 && j == m - 1) {
        return max(1, 1 - dungeon[i][j]);
    }

    // If the subproblem has already been solved, return the stored result
    if (dp[i][j] != -1) return dp[i][j];

    // Calculate the minimum health needed from the right and down cells
    int right = rec(i, j + 1);
    int down = rec(i + 1, j);

    // The current cell's minimum health is determined by the min of right and down, minus the dungeon value
    dp[i][j] = max(1, min(right, down) - dungeon[i][j]);

    return dp[i][j];
}

void solve() {
    cin >> n >> m;
    dungeon.assign(n, vector<int>(m));
    dp.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> dungeon[i][j];
        }
    }

    // Start the recursion from the top-left corner
    cout << rec(0, 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
