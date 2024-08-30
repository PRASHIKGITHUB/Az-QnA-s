#include <bits/stdc++.h>
using lli = long long;
using namespace std;
// lli m=1e9+7;
lli n, k;

bool check(lli x, lli *arr)
{
    lli deployed=0;

   for(int i=1;i<n;i++){
    lli d=arr[i]-arr[i-1];
        deployed+=((d+x-1)/x)-1 ;
   }
   return (deployed)<=k;
}
// 5 4
// 1 7 2 3 5
// 7
void solve()
{
    cin >> n >> k;
    lli arr[n];
    
    lli low = 1;
    for (lli i = 0; i < n; i++)
    {
        cin >> arr[i];
        
    }
    lli high = arr[n-1]-arr[0];
    lli ans = -1;
    
    while (low <= high)
    {
        lli mid = (low + high) / 2;
        if (check(mid, arr))
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}