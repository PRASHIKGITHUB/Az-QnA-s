#include <bits/stdc++.h>
using namespace std;
int n;
int depth = 0;
char choices[2] = {'(', ')'};
int maxd;
vector<char> curr_sol;
int open;
int k;
int clo;
void rec(int level)
{
	if (level == n)
	{
		cout << maxd << endl;
		if (depth == 0 && maxd==k)
		{

			for (auto i : curr_sol)
			{
				cout << i;
			}
			cout << endl;
			return;
		}
		// for (auto i : curr_sol)
		// {
		// 	cout << i;
		// }
		// cout << endl;
		// return;
	}
	// choices
	for (int i = 0; i < 2; i++)
	{
		char temp = choices[i];
		if (i == 0 && open)
		{
			open--;
			curr_sol.push_back(temp);
			depth++;
			maxd = max(maxd, depth);
			rec(level + 1);
			curr_sol.pop_back();
			depth--;
			maxd--;
			open++;
		}
		else if (i == 1 && clo)
		{
			depth--;
			if (depth < 0)
			{
				depth++;
				return;
			}
			clo--;
			curr_sol.push_back(temp);
			rec(level + 1);
			depth++;
			// maxd=max(maxd,depth);
			curr_sol.pop_back();
			clo++;
		}
	}
	return;
}

int main()

{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	open = n / 2;
	clo = n / 2;
	rec(0);
	return 0;
}