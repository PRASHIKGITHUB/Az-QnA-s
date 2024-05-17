#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
lli n, k, i;

map<int, int> mp;

vector<int> curr_sol;
void rec(int x)
{
    using lli = long long int;
    if (x == n)
    {
        i++;
        if (i == k)
        {
            for (auto i : curr_sol)
            {
                cout << i << " ";
            }
        }
        return;
    }
    // choices
    for (auto ch : mp)
    {
        if (i == k)
        {
            return;
        }
        if (ch.second != 0)
        {
            curr_sol.push_back(ch.first);
            mp[ch.first]--;
            rec(x + 1);
            mp[ch.first]++;
            curr_sol.pop_back();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        mp[i]++;
    }

    rec(0);
    return 0;
}