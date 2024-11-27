#include <bits/stdc++.h>
using lli = long long;
using namespace std;
// lli m=1e9+7;
lli n, m, k;

bool check(lli *a, lli *b, lli x)
{
    lli sum = 0;
    if (m > n)
    {
        for (lli i = 0; i < n; i++)
        {
            lli num = a[i];
            auto k = upper_bound(b, b + m, x - num);
            sum += (k-b);
        }
    }
    else
    {
        for (lli i = 0; i < m; i++)
        {
            lli num = b[i];
            auto k = upper_bound(a, a + n, x - num);
            sum += (k-a);
        }
    }
    return sum >= k;
}
void solve()
{

    cin >> n >> m >> k;
    lli a[n];
    lli b[m];
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lli i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+m);

    lli l = 0;
    lli r = a[n-1]+b[m-1];
    lli ans = -1;
    while (l <= r)
    {
        lli mid = l + (r - l) / 2;
        if (check(a, b, mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
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