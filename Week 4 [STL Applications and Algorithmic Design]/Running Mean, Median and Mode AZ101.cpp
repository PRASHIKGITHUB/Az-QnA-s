#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
using pp = pair<lli, lli>;
lli m = 1e9 + 7;
lli fastExpo(lli a, lli b)
{
    lli ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % m;
        }
        a = (a % m * a % m) % m;
        b /= 2;
    }
    return ans;
}
lli divide(lli a, lli b)
{
    return (a % m * fastExpo(b, m - 2) % m) % m;
}
struct data
{
    lli sum = 0;
    lli square_sum = 0;
    int cnt = 0;
    // mean
    multiset<lli> small;
    multiset<lli> large;
    // mode
    map<int, int> freq;          // elemet,frequency
    multiset<pair<int, int>> ms; // frequency,element
    void balance()
    {
        if (large.size() > small.size())
        {
            int x = *large.begin();
            large.erase(large.find(x));
            small.insert(x);
        }
        if (small.size()>large.size()+1)
        {
            int x = *small.rbegin();
            small.erase(small.find(x));
            large.insert(x);
        }
    }
    void add(int x)
    {
        cnt++;
        sum += x;
        square_sum += x * x;

        // median
        if (small.empty())
        {
            small.insert(x);
        }
        else if (x <= (*small.rbegin()))
        {
            small.insert(x);
        }
        else
        {
            large.insert(x);
        }
        balance();
        // mode

        if (ms.find(make_pair(freq[x], x)) != ms.end())
        {
            ms.erase(ms.find(make_pair(freq[x], x)));
        }
        freq[x]++;
        ms.insert(make_pair(freq[x], x));
    }
    void remove(int x)
    {
        cnt--;
        sum -= x;
        square_sum -= x * x;

        // median
        if (small.find(x) != small.end())
        {
            small.erase(small.find(x));
        }
        else
        {
            large.erase(large.find(x));
        }

        // mode
        if (ms.find(make_pair(freq[x], x)) != ms.end())
        {
            ms.erase(ms.find(make_pair(freq[x], x)));
        }
        freq[x]--;
        if (freq[x] != 0)
        {
            ms.insert(make_pair(freq[x], x));
        }
        balance();
    }
    lli mean()
    {
        if (cnt == 0)
        {
            return -1;
        }
        return divide(sum, cnt);
    }
    lli median()
    {
        if (cnt == 0)
        {
            return -1;
        }
        if (cnt % 2)
        {
            return *small.rbegin();
        }
        else
        {
            // cout << *small.rbegin() << " " << *large.begin() << endl;
            int temp = *small.rbegin() + *large.begin();
            return divide(temp, 2);
        }
    }
    lli mode()
    {
        if (cnt == 0)
        {
            return -1;
        }
        int x = ms.rbegin()->first;
        
        auto it = ms.lower_bound(make_pair(x, 1)); // finding smallest element with same frequency
        return it->second;
    }
    void print()
    {
        for (auto i : small)
        {
            cout << "small " << i << endl;
        }
        for (auto i : large)
        {
            cout << "large " << i << endl;
        }
        for(auto i:ms){
            cout<<"("<<i.first<<" "<<i.second<<")"<<endl;
        }
    }
};
void solve()
{
    int q;
    struct data temp;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "insert")
        {
            int x;
            cin >> x;
            temp.add(x);
            // cout << "inserting " << x << endl;
            // temp.print();
            // cout << endl;
        }
        else if (s == "getMean")
        {
            cout << temp.mean() << endl;
        }
        else if (s == "remove")
        {
            int x;
            cin >> x;
            temp.remove(x);
            // cout << "removing " << x << endl;
            // temp.print();
            // cout << endl;
        }
        else if (s == "getMedian")
        {
            cout << temp.median() << endl;
        }
        else if (s == "getMode")
        {
            cout << temp.mode() << endl;
        }
    }
    // temp.print();
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