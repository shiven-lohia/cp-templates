vector<int> tin(n), tout(n), euler(n);
int time = 0;

function<void(int,int)> euler_tour = [&](int u, int p) {
    tin[u] = time;
    euler[time] = u; // or val[u]
    time++;
    
    for(auto v: adj[u]) {
        if(v==p) continue;
        euler_tour(v,u);
    }
    
    tout[u] = time;
};
// subtree of u = euler[tin[u]..tout[u])
// tin[u] ≤ tin[v] < tout[u] = u is ancestor of v

euler_tour(0,-1);