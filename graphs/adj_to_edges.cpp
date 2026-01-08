vector<pair<ll, pair<int,int>>> adj_to_edges(const vector<vector<pair<int,ll>>>& adj) {
    int n = adj.size();
    vector<pair<ll, pair<int,int>>> edges;

    for (int u = 0; u < n; u++) {
        for (auto &[v, w] : adj[u]) {
            if (u < v) {
                edges.push_back({w, {u, v}});
            }
        }
    }
    return edges;
}

vector<vector<pair<int,ll>>> edges_to_adj(int n, const vector<pair<ll, pair<int,int>>>& edges) {
    vector<vector<pair<int,ll>>> adj(n);

    for (auto &e : edges) {
        ll w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    return adj;
}
