#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
int n, q;
vector<int> parent;
vector<int> component_size;
int rep(int x)//TC O(lln)
{
    if (parent[x] == x)
    {
        return x;
    }
    else
    {
        return parent[x] = rep(parent[x]);
    }
}
void add(int a, int b)
{
    if(rep(a)==rep(b)){
        return;
    }
    a=rep(a);
    b=rep(b);
    if (component_size[a] >= component_size[b])
    {
        parent[b] = a;
        component_size[a] += component_size[b];
    }
    else
    {
        parent[a] = b;
        component_size[b] += component_size[a];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    parent.resize(n);
    component_size.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        component_size[i] = 1;
    }
    while (q--)
    {
        int command, a, b;
        cin >> command >> a >> b;
        if (command == 0)
        {
            add(a, b);
        }
        else
        {
            if (rep(a) == rep(b))
            {
                cout << "1" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }
    return 0;
}