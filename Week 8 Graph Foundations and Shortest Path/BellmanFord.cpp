#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}
struct edge{
    int u,v,w;
};
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    edge E[2 * m];  // For undirected graph, store 2*m edges
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        E[i].u = a;
        E[i].v = b;
        E[i].w = -c;

        // Add reverse edge for undirected graph
        E[i + m].u = b;
        E[i + m].v = a;
        E[i + m].w = -c;
    }

    ll dist[n + 1];
    for(int i = 1; i <= n; i++) {
        dist[i] = 1e18;
    }
    dist[1] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 2 * m; j++) {  // Iterate over both directions
            int u = E[j].u;
            int v = E[j].v;
            int w = E[j].w;
            dist[v] = min(dist[v], dist[u] + w);
        }
    }

    bool neg = false;
    for(int i = 0; i < 2 * m; i++) {
        int u = E[i].u;
        int v = E[i].v;
        int w = E[i].w;
        if(dist[v] > dist[u] + w) {
            neg = true;
            break;
        }
    }

    if(neg) cout << "-1\n";
    else {
        assert(dist[n] != 1e18);
        cout << -dist[n] << "\n";
    }
}
