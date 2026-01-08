const int MAXN = 200000;

vector<int> tin(MAXN), depth(MAXN), euler;
int time = 0;

void euler_tour(int u, int p, const vector<vector<int>>& adj) {
    tin[u] = time;
    euler.pb(u);
    time++;

    for(auto v: adj[u]) {
        if(v==p) continue;
        depth[v] = depth[u] + 1;
        euler_tour(v,u,adj);
        euler.pb(u);
        time++;
    }
};

vector<int> seg(4 * MAXN);

int merge_idx(int i, int j) {
    if (i == -1) return j;
    if (j == -1) return i;
    return (depth[euler[i]] < depth[euler[j]] ? i : j);
}

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = l;
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    seg[node] = merge_idx(seg[node * 2], seg[node * 2 + 1]);
}

int query(int node, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return -1;
    if (l >= ql && r <= qr) return seg[node];
    int mid = (l + r) / 2;
    return merge_idx(
        query(node * 2, l, mid, ql, qr),
        query(node * 2 + 1, mid + 1, r, ql, qr)
    );
}

int lca(int u, int v) {
    int l = tin[u];
    int r = tin[v];
    if (l > r) swap(l, r);
    int idx = query(1, 0, (int)euler.size() - 1, l, r);
    return euler[idx];
}


// time = 0;
// euler.clear();
// depth[0] = 0;
// euler_tour(0,-1,adj);

// build(1,0,(int)euler.size()-1);
// int lca_idx = lca(u,v); // 0 based