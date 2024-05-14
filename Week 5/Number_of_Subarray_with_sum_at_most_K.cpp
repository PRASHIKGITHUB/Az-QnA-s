#include <bits/stdc++.h>
using namespace std;
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
    lli sum = 0;
    lli ans = 0;
    
    while (tail < n)
    {
        while (head + 1 < n && (sum+arr[head+1]<=k))
        {
            head++;
            sum+=arr[head];
           
        }

        ans += head - tail + 1;

        if (tail > head)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            sum-=arr[tail];
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
    
    while(t--){
        lli ans;
        ans=solve();
        cout<<ans<<endl;
    }
    return 0;
}