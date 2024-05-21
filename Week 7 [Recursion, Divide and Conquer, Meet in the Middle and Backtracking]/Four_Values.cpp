#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
void solve(ll *arr, ll x, ll n)
{
    map<ll, ll> mp;
    for (ll b = n - 2; b >= 0; b--)
    {
        for (ll a = 0; a <= b - 1; a++)
        {
            if (mp[x - arr[b] - arr[a]])
            {
                cout << "YES";
                return;
            }
        }
        ll c = b;
        for (ll d = c + 1; d < n; d++)
        {
            mp[arr[d] + arr[c]] = 1;
        }
    }
    cout << "NO";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, x;
    cin >> n >> x;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(arr, x, n);
    return 0;
}