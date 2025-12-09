function<void(int)> dfs = [&](int i) {
    visited[i] = true;

    for (auto next : adj[i]) {
        if (!visited[next]) dfs(next);
    }
};