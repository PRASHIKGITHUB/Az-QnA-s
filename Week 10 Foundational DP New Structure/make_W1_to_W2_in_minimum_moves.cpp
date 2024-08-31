#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

string s1, s2;
int n, m;
int dp[1001][1001];

int rec(int i, int j) {//longest common substring in s1[i....n-1] and s2[j....m-1]
    if (i == n || j == m) return 0; // Base case: if any index reaches the end of a string, return 0.
    auto &ans = dp[i][j]; 
    if (ans != -1) return ans; // If the subproblem is already solved, return the stored result.
    
    ans = 0; 
    if (s1[i] == s2[j]) ans = max(ans, 1 + rec(i + 1, j + 1)); 
    // If characters match, extend the LCSuff by 1.

    rec(i + 1, j), rec(i, j + 1); 
    // Recursively calculate for other possibilities (moving forward in either of the strings).

    return dp[i][j]= ans; 
}

void solve() {
    cin >> s1 >> s2;
    n = s1.size(), m = s2.size();
    memset(dp, -1, sizeof(dp)); // Initialize the dp array with -1.

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) ans = max(ans, rec(i, j));
        // Calculate the maximum LCSuff for all possible starting points.
    }
    cout << ans << endl; // Output the longest common substring.
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
