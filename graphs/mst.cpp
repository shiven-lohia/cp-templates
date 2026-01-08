//! import DSU first
// return mst sum
ll mst(int n, vector<pair<ll, pair<int,int>>>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    ll res = 0;
    int cnt = 0;

    for (auto &e : edges) {
        ll w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if (dsu.unite(u, v)) {
            res += w;
            cnt++;
        }
    }

    if (cnt != n - 1) return -1;
    return res;
}

//! import DSU first
// return edges of mst
vector<pair<ll, pair<int,int>>> mst(int n, vector<pair<ll, pair<int,int>>>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    vector<pair<ll, pair<int,int>>> res;

    for (auto &e : edges) {
        int u = e.second.first;
        int v = e.second.second;
        if (dsu.unite(u, v)) {
            res.push_back(e);
        }
    }

    if ((int)res.size() != n - 1) return {};
    return res;
}
