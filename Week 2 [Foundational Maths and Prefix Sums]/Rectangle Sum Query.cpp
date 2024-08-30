#include <bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, q;
  cin >> n >> m >> q;
  long long arr[n + 1][m + 1];
  memset(arr, 0, sizeof(arr));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
      arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
    }
  }
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long ans =
        arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
    ans %= mod;
    if (ans < 0) ans += mod;
    cout << ans << '\n';
  }
  return 0;
}