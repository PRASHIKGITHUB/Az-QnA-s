#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
void solve()
{
    int n, k, d;
    cin >> n >> k >> d;
    lli arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int head = -1;
    int tail = 0;
    lli sum = 0;
    lli odd = 0;
    lli ans = INT_MIN;
    while (tail < n)
    {

        while (head + 1 < n && (sum + arr[head + 1] <= d && (odd < k || arr[head + 1] % 2 == 0)))
        {
            head++;
            if (arr[head] % 2 != 0)
            {
                odd++;
            }
            sum += arr[head];
        }
        if ((head - tail + 1)!=0 && sum<=d  && odd<=k)
        {
            ans = max(ans, sum);
        }

        if (tail > head)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            if (arr[tail] % 2 != 0)
            {
                odd--;
            }
            sum -= arr[tail];
            tail++;
        }
    }
    if (ans == INT_MIN)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << ans << endl;
    }
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