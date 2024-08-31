#include <bits/stdc++.h>
using namespace std;

int n;
using lli = long long int;
lli arr[3001];
lli dp[3001][3001][2];
lli sum=0;
lli rec(int l, int r, int chance) {
    // Base case
    if (l > r) {
        return 0;
    }
    // Cache check
    if (dp[l][r][chance] != -1) {
        return dp[l][r][chance];
    }
    // Transition
    if (chance == 0) { // Taro's turn
        lli ans = max(rec(l + 1, r, 1) + arr[l], rec(l, r - 1, 1) + arr[r]);
        return dp[l][r][chance] = ans;
    } else { // Jiro's turn
        lli ans = min(rec(l + 1, r, 0), rec(l, r - 1, 0));
        return dp[l][r][chance] = ans;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum+=arr[i];
    }

    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));

    cout <<2* rec(0, n - 1, 0)-sum << endl;

    return 0;
}