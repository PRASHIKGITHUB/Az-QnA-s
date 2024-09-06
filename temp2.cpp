#include <bits/stdc++.h>
using lli = long long int;
using namespace std;
class Solution
{
public:
  vector<lli> prefix;
  vector<int> right;
  vector<int> left;
  int maxSumMinProduct(vector<int> &nums)
  {
    int n;
    n = nums.size();
    stack<int> s;
    prefix.assign(n + 1, 0);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
      prefix[i] = prefix[i - 1] + nums[i];
    }
    right.resize(n);
    left.resize(n);
    for (int i = 0; i < n; i++)
    {
      while (!s.empty() && nums[s.top()] >= nums[i])
      {
        s.pop();
      }
      if (s.empty())
      {
        left[i] = -1;
      }
      else
      {
        left[i] = s.top();
      }
      s.push(i);
    }

    while (!s.empty())
    {
      s.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
      while (!s.empty() && nums[s.top()] >= nums[i])
      {
        s.pop();
      }
      if (s.empty())
      {
        right[i] = n;
      }
      else
      {
        right[i] = s.top();
      }
      s.push(i);
    }

    lli ans = 0;
    lli Subsum = 0;
    for (int i = 0; i < n; i++)
    {
      if (right[i] == n && left[i] == -1)
      {
        Subsum = prefix[n - 1];
      }
      else if (right[i] == n)
      {
        Subsum = prefix[n - 1] - prefix[left[i]];
      }
      else if (left[i] == -1)
      {
        Subsum = prefix[right[i] - 1];
      }
      else
      {
        Subsum = prefix[right[i] - 1] - prefix[left[i]];
      }
      ans = max(Subsum * nums[i], ans);
    }
    lli m = 1e9 + 1;
    return ans % m;
  }
};

