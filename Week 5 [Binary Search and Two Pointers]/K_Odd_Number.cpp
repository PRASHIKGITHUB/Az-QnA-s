#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
multiset<lli> ms;
void solve()
{
    int n, k, d;
    cin >> n >> k >> d;
    lli arr[n];
    lli prefix[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        prefix[i] = arr[i];
        if (i)
        {
            prefix[i] += prefix[i - 1];
        }
    }

    int head = -1;
    int tail = 0;
    int oddcnt = 0;
    lli ans = INT_MIN;

    while (tail < n)
    {
        while (head + 1 < n && (oddcnt < k || arr[head + 1] % 2 == 0))
        {
            head++;
            ms.insert(prefix[head]);
            if (arr[head] % 2 != 0)
            {
                oddcnt++;
            }
        }

        lli lminusone = (tail == 0) ? 0 : (prefix[tail - 1]);
        auto it = ms.upper_bound(lminusone + d);

        if (it != ms.begin()) //if the window is empty then ms.begin()=ms.end()
        {
            it--;
            ans = max(ans, *it - lminusone);
        }

        if (head < tail)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            if (arr[tail] % 2 != 0)
            {
                oddcnt--;
            }
            ms.erase(ms.find(prefix[tail]));
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