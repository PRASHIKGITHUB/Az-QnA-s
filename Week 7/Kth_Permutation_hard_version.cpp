#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

lli fact[14];

vector<lli> kthsol;
set<lli> digits;
// 6227020800=13!
// 479001600=12!
// 1000000000
// for 1 to 12  calculate 1-12! respectively
// for n>=13  calculate 13! permuatitons for the last 13 digits
void Kth(lli k, lli n)
{
    if (n == 0)
    {
        return;
    }
    lli m = 1;
    int toerase;
    for (auto i : digits)
    {
        if (k <= fact[n - 1] * m)
        {
            kthsol.push_back(i);
            toerase = i;
            break;
        }
        m++;
    }
    digits.erase(toerase);
    Kth(k - fact[n - 1] * (m - 1), n - 1);
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lli n, k;
    cin >> n >> k;

    fact[1] = 1;
    fact[0] = 1;
    for (int i = 2; i <= 13; i++)
    {
        fact[i] = fact[i - 1] * i;
    }

    if (n >= 13)
    {
        for (int i = n - 13 + 1; i <= n; i++)
        {
            digits.insert(i);
        }
        Kth(k, 13);
        for (int i = 1; i <= n - 13; i++)
        {
            cout << i << " ";
        }
        for (auto i : kthsol)
        {
            cout << i << " ";
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            digits.insert(i);
        }
        Kth(k, n);
        for (auto i : kthsol)
        {
            cout << i << " ";
        }
    }

    return 0;
}
