#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int cntzero = 0;
    int head = -1;
    int tail = 0;
    int ans = 0;
    while (tail < n)
    {
        while (head + 1 < n && (arr[head+1]==1 || cntzero<k))
        {
            head++;
            if (arr[head] == 0)
            {
                cntzero++;
            }
        }

        ans = max(ans, head - tail + 1);
        // cout<<tail<<" "<<head<<endl;
        if (head >= tail)
        {
            if (arr[tail] == 0)
            {
                cntzero--;
            }
            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
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
    return 0;
}