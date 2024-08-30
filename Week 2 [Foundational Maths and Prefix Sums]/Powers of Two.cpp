#include <bits/stdc++.h>

using namespace std;

using lli = long long int;

#define int long long

lli m = 1e9 + 7;

lli fastExpo(lli a, lli b)
{

    lli ans = 1;

    while (b)
    {

        if (b % 2 == 1)
        {

            ans = (ans % m * a % m) % m;
        }

        a = (a % m * a % m) % m;

        b /= 2;
    }

    return ans;
}

void solve()
{

    int n;

    cin >> n;

    int arr[n];

    map<lli, lli> mp;

    for (int i = 0; i < n; i++)
    {

        int temp;

        cin >> temp;

        mp[temp]++;
    }

    lli ans1 = 0;

    lli ans2 = 0;

    for (auto m : mp)
    {

        lli element = m.first;

        for (int i = 0; i <= 31; i++)
        {

            lli temp = (1LL << i) - element;

            if (temp < 0)
            {

                continue;
            }

            auto it = mp.find(temp);

            if (it != mp.end())
            {

                if (element == temp)
                {

                    ans1 += ((m.second) * (m.second - 1)) / 2;
                }

                else
                {

                    ans2 += (m.second) * (it->second);
                }
            }
        }
    }

    lli finalans = ans1 + ans2 / 2;

    cout << finalans << endl;
}

signed main()
{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {

        solve();
    }

    return 0;
}