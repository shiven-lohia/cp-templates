// return lexographically minimum topo sort array
vector<int> topo_sort(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indeg(n), res;
    priority_queue<int, vector<int>, greater<int>> q;

    for (int u = 0; u < n; u++)
        for (int v : adj[u])
            indeg[v]++;

    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int u = q.top(); q.pop();
        res.push_back(u);
        for (int v : adj[u])
            if (--indeg[v] == 0)
                q.push(v);
    }

    if ((int)res.size() != n) return {};
    return res;
}
