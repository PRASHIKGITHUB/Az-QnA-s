#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long

signed main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        set<int> s, ns;
        while (q--)
        {
            int t, x;
            cin >> t >> x;
            if (t == 1)
            {
                s.insert(x);
                ns.erase(x);
                if (!s.count(x + 1))
                {
                    ns.insert(x + 1);
                }
            }
            else
            {
                if (!s.count(x))
                {
                    cout << x << "\n";
                }
                else
                {
                    cout << *ns.lower_bound(x) << "\n";
                }
            }
        }
    }
    return 0;
}
/*
This solution uses two sets s and ns to maintain the values of 
x
i
 and 
x
i
+
1
 , respectively. When we perform an operation of type 1 x, we insert x into s. If 
x
+
1
 is not already in s, we also insert it into ns. If 
x
+
1
 is already in s, we remove it from ns. This is because if 
x
i
+
1
 is already in the set, we do not need to keep track of it separately, since we know that xi is present in the set.

When we perform an operation of type 2 x, we check if x is in s. If it is not, we return x as the smallest integer not present in the set that is greater than or equal to x. If x is in s, we use the lower_bound function on ns to find the smallest integer in ns that is greater than or equal to x, and return that as the answer.

The reason this solution works is because the values in s represent the integers that are present in the set, and the values in ns represent the integers that are not present in the set but have an immediate neighbor that is present in the set. This means that the smallest integer not present in the set that is greater than or equal to x will either be x itself (if x is not in the set), or the smallest value in ns that is greater than or equal to x (if x is in the set).

Time Complexity per test case: 
O
(
Q
log
Q
)
, because each operation takes 
O
(
log
Q
)
 time to perform (due to the use of sets and the lower_bound function).
*/