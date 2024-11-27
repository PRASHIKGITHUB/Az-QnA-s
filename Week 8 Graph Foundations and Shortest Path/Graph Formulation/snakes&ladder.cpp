#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
using pp = pair<lli, lli>;

vector<vector<pair<int, int>>> g;
vector<int> dis;

void Dijkstra(int start) {
    deque<pair<int, int>> dq;
    dq.push_back({start, 0});
    dis[start] = 0;

    while (!dq.empty()) {
        auto x = dq.front();
        dq.pop_front();
        
        int u = x.first;  // current node
        int dist_u = x.second;  // current distance

        for (auto& nei : g[u]) {
            int v = nei.first;  // neighbor node
            int weight = nei.second;  // weight of the edge

            if (dis[v] > dist_u + weight) {
                dis[v] = dist_u + weight;

                if (weight == 0) {
                    dq.push_front({v, dis[v]});  // zero-weight edges
                } else {
                    dq.push_back({v, dis[v]});  // one-weight edges
                }
            }
        }
    }
}

void solve() {
    // Reset the graph and distance array for each test case
    g.assign(101, vector<pair<int, int>>());
    dis.assign(101, 1e9);

    // Mapping for ladders and snakes
    vector<int> go_to(101);
    for (int i = 1; i <= 100; i++) {
        go_to[i] = i;  // Initialize to self
    }

    int n, m;
    cin >> n;  // Number of ladders
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        go_to[a] = b;  // Ladder from a to b
    }

    cin >> m;  // Number of snakes
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        go_to[a] = b;  // Snake from a to b
    }

    // Add edges for possible dice rolls with cost of 1
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 6; j++) {
            int target = i + j;
            if (target <= 100) {
                g[i].emplace_back(go_to[target], 1);  // Go to target (considering ladders/snakes)
            }
        }
    }

    Dijkstra(1);  // Start Dijkstra from node 1
    
    // If `dis[100]` is still 1e9, it means node 100 is unreachable
    if (dis[100] == 1e9) {
        cout << -1 << endl;  // Impossible to reach cell 100
    } else {
        cout << dis[100] << endl;  // Minimum rolls to reach node 100
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
