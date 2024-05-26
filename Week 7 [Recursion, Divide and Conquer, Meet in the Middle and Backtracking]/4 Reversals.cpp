#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
string curr_sol;
int n;
void rec(int level, set<string> &sat, string s)
{
    if (level == 2)
    {
        sat.insert(s);
        return;
    }
    curr_sol = s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j <n; j++)
        {
            string temp;
            temp = s;
            reverse(s.begin() + i, s.begin() + j + 1);
            rec(level + 1, sat, s);
			s=temp;
        }
    }
}
void solve()
{
    string s, t;
    cin >> s >> t;
    n = s.length();
    set<string> s1;
    set<string> s2;
    rec(0, s1, s);
    rec(0, s2, t);
    for (auto i : s1)
    {
        auto it = s2.find(i);
        if (it != s2.end())
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> m;
    while (m--)
    {
        solve();
    }
    return 0;
}  