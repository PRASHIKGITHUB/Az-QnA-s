#include <bits/stdc++.h>
using namespace std;
int mp[1001000];
using lli = long long int;
lli solve()
{
    
    int n, d;
    cin >> n >> d;
    int distinct = 0;
    int arr[n + 1];
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= d; i++)
    {
        if (mp[arr[i]] == 0)
        {
            distinct++;
        }
        mp[arr[i]]++;
    }
    ans = min(ans, distinct);

    for (int i = d + 1; i <= n; i++)
    {
        if (mp[arr[i]] == 0)
        {
            distinct++;
        }
        mp[arr[i]]++;

        // remove last element of the window
        if (mp[arr[i - d]] == 1)
        {
            distinct--;
        }
        mp[arr[i - d]]--;
        // cout<<i<<" distinct:"<<distinct<<endl;

        ans = min(ans, distinct);
    }
    // cout<<endl;

    for(int i=n-d+1;i<=n;i++){
        mp[arr[i]]--;
    }
    


    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i <= 1000000; i++)
    {
        mp[i] = 0;
    }
    while (t--)
    {
        lli ans;
        ans = solve();
        cout << ans << endl;
    }
    return 0;
}