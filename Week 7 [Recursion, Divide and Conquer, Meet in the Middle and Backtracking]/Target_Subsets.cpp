#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
vector<int> SumofSubArrays(vector<int> &v)
{
    int n = v.size();
    vector<int> ans;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if ((mask >> j) & 1)
            {
                sum += v[j];
            }
        }
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
ll solve()
{
    int n, x;
    cin >> n >> x;
    ll cnt = 0;
    vector<int> ele;
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        ele.push_back(temp);
        if (i & 1)
        {
            v1.push_back(ele[i]);
        }
        else
        {
            v2.push_back(ele[i]);
        }
    }
    vector<int> sub1, sub2;
    sub1 = SumofSubArrays(v1);
    sub2 = SumofSubArrays(v2);

    for (auto i : sub1)
    {
        cnt += upper_bound(sub2.begin(), sub2.end(), x - i) - sub2.begin();
    }
    return cnt;
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
        ll ans;
        ans = solve();
        cout << ans << endl;
    }
    return 0;
}