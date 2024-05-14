#include <bits/stdc++.h>
using namespace std;
int mp[1001000];
using lli=long long int;
lli solve(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int head = -1;
    int tail = 0;
    int distinct = 0;
    lli ans = 0;
    // map<int, int> mp; //if we use map TC will be nlog n
    
    while (tail < n)
    {
        while (head + 1 < n && (distinct < k || mp[arr[head + 1]] != 0))
        {
            head++;
            if (mp[arr[head]] == 0)
            {
                distinct++;
            }
            mp[arr[head]]++;
        }

        ans += head - tail + 1;

        if (tail > head)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            if (mp[arr[tail]] == 1)
            {
                distinct--;
            }
            mp[arr[tail]]--;
            tail++;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for (int i = 0; i <= 1000000; i++)
    {
        mp[i] = 0;
    }
    
    while(t--){
        lli ans;
        ans=solve();
        cout<<ans<<endl;
    }
    return 0;
}