
#include <bits/stdc++.h>
using namespace std;


#define ll int64_t
int N, Q;
int dp[101][100100];
bool rec(int level,int sum_remain,vector<int>&arr){
    if(sum_remain==0){
        return 1;
    }
    if(sum_remain<0){
        return 0;
    }
    if(level==N){
        return 0;
    }
    
    if(dp[level][sum_remain]!=-1){
        return dp[level][sum_remain];
    }
    int ans=rec(level+1,sum_remain,arr);
    int ans2=rec(level+1,sum_remain-arr[level],arr);

    return dp[level][sum_remain]=(ans || ans2);
}
void generate(int level,int sum_remain,vector<int> &arr,vector<int>&temp){
    if(level==N){
        return;
    }
    //take
    int take=rec(level+1,sum_remain-arr[level],arr);
    if(take==1){
        temp.push_back(level);
        generate(level+1,sum_remain-arr[level],arr,temp);
    }
    else{
        generate(level+1,sum_remain,arr,temp);
    }
    
}
vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    vector<vector<int>>ans;
    for(auto q:queries){
        rec(0,q,arr);
    }
    for(auto q:queries){
        vector<int>temp;
        generate(0,q,arr,temp);
        if(temp.size()>0){
            ans.push_back(temp);
        }
        else{
            temp.push_back(-1);
            ans.push_back(temp);
        }
    }
    return ans;
}


void solve() {
    
    cin >> N >> Q;
    memset(dp,-1,sizeof(dp));
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // for(auto k:ans){
    //     for(auto i:k){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }
    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
