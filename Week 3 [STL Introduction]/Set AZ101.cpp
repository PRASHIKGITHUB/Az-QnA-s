#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve(int k)
{
    set<int> q;
    while (k--)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            int x;
            cin >> x;
            q.insert(x);
        }
        else if (s == "erase")
        {
            int x;
            cin >> x;
            auto it = q.find(x);
            if (it != q.end())
            {
                q.erase(it);
            }
        }
        else if (s == "find")
        {
            int x;
            cin >> x;
            if (q.find(x) != q.end())
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else if (s == "print")
        {
            for (auto i : q)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else if (s == "empty")
        {
            q.clear();
        }
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
        int q;
        cin >> q;
        solve(q);
    }
    return 0;
}