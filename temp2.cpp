#include <bits/stdc++.h>

using namespace std;

int n, open, close;
string s;
void helper(int i, int o, int c)
{
	if (i == n)
	{
		cout << s << endl;
		return;
	}
	if (o)
	{
		s += '(';
		helper(i + 1, o - 1, c);
		s.pop_back();
	}
	if (o * 2 < n and c and o < c)
	{
		s += ')';
		helper(i + 1, o, c - 1);
		s.pop_back();
	}
}
void solve()
{
	cin >> n;
	open = n / 2, close = n / 2;
	helper(0, open, close);
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif // ONLINE_JUDGE
	int t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}