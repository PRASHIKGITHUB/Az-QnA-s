#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve()
{
    string k;
    cin >> k;
    int ans = 0;
    stack<char> s;
    // ))((
    for (int i = 0; i < k.length(); i++)
    {
        if (k[i] == '(')
        {
            s.push('(');
        }
        else
        {
            if (!s.empty() && s.top() == '(')
            {
                s.pop();
            }
            else
            {
                ans++;
                // s.pop();
            }
        }
    }
    while (!s.empty())
    {
        s.pop();
        ans++;
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