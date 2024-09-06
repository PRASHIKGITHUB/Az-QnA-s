#include <bits/stdc++.h>
using lli = long long;
using namespace std;
// lli m=1e9+7;
lli n, k;

bool check(lli x, lli *arr)
{
    lli deployed=0;
    lli time_remain=0;
    for(lli i=0;i<n;i++){
        
        if(time_remain>=arr[i]){
            time_remain-=arr[i];
        }
        else{
            deployed++;
            if(deployed>k){
                return 0;
            }
            time_remain=x;
            if(time_remain>=arr[i]){
                time_remain-=arr[i];
            }
            else{
                return 0;
            }
        }

    }
    return 1;
}
// 5 4
// 1 7 2 3 5
// 7
void solve()//minimise the maximum time taken 
//for ans we are searching for the maximum time
//if painters can paint in x time then painters can also paint in x+1 time but we need find the minimum of them 
{
    cin >> n >> k;
    lli arr[n];
    lli high = 0;//high will be sum of Ai if we have one painter
    lli low = 0;//low will be maximum of Ai if we have n number of painters
    for (lli i = 0; i < n; i++)
    {
        cin >> arr[i];
        high+=arr[i];
    }
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