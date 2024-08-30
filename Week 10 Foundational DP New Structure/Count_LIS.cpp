#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

ll MOD = 1000000007;
vector<ll> nums, dp, cnt;

ll rec_dp(int i) {
    // Base case: If we've already calculated dp[i], return it
    if (dp[i] != -1) return dp[i];

    ll ans = 1;
    for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
            ans = max(ans, rec_dp(j) + 1);
        }
    }
    
    return dp[i] = ans;
}

ll rec_cnt(int i, ll lis_len) {//number of subSeq of lis_len ending at i
    // Base case: If we've already calculated cnt[i], return it
    if (cnt[i] != -1) return cnt[i];
    
    ll count = 0;
    for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i] && rec_dp(j) + 1 == lis_len) {
            count = (count + rec_cnt(j, rec_dp(j))) % MOD;
        }
    }
    
    return cnt[i] = (count == 0 ? 1 : count); // If no subsequence can be extended, cnt[i] = 1
}

void solve() {
    ll n;
    cin >> n;
    nums.resize(n);
    dp.assign(n, -1);
    cnt.assign(n, -1);//stores number of longest increasing subseq ending at i
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    ll lis = 1;
    for (int i = 0; i < n; i++) {
        lis = max(lis, rec_dp(i));
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (lis == rec_dp(i)) {
            ans = (ans + rec_cnt(i, lis)) % MOD;
        }
    }
    
    cout << ans << endl;
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
